<?php
/**
 * @file
 * svendborg_search.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function svendborg_search_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'svendborg_elastic_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_svendborg_public';
  $view->human_name = 'Svendborg Elastic Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Søg';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Søg';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Gendan';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér efter';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Faldende';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Search: Spellcheck */
  $handler->display->display_options['header']['search_api_spellcheck']['id'] = 'search_api_spellcheck';
  $handler->display->display_options['header']['search_api_spellcheck']['table'] = 'search_api_index_svendborg_public';
  $handler->display->display_options['header']['search_api_spellcheck']['field'] = 'search_api_spellcheck';
  $handler->display->display_options['header']['search_api_spellcheck']['empty'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<ul>
<li>Kontrollér at stavningen er korrekt eller prøv at fjerne filtre.</li>
<li>Fjern anførselstegn omkring udtryk for at søge efter hvert ord individuelt: <em>"blue drop"</em> giver færre resultater end <em>blue drop</em>.</li>
<li>Du kan forlange eller ekskludere termer med  + og -: <em>big +blue drop</em> kræver at <em>blue</em> findes, mens <em>big blue -drop</em> ekskluderer resultater som indeholder <em>drop</em>.</li>
</ul>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Node: Title (indexed) */
  $handler->display->display_options['fields']['node_title']['id'] = 'node_title';
  $handler->display->display_options['fields']['node_title']['table'] = 'search_api_index_svendborg_public';
  $handler->display->display_options['fields']['node_title']['field'] = 'node_title';
  $handler->display->display_options['fields']['node_title']['label'] = '';
  $handler->display->display_options['fields']['node_title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['node_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['node_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['node_title']['link_to_entity'] = 1;
  /* Field: Taxonomy term: Name (indexed) */
  $handler->display->display_options['fields']['taxonomy_term_name']['id'] = 'taxonomy_term_name';
  $handler->display->display_options['fields']['taxonomy_term_name']['table'] = 'search_api_index_svendborg_public';
  $handler->display->display_options['fields']['taxonomy_term_name']['field'] = 'taxonomy_term_name';
  $handler->display->display_options['fields']['taxonomy_term_name']['label'] = '';
  $handler->display->display_options['fields']['taxonomy_term_name']['element_type'] = 'h3';
  $handler->display->display_options['fields']['taxonomy_term_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['taxonomy_term_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['taxonomy_term_name']['link_to_entity'] = 1;
  /* Field: Node » File ref: The file. (indexed) */
  $handler->display->display_options['fields']['node_field_os2search_file_ref_file']['id'] = 'node_field_os2search_file_ref_file';
  $handler->display->display_options['fields']['node_field_os2search_file_ref_file']['table'] = 'search_api_index_svendborg_public';
  $handler->display->display_options['fields']['node_field_os2search_file_ref_file']['field'] = 'node_field_os2search_file_ref_file';
  $handler->display->display_options['fields']['node_field_os2search_file_ref_file']['label'] = '';
  $handler->display->display_options['fields']['node_field_os2search_file_ref_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['node_field_os2search_file_ref_file']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['node_field_os2search_file_ref_file']['display'] = 'view';
  $handler->display->display_options['fields']['node_field_os2search_file_ref_file']['view_mode'] = 'search_result';
  $handler->display->display_options['fields']['node_field_os2search_file_ref_file']['bypass_access'] = 0;
  /* Field: Search: Excerpt */
  $handler->display->display_options['fields']['search_api_excerpt']['id'] = 'search_api_excerpt';
  $handler->display->display_options['fields']['search_api_excerpt']['table'] = 'search_api_index_svendborg_public';
  $handler->display->display_options['fields']['search_api_excerpt']['field'] = 'search_api_excerpt';
  $handler->display->display_options['fields']['search_api_excerpt']['label'] = '';
  $handler->display->display_options['fields']['search_api_excerpt']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['search_api_excerpt']['alter']['preserve_tags'] = '<strong> </strong>';
  $handler->display->display_options['fields']['search_api_excerpt']['element_type'] = 'p';
  $handler->display->display_options['fields']['search_api_excerpt']['element_class'] = 'indhold';
  $handler->display->display_options['fields']['search_api_excerpt']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['search_api_excerpt']['element_wrapper_class'] = 'search-snippet-info';
  $handler->display->display_options['fields']['search_api_excerpt']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['search_api_excerpt']['link_to_entity'] = 0;
  /* Field: Node: URL (indexed) */
  $handler->display->display_options['fields']['node_url']['id'] = 'node_url';
  $handler->display->display_options['fields']['node_url']['table'] = 'search_api_index_svendborg_public';
  $handler->display->display_options['fields']['node_url']['field'] = 'node_url';
  $handler->display->display_options['fields']['node_url']['label'] = '';
  $handler->display->display_options['fields']['node_url']['element_type'] = 'p';
  $handler->display->display_options['fields']['node_url']['element_class'] = 'url';
  $handler->display->display_options['fields']['node_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['node_url']['element_wrapper_class'] = 'search-snippet-info';
  $handler->display->display_options['fields']['node_url']['link_to_entity'] = 1;
  /* Field: Taxonomy term: URL (indexed) */
  $handler->display->display_options['fields']['taxonomy_term_url']['id'] = 'taxonomy_term_url';
  $handler->display->display_options['fields']['taxonomy_term_url']['table'] = 'search_api_index_svendborg_public';
  $handler->display->display_options['fields']['taxonomy_term_url']['field'] = 'taxonomy_term_url';
  $handler->display->display_options['fields']['taxonomy_term_url']['label'] = '';
  $handler->display->display_options['fields']['taxonomy_term_url']['element_type'] = 'p';
  $handler->display->display_options['fields']['taxonomy_term_url']['element_class'] = 'url';
  $handler->display->display_options['fields']['taxonomy_term_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['taxonomy_term_url']['element_wrapper_class'] = 'search-snippet-info';
  $handler->display->display_options['fields']['taxonomy_term_url']['link_to_entity'] = 1;
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_svendborg_public';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['order'] = 'DESC';
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_svendborg_public';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    4 => 0,
    7 => 0,
    3 => 0,
    5 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    15 => 0,
    13 => 0,
    14 => 0,
    16 => 0,
    17 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'search';

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_menu');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'webform_submission';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;

  /* Display: Content pane 2 */
  $handler = $view->new_display('panel_pane', 'Content pane 2', 'panel_pane_frontpage');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'webform_submission';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $translatables['svendborg_elastic_search'] = array(
    t('Master'),
    t('Søg'),
    t('more'),
    t('Gendan'),
    t('Sortér efter'),
    t('Stigende'),
    t('Faldende'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('<ul>
<li>Kontrollér at stavningen er korrekt eller prøv at fjerne filtre.</li>
<li>Fjern anførselstegn omkring udtryk for at søge efter hvert ord individuelt: <em>"blue drop"</em> giver færre resultater end <em>blue drop</em>.</li>
<li>Du kan forlange eller ekskludere termer med  + og -: <em>big +blue drop</em> kræver at <em>blue</em> findes, mens <em>big blue -drop</em> ekskluderer resultater som indeholder <em>drop</em>.</li>
</ul>'),
    t('Page'),
    t('Content pane'),
    t('View panes'),
    t('Content pane 2'),
  );
  $export['svendborg_elastic_search'] = $view;

  return $export;
}
