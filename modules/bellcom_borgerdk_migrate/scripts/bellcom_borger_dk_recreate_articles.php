<?php

/**
 * @author: Stanislav Kutasevits, stan@bellcom.dk
 *
 * This script will loop through all of the committeers taxonomy terms and remove the duplicates in field: field_os2web_meetings_com_subid
 *
 * Example,
 *
 * term before running script:
 * Afsluttede Børnefagligt Forum, field_os2web_meetings_com_subid: [1,2,50,2,1]
 *
 * term after running script:
 * Afsluttede Børnefagligt Forum, field_os2web_meetings_com_subid: [1,2,50]
 **/
$time_start = microtime(TRUE);
print('==========================' . PHP_EOL);
print('Started bellcom_borger_dk_recreate_articles.php.php' . PHP_EOL);

$query = new EntityFieldQuery();
$query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'os2web_borger_dk_article');
//->propertyCondition('status', NODE_PUBLISHED);
//->range(0, 10);
$result = $query->execute();

if (isset($result['node'])) {
  $nids = array_keys($result['node']);
  $old_articles = entity_load('node', $nids);
  foreach ($old_articles as $old_article) {
//    if ($old_article->nid == 35004) {
    print('==========================' . PHP_EOL);
    print('Copying ' . $old_article->title . ' [nid: ' . $old_article->nid . ']' . PHP_EOL);

    if ($existing_node = bellcom_borger_dk_get_corresponding_new_article($old_article)) {
      print('Skipping. Node already exists [nid: ' . $existing_node->nid . ']' . PHP_EOL);
      continue;
    }

    print('No node found, creating new node...' . PHP_EOL);

    if ($parent_node = bellcom_borgerdk_migrate_need_replace_parent_menu($old_article)) {
      if (!$corresponding_new_article = bellcom_borger_dk_get_corresponding_new_article($parent_node)) {
        print('Skipping. This node\'s menu parent is another Borger.dk article, which is not created yet. Try running script again until no such messages are present' . PHP_EOL);
        continue;
      }
    }

    //create a node
    $node = new stdClass();
    $node->title = $old_article->title;
    $node->type = 'borger_dk_article';
    node_object_prepare($node); // Sets some defaults. Invokes hook_prepare() and hook_node_prepare().
    $node->language = $old_article->language; // Or e.g. 'en' if locale is enabled
    $node->status = $old_article->status;
    $node->uid = $old_article->uid;

    $node = node_submit($node); // Prepare node for saving

    //filling the fields
    $node->created = $old_article->created;
    $node->field_borger_dk_image = $old_article->field_os2web_borger_dk_image;
    $node->field_borger_dk_shortlist = $old_article->field_os2web_borger_dk_shortlist;
    $node->field_os2web_base_field_contact = $old_article->field_os2web_base_field_contact;
    $node->field_os2web_base_field_related = $old_article->field_os2web_base_field_related;
    $node->field_os2web_base_field_spotbox = $old_article->field_os2web_base_field_spotbox;
    $node->field_borger_dk_kle = $old_article->field_os2web_borger_dk_kle;
    $node->field_svendborg_hide_sidebar = $old_article->field_svendborg_hide_sidebar;

    //filling borger.dk - article fields
    $old_article_url = $old_article->field_os2web_borger_dk_borgerurl['und'][0]['value'];
    $old_article_url = parse_url($old_article_url);
    $old_article_url = $old_article_url['scheme'] . '://' . $old_article_url['host'] . $old_article_url['path'];
    $entities = borgerdk_article_load_multiple(FALSE, array('articleUrl' => $old_article_url));
    $selected_article_entity = reset($entities);
    if (!$selected_article_entity) {
      print('Skipping. Borger.dk article with this URL is not found: [url: ' . $old_article->field_os2web_borger_dk_borgerurl['und'][0]['value'] . ']' . PHP_EOL);
      continue;
    }

    $node->field_borger_dk_article_ref['und'][0]['borgerdk_article_entity_id'] = $selected_article_entity->entity_id;

    //filling borger.dk - microarticle fields
    $selected_microarticles = array();
    $available_microarticles = borgerdk_microarticle_load_multiple_sorted(FALSE, array('article_id' => $selected_article_entity->entity_id));
    $i = 0;
    foreach ($available_microarticles as $ma) {
      $i++; //start from index 1

      //don't add in case the key exists and it's 0
      if (is_array($old_article->os2web_borger_dk_microarticle['field_microarticle_settings'])
        && array_key_exists($i, $old_article->os2web_borger_dk_microarticle['field_microarticle_settings'])
        && $old_article->os2web_borger_dk_microarticle['field_microarticle_settings'][$i] === 0
      ) {
        continue;
      }
      $selected_microarticles[] = $ma->entity_id;
    }
    $node->field_borger_dk_article_ref['und'][0]['borgerdk_microarticle_entity_ids'] = json_encode($selected_microarticles);

    //filling borger.dk - selfservice fields
    $selected_selfservices = borgerdk_selfservice_load_multiple_sorted(FALSE, array(
      'article_id' => $selected_article_entity->entity_id,
      'microarticle_id' => NULL
    ));
    if (is_array($old_article->field_os2web_base_field_selfserv['und'])) {
      foreach ($old_article->field_os2web_base_field_selfserv['und'] as $field_serlfservice) {
        $ss = bellcom_borgerdk_migrate_get_selfservice_from_selvbetjening(node_load($field_serlfservice['nid']), $selected_article_entity);
        $selected_selfservices[$ss->entity_id] = $ss;
      }
    }

    $node->field_borger_dk_article_ref['und'][0]['borgerdk_selfservice_entity_ids'] = json_encode(array_keys($selected_selfservices));

    //saving node
    $node->path['pathauto'] = 1;
    node_save($node);

    //updating menu
    $menu_link = _bellcom_borger_dk_get_menu_link($old_article);
    if ($menu_link) {
      $menu_link['mlid'] = NULL;
      $menu_link['link_path'] = 'node/' . $node->nid;

      //updating the parent if needed
      if ($parent_node = bellcom_borgerdk_migrate_need_replace_parent_menu($old_article)) {
        if ($corresponding_new_article = bellcom_borger_dk_get_corresponding_new_article($parent_node)) {
          //getting parent menu link
          $menu_link['plid'] = _bellcom_borger_dk_get_menu_link($corresponding_new_article)['mlid'];
        }
      }
      menu_link_save($menu_link);
    }

    print('New borger.dk article: ' . $node->title . ' [nid: ' . $node->nid . ']' . PHP_EOL);
  }
//  }
}

print('==========================' . PHP_EOL);
print('Finished bellcom_borger_dk_recreate_articles' . PHP_EOL);
print('Total execution time: ' . (microtime(TRUE) - $time_start) . ' seconds' . PHP_EOL);
print('==========================' . PHP_EOL);
