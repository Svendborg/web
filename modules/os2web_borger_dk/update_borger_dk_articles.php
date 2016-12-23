<?php

$result = db_query('SELECT nid, external_id FROM {os2web_borger_dk_article} WHERE external_status > 0');
foreach ($result as $item) {
  // We also build an index of "external_id" => "nid".
  if (!in_array($item->external_id, array(157, 552, 585))) {
    $article_id2nid[$item->external_id] = $item->nid;
    $article_id_list[] = $item->external_id;
  }
}

$articles = array();
$wsdl = variable_get('os2web_borger_dk_webservice', 'https://www.borger.dk/_vti_bin/borger/ArticleExport.svc?wsdl');
$articles = _os2web_borger_dk_GetArticlesByIDs($article_id_list, NULL, $wsdl);
error_log(__FILE__ . ' : ' . __LINE__ . ' : $articles : ' .  print_r($articles, 1));

foreach ($articles as $article) {
  $external_id = $article['external_id'];
  // We only update articles we already know the nid for (just in case).
  if (!empty($article_id2nid[$external_id])) {
    $nid = $article_id2nid[$external_id];

    // First we check if the article is an error-array.
    if (empty($article['no_updates'])) {
      // We only update articles that does not contain an error.
      if (empty($article['Exceptions']) && empty($article['error'])) {
        _os2web_borger_dk_update_node_content($nid, $article);
      }
      if (!empty($article['Exceptions'])) {
        $any_webservice_errors = TRUE;
      }
    }
    else {
      // Articles with errors might have been deleted, and we must handle it.
      // But if "Titles autocomplete" is active, then it will be handled by
      // the titles-auto-update in the cron-function:
      // _os2web_borger_dk_titles_cronbatch().
      if (!$titles_autocomplete) {
        // Try to get this one article, to see if it still exists.
        $item = _os2web_borger_dk_GetArticleByID($external_id, $wsdl);
        if (!empty($item['error']) && $item['error'] == 1) {
          if (!empty($item['error_type']) && ($item['error_type'] == 'not_found')) {
            // $deleted_items[$nid] = $item;
            $deleted_ids[] = $nid;
          }
          else {
            $error_items[$nid] = $item;
          }
        }
      }
    }
  }
}
