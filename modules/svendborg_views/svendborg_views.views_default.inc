<?php
/**
 * @file
 * svendborg_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function svendborg_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'culture_calendar';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'culture calendar';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Kulturkalender';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mere';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Udfør';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Gendan';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér efter';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Faldende';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Antal elementer';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Forskydning';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« første';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ forrige';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'næste ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'sidste »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Felt: Indhold: Kulturkalender Dato */
  $handler->display->display_options['fields']['field_kulturkalender_dato']['id'] = 'field_kulturkalender_dato';
  $handler->display->display_options['fields']['field_kulturkalender_dato']['table'] = 'field_data_field_kulturkalender_dato';
  $handler->display->display_options['fields']['field_kulturkalender_dato']['field'] = 'field_kulturkalender_dato';
  $handler->display->display_options['fields']['field_kulturkalender_dato']['label'] = '';
  $handler->display->display_options['fields']['field_kulturkalender_dato']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_kulturkalender_dato']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_kulturkalender_dato']['settings'] = array(
    'format_type' => 'tab_date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Felt: Indhold: Kulturkalender Link */
  $handler->display->display_options['fields']['field_kulturkalender_link']['id'] = 'field_kulturkalender_link';
  $handler->display->display_options['fields']['field_kulturkalender_link']['table'] = 'field_data_field_kulturkalender_link';
  $handler->display->display_options['fields']['field_kulturkalender_link']['field'] = 'field_kulturkalender_link';
  $handler->display->display_options['fields']['field_kulturkalender_link']['label'] = '';
  $handler->display->display_options['fields']['field_kulturkalender_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_kulturkalender_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_kulturkalender_link']['empty'] = 'http://www.svendborgkultur.dk/';
  $handler->display->display_options['fields']['field_kulturkalender_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_kulturkalender_link']['type'] = 'link_title_plain';
  /* Felt: Indhold: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<a href="[field_kulturkalender_link]">[title]</a>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Felt: Indhold: Indhold */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '50';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Felt: Global: Tilpasset tekst */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="col-md-12 col-sm-12 col-xs-12 quicktabs-nyheder-row">
   <div class="col-md-12 quicktabs-row-border">
     <div>[field_kulturkalender_dato]</div>
     <h4>[title]</h4>
      [body]
  </div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sorteringskriterie: Indhold: Oprettelsesdato */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filterkriterie: Indhold: Udgivet */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterie: Indhold: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'kulturkalender' => 'kulturkalender',
  );
  /* Filterkriterie: Indhold: Kulturkalender Kategori ID (field_kulturkalender_kategori_id) */
  $handler->display->display_options['filters']['field_kulturkalender_kategori_id_value']['id'] = 'field_kulturkalender_kategori_id_value';
  $handler->display->display_options['filters']['field_kulturkalender_kategori_id_value']['table'] = 'field_data_field_kulturkalender_kategori_id';
  $handler->display->display_options['filters']['field_kulturkalender_kategori_id_value']['field'] = 'field_kulturkalender_kategori_id_value';
  $handler->display->display_options['filters']['field_kulturkalender_kategori_id_value']['operator'] = '!=';
  $handler->display->display_options['filters']['field_kulturkalender_kategori_id_value']['value']['value'] = '3';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Indhold: Kulturkalender Dato */
  $handler->display->display_options['fields']['field_kulturkalender_dato']['id'] = 'field_kulturkalender_dato';
  $handler->display->display_options['fields']['field_kulturkalender_dato']['table'] = 'field_data_field_kulturkalender_dato';
  $handler->display->display_options['fields']['field_kulturkalender_dato']['field'] = 'field_kulturkalender_dato';
  $handler->display->display_options['fields']['field_kulturkalender_dato']['label'] = '';
  $handler->display->display_options['fields']['field_kulturkalender_dato']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_kulturkalender_dato']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_kulturkalender_dato']['settings'] = array(
    'format_type' => 'day',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Felt: Indhold: Kulturkalender Dato */
  $handler->display->display_options['fields']['field_kulturkalender_dato_1']['id'] = 'field_kulturkalender_dato_1';
  $handler->display->display_options['fields']['field_kulturkalender_dato_1']['table'] = 'field_data_field_kulturkalender_dato';
  $handler->display->display_options['fields']['field_kulturkalender_dato_1']['field'] = 'field_kulturkalender_dato';
  $handler->display->display_options['fields']['field_kulturkalender_dato_1']['label'] = '';
  $handler->display->display_options['fields']['field_kulturkalender_dato_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_kulturkalender_dato_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_kulturkalender_dato_1']['settings'] = array(
    'format_type' => 'month',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Felt: Indhold: Kulturkalender Link */
  $handler->display->display_options['fields']['field_kulturkalender_link']['id'] = 'field_kulturkalender_link';
  $handler->display->display_options['fields']['field_kulturkalender_link']['table'] = 'field_data_field_kulturkalender_link';
  $handler->display->display_options['fields']['field_kulturkalender_link']['field'] = 'field_kulturkalender_link';
  $handler->display->display_options['fields']['field_kulturkalender_link']['label'] = '';
  $handler->display->display_options['fields']['field_kulturkalender_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_kulturkalender_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_kulturkalender_link']['empty'] = 'http://www.svendborgkultur.dk/';
  $handler->display->display_options['fields']['field_kulturkalender_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_kulturkalender_link']['type'] = 'link_title_plain';
  /* Felt: Indhold: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<a href="[field_kulturkalender_link]">[title]</a>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Felt: Indhold: Indhold */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '800';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Felt: Global: Tilpasset tekst */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="front-s-news-item front-s-news-item-">
<div class="front-s-news-item-text clearfix">
                <div class="col-md-2 col-sm-2 col-xs-2">
                     <div class="news-text-date">
                       <span class="news-date-day">[field_kulturkalender_dato].</span>
                       <span class="news-date-month">[field_kulturkalender_dato_1]</span>
                     </div>
                 </div>
                <div class="col-md-10 col-sm-10 col-xs-10">
                      <div>[title]</div>
                      <div>
                          <p>[body]</p>
                      </div>
                </div>
            </div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sorteringskriterie: Indhold: Kulturkalender Dato -  startdato (field_kulturkalender_dato) */
  $handler->display->display_options['sorts']['field_kulturkalender_dato_value']['id'] = 'field_kulturkalender_dato_value';
  $handler->display->display_options['sorts']['field_kulturkalender_dato_value']['table'] = 'field_data_field_kulturkalender_dato';
  $handler->display->display_options['sorts']['field_kulturkalender_dato_value']['field'] = 'field_kulturkalender_dato_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterie: Indhold: Udgivet */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterie: Indhold: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'kulturkalender' => 'kulturkalender',
  );
  /* Filterkriterie: Indhold: Kulturkalender Kategori ID (field_kulturkalender_kategori_id) */
  $handler->display->display_options['filters']['field_kulturkalender_kategori_id_value']['id'] = 'field_kulturkalender_kategori_id_value';
  $handler->display->display_options['filters']['field_kulturkalender_kategori_id_value']['table'] = 'field_data_field_kulturkalender_kategori_id';
  $handler->display->display_options['filters']['field_kulturkalender_kategori_id_value']['field'] = 'field_kulturkalender_kategori_id_value';
  $handler->display->display_options['filters']['field_kulturkalender_kategori_id_value']['operator'] = '!=';
  $handler->display->display_options['filters']['field_kulturkalender_kategori_id_value']['value']['value'] = '3';
  /* Filterkriterie: Indhold: Kulturkalender Dato -  startdato (field_kulturkalender_dato) */
  $handler->display->display_options['filters']['field_kulturkalender_dato_value']['id'] = 'field_kulturkalender_dato_value';
  $handler->display->display_options['filters']['field_kulturkalender_dato_value']['table'] = 'field_data_field_kulturkalender_dato';
  $handler->display->display_options['filters']['field_kulturkalender_dato_value']['field'] = 'field_kulturkalender_dato_value';
  $handler->display->display_options['filters']['field_kulturkalender_dato_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_kulturkalender_dato_value']['default_date'] = 'now';
  $handler->display->display_options['path'] = 'culture-calendar';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'culture calendar';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'Alle kulturkalender';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Sidefod: Global: Tekstområde */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a class="btn btn-primary" href="http://www.svendborgkultur.dk/">Se kulturkalender</a>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sorteringskriterie: Indhold: Kulturkalender Dato -  startdato (field_kulturkalender_dato) */
  $handler->display->display_options['sorts']['field_kulturkalender_dato_value']['id'] = 'field_kulturkalender_dato_value';
  $handler->display->display_options['sorts']['field_kulturkalender_dato_value']['table'] = 'field_data_field_kulturkalender_dato';
  $handler->display->display_options['sorts']['field_kulturkalender_dato_value']['field'] = 'field_kulturkalender_dato_value';
  /* Sorteringskriterie: Indhold: Oprettelsesdato */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterie: Indhold: Udgivet */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterie: Indhold: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'kulturkalender' => 'kulturkalender',
  );
  /* Filterkriterie: Indhold: Kulturkalender Kategori ID (field_kulturkalender_kategori_id) */
  $handler->display->display_options['filters']['field_kulturkalender_kategori_id_value']['id'] = 'field_kulturkalender_kategori_id_value';
  $handler->display->display_options['filters']['field_kulturkalender_kategori_id_value']['table'] = 'field_data_field_kulturkalender_kategori_id';
  $handler->display->display_options['filters']['field_kulturkalender_kategori_id_value']['field'] = 'field_kulturkalender_kategori_id_value';
  $handler->display->display_options['filters']['field_kulturkalender_kategori_id_value']['operator'] = '!=';
  $handler->display->display_options['filters']['field_kulturkalender_kategori_id_value']['value']['value'] = '3';
  /* Filterkriterie: Indhold: Kulturkalender Dato -  startdato (field_kulturkalender_dato) */
  $handler->display->display_options['filters']['field_kulturkalender_dato_value']['id'] = 'field_kulturkalender_dato_value';
  $handler->display->display_options['filters']['field_kulturkalender_dato_value']['table'] = 'field_data_field_kulturkalender_dato';
  $handler->display->display_options['filters']['field_kulturkalender_dato_value']['field'] = 'field_kulturkalender_dato_value';
  $handler->display->display_options['filters']['field_kulturkalender_dato_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_kulturkalender_dato_value']['default_date'] = 'now';
  $translatables['culture_calendar'] = array(
    t('Master'),
    t('Kulturkalender'),
    t('mere'),
    t('Udfør'),
    t('Gendan'),
    t('Sortér efter'),
    t('Stigende'),
    t('Faldende'),
    t('Antal elementer'),
    t('- Alle -'),
    t('Forskydning'),
    t('« første'),
    t('‹ forrige'),
    t('næste ›'),
    t('sidste »'),
    t('http://www.svendborgkultur.dk/'),
    t('<a href="[field_kulturkalender_link]">[title]</a>'),
    t('<div class="col-md-12 col-sm-12 col-xs-12 quicktabs-nyheder-row">
   <div class="col-md-12 quicktabs-row-border">
     <div>[field_kulturkalender_dato]</div>
     <h4>[title]</h4>
      [body]
  </div>
</div>'),
    t('Page'),
    t('<div class="front-s-news-item front-s-news-item-">
<div class="front-s-news-item-text clearfix">
                <div class="col-md-2 col-sm-2 col-xs-2">
                     <div class="news-text-date">
                       <span class="news-date-day">[field_kulturkalender_dato].</span>
                       <span class="news-date-month">[field_kulturkalender_dato_1]</span>
                     </div>
                 </div>
                <div class="col-md-10 col-sm-10 col-xs-10">
                      <div>[title]</div>
                      <div>
                          <p>[body]</p>
                      </div>
                </div>
            </div>
</div>'),
    t('Block'),
    t('culture calendar'),
    t('Alle kulturkalender'),
    t('<a class="btn btn-primary" href="http://www.svendborgkultur.dk/">Se kulturkalender</a>'),
  );
  $export['culture_calendar'] = $view;

  $view = new view();
  $view->name = 'forfatters_indhold';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Forfatters indhold';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Forfatters indhold';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mere';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Udfør';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Gendan';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér efter';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Faldende';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Antal elementer';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Forskydning';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« første';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ forrige';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'næste ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'sidste »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Forbindelse: Indhold: Forfatter */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Felt: Indhold: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Felt: Indhold: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Felt: Indhold: Opdateringsdato */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Felt: Indhold: Oprettelsesdato */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Oprettet';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Felt: Bruger: Navn */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  /* Sorteringskriterie: Indhold: Opdateringsdato */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Kontekstuelt filter: Indhold: Forfatter uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['uid']['validate_options']['type'] = 'either';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'forfatters-indhold';
  $handler->display->display_options['menu']['title'] = 'Indhold';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Blok */
  $handler = $view->new_display('block', 'Blok', 'block_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'type' => 'type',
    'changed' => 'changed',
    'created' => 'created',
    'name' => 'name',
    'publishcontent' => 'publishcontent',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'publishcontent' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Masse-handlinger: Indhold */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Vælg';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::balk_custom_node_assign_term_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::balk_custom_node_empty_lead_image_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_assign_owner_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::pathauto_node_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_promote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Felt: Indhold: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Felt: Indhold: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Felt: Indhold: Opdateringsdato */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Felt: Indhold: Oprettelsesdato */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Oprettet';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Felt: Bruger: Navn */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  /* Felt: Indhold: Publish link */
  $handler->display->display_options['fields']['publishcontent']['id'] = 'publishcontent';
  $handler->display->display_options['fields']['publishcontent']['table'] = 'node';
  $handler->display->display_options['fields']['publishcontent']['field'] = 'publishcontent';
  $handler->display->display_options['fields']['publishcontent']['label'] = 'Udgiv';
  $translatables['forfatters_indhold'] = array(
    t('Master'),
    t('Forfatters indhold'),
    t('mere'),
    t('Udfør'),
    t('Gendan'),
    t('Sortér efter'),
    t('Stigende'),
    t('Faldende'),
    t('Antal elementer'),
    t('- Alle -'),
    t('Forskydning'),
    t('« første'),
    t('‹ forrige'),
    t('næste ›'),
    t('sidste »'),
    t('forfatter'),
    t('Type'),
    t('Opdateringsdato'),
    t('Oprettet'),
    t('Navn'),
    t('Alle'),
    t('Page'),
    t('Blok'),
    t('Vælg'),
    t('- Vælg en handling -'),
    t('Udgiv'),
  );
  $export['forfatters_indhold'] = $view;

  $view = new view();
  $view->name = 'news_filter';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'News filter';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Filtre i kategorier';
  $handler->display->display_options['css_class'] = 'col-md-12 col-sm-12 col-xs-12';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mere';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Udfør';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Gendan';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér efter';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Faldende';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Overskrift: Global: Tekstområde */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="col-md-6 col-sm-12 col-xs-12">
<div class="btn btn-blacknblue filter-link col-md-12 col-sm-12 col-xs-12" id="filter-all" data-filter="all">Alle</div>
</div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Felt: Ord i ordforråd: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Felt: Ord i ordforråd: Navn */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['max_length'] = '20';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['name']['element_type'] = '0';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  /* Felt: Global: Tilpasset tekst */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="col-md-6 col-sm-12 col-xs-12">
<div class="btn btn-blacknblue filter-link col-md-12 col-sm-12 col-xs-12" id="filter-[tid]" data-filter="[tid]">[name]</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  /* Filterkriterie: Ordforråd: Internt navn */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'os2web_base_tax_site_structure' => 'os2web_base_tax_site_structure',
  );
  $handler->display->display_options['filters']['machine_name']['group'] = 1;
  /* Filterkriterie: Ord i ordforråd: Navn */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['value'] = 'Borger';
  $handler->display->display_options['filters']['name']['group'] = 2;
  /* Filterkriterie: Ord i ordforråd: Navn */
  $handler->display->display_options['filters']['name_1']['id'] = 'name_1';
  $handler->display->display_options['filters']['name_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name_1']['field'] = 'name';
  $handler->display->display_options['filters']['name_1']['value'] = 'Erhverv';
  $handler->display->display_options['filters']['name_1']['group'] = 2;
  /* Filterkriterie: Ord i ordforråd: Navn */
  $handler->display->display_options['filters']['name_2']['id'] = 'name_2';
  $handler->display->display_options['filters']['name_2']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name_2']['field'] = 'name';
  $handler->display->display_options['filters']['name_2']['value'] = 'Politik';
  $handler->display->display_options['filters']['name_2']['group'] = 2;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Ord i ordforråd: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Felt: Ord i ordforråd: Navn */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['max_length'] = '20';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['name']['element_type'] = '0';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  /* Felt: Global: Tilpasset tekst */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="col-md-6 col-sm-12 col-xs-12">
<div class="btn btn-blacknblue filter-link col-md-12 col-sm-12 col-xs-12" id="filter-[tid]" data-filter="[tid]">[name]</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $translatables['news_filter'] = array(
    t('Master'),
    t('Filtre i kategorier'),
    t('mere'),
    t('Udfør'),
    t('Gendan'),
    t('Sortér efter'),
    t('Stigende'),
    t('Faldende'),
    t('<div class="col-md-6 col-sm-12 col-xs-12">
<div class="btn btn-blacknblue filter-link col-md-12 col-sm-12 col-xs-12" id="filter-all" data-filter="all">Alle</div>
</div>'),
    t('.'),
    t('<div class="col-md-6 col-sm-12 col-xs-12">
<div class="btn btn-blacknblue filter-link col-md-12 col-sm-12 col-xs-12" id="filter-[tid]" data-filter="[tid]">[name]</div>
</div>'),
    t('Block'),
    t('Content pane'),
    t('View panes'),
  );
  $export['news_filter'] = $view;

  $view = new view();
  $view->name = 'pressemeddelelser';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Pressemeddelelser';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Pressemeddelelser';
  $handler->display->display_options['css_class'] = 'bg-white';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mere';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Udfør';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Gendan';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér efter';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Faldende';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Antal elementer';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Forskydning';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« første';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ forrige';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'næste ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'sidste »';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Felt: Indhold: Oprettelsesdato */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Felt: Indhold: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sorteringskriterie: Indhold: Oprettelsesdato */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filterkriterie: Indhold: Udgivet */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterie: Indhold: Forfrem til (field_os2web_base_field_promote) */
  $handler->display->display_options['filters']['field_os2web_base_field_promote_tid']['id'] = 'field_os2web_base_field_promote_tid';
  $handler->display->display_options['filters']['field_os2web_base_field_promote_tid']['table'] = 'field_data_field_os2web_base_field_promote';
  $handler->display->display_options['filters']['field_os2web_base_field_promote_tid']['field'] = 'field_os2web_base_field_promote_tid';
  $handler->display->display_options['filters']['field_os2web_base_field_promote_tid']['value'] = array(
    0 => '7038',
  );
  $handler->display->display_options['filters']['field_os2web_base_field_promote_tid']['vocabulary'] = 'os2web_base_tax_promoteto';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'kommunen/nyheder/pressemeddelelser-1';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Pressemeddelelser';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-indholdsmenu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Side */
  $handler = $view->new_display('page', 'Side', 'page_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'bg-white os2web-list';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'smallteaser';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterie: Indhold: Udgivet */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterie: Indhold: Forfrem til (field_os2web_base_field_promote) */
  $handler->display->display_options['filters']['field_os2web_base_field_promote_tid']['id'] = 'field_os2web_base_field_promote_tid';
  $handler->display->display_options['filters']['field_os2web_base_field_promote_tid']['table'] = 'field_data_field_os2web_base_field_promote';
  $handler->display->display_options['filters']['field_os2web_base_field_promote_tid']['field'] = 'field_os2web_base_field_promote_tid';
  $handler->display->display_options['filters']['field_os2web_base_field_promote_tid']['value'] = array(
    0 => '7038',
  );
  $handler->display->display_options['filters']['field_os2web_base_field_promote_tid']['vocabulary'] = 'os2web_base_tax_promoteto';
  $handler->display->display_options['path'] = 'kommunen/nyheder/pressemeddelelser';

  /* Display: Side */
  $handler = $view->new_display('page', 'Side', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Aktuelle udbud';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'bg-white os2web-list';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'smallteaser';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterie: Indhold: Udgivet */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterie: Indhold: Nyhedstype (field_os2web_news_page_type) */
  $handler->display->display_options['filters']['field_os2web_news_page_type_tid']['id'] = 'field_os2web_news_page_type_tid';
  $handler->display->display_options['filters']['field_os2web_news_page_type_tid']['table'] = 'field_data_field_os2web_news_page_type';
  $handler->display->display_options['filters']['field_os2web_news_page_type_tid']['field'] = 'field_os2web_news_page_type_tid';
  $handler->display->display_options['filters']['field_os2web_news_page_type_tid']['value'] = array(
    4054 => '4054',
  );
  $handler->display->display_options['filters']['field_os2web_news_page_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_os2web_news_page_type_tid']['vocabulary'] = 'os2web_news_page_newstypes';
  $handler->display->display_options['path'] = 'kommunen/nyheder/udbud';
  $translatables['pressemeddelelser'] = array(
    t('Master'),
    t('Pressemeddelelser'),
    t('mere'),
    t('Udfør'),
    t('Gendan'),
    t('Sortér efter'),
    t('Stigende'),
    t('Faldende'),
    t('Antal elementer'),
    t('- Alle -'),
    t('Forskydning'),
    t('« første'),
    t('‹ forrige'),
    t('næste ›'),
    t('sidste »'),
    t('Page'),
    t('Side'),
    t('Aktuelle udbud'),
  );
  $export['pressemeddelelser'] = $view;

  $view = new view();
  $view->name = 'svendborg_inactive_users';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Svendborg Inaktive brugere';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Inaktive brugere';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mere';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Udfør';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Gendan';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér efter';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Faldende';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Antal elementer';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Forskydning';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« første';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ forrige';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'næste ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'sidste »';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Overskrift: Global: Ufiltreret tekst */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  /* Felt: Masse-handlinger: Bruger */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'users';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::user_block_user_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_user_cancel_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_revision' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_user_roles_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::pathauto_user_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Felt: Bruger: Navn */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Felt: Bruger: Seneste login */
  $handler->display->display_options['fields']['login']['id'] = 'login';
  $handler->display->display_options['fields']['login']['table'] = 'users';
  $handler->display->display_options['fields']['login']['field'] = 'login';
  $handler->display->display_options['fields']['login']['date_format'] = 'os2web_base_date_only';
  /* Felt: Bruger: Seneste tilgang */
  $handler->display->display_options['fields']['access']['id'] = 'access';
  $handler->display->display_options['fields']['access']['table'] = 'users';
  $handler->display->display_options['fields']['access']['field'] = 'access';
  $handler->display->display_options['fields']['access']['date_format'] = 'os2web_base_date_only';
  /* Sorteringskriterie: Bruger: Seneste login */
  $handler->display->display_options['sorts']['login']['id'] = 'login';
  $handler->display->display_options['sorts']['login']['table'] = 'users';
  $handler->display->display_options['sorts']['login']['field'] = 'login';
  /* Filterkriterie: Bruger: Aktiv */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterie: Bruger: Seneste login */
  $handler->display->display_options['filters']['login']['id'] = 'login';
  $handler->display->display_options['filters']['login']['table'] = 'users';
  $handler->display->display_options['filters']['login']['field'] = 'login';
  $handler->display->display_options['filters']['login']['operator'] = '<';
  $handler->display->display_options['filters']['login']['value']['value'] = '-30 day';
  $handler->display->display_options['filters']['login']['value']['type'] = 'offset';
  $handler->display->display_options['filters']['login']['exposed'] = TRUE;
  $handler->display->display_options['filters']['login']['expose']['operator_id'] = 'login_op';
  $handler->display->display_options['filters']['login']['expose']['label'] = 'Seneste login';
  $handler->display->display_options['filters']['login']['expose']['description'] = 'Relativt til det aktuelle tidspunkt, f.eks. "-30 day" eller "-2 hours -30 minutes"';
  $handler->display->display_options['filters']['login']['expose']['operator'] = 'login_op';
  $handler->display->display_options['filters']['login']['expose']['identifier'] = 'login';
  $handler->display->display_options['filters']['login']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    4 => 0,
    7 => 0,
    3 => 0,
    5 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/people/inaktive-brugere';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Inaktive brugere';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Inaktive brugere';
  $handler->display->display_options['tab_options']['weight'] = '2';
  $handler->display->display_options['tab_options']['name'] = 'management';
  $translatables['svendborg_inactive_users'] = array(
    t('Master'),
    t('Inaktive brugere'),
    t('mere'),
    t('Udfør'),
    t('Gendan'),
    t('Sortér efter'),
    t('Stigende'),
    t('Faldende'),
    t('Antal elementer'),
    t('- Alle -'),
    t('Forskydning'),
    t('« første'),
    t('‹ forrige'),
    t('næste ›'),
    t('sidste »'),
    t('Bruger'),
    t('- Vælg en handling -'),
    t('Navn'),
    t('Seneste login'),
    t('Seneste tilgang'),
    t('Relativt til det aktuelle tidspunkt, f.eks. "-30 day" eller "-2 hours -30 minutes"'),
    t('Page'),
  );
  $export['svendborg_inactive_users'] = $view;

  $view = new view();
  $view->name = 'svendborg_news_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Svendborg News view';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mere';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Udfør';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Gendan';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér efter';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Faldende';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Felt: Indhold: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sorteringskriterie: Indhold: Oprettelsesdato */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Kontekstuelt filter: Indhold: Nyhedstype (field_os2web_news_page_type) */
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['id'] = 'field_os2web_news_page_type_tid';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['table'] = 'field_data_field_os2web_news_page_type';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['field'] = 'field_os2web_news_page_type_tid';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['validate_options']['vocabularies'] = array(
    'os2web_news_page_newstypes' => 'os2web_news_page_newstypes',
  );
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  /* Filterkriterie: Indhold: Udgivet */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterie: Indhold: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'os2web_base_news' => 'os2web_base_news',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filterkriterie: Indhold: Arkiveringsdato (field_os2web_news_page_archive) */
  $handler->display->display_options['filters']['field_os2web_news_page_archive_value']['id'] = 'field_os2web_news_page_archive_value';
  $handler->display->display_options['filters']['field_os2web_news_page_archive_value']['table'] = 'field_data_field_os2web_news_page_archive';
  $handler->display->display_options['filters']['field_os2web_news_page_archive_value']['field'] = 'field_os2web_news_page_archive_value';
  $handler->display->display_options['filters']['field_os2web_news_page_archive_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_os2web_news_page_archive_value']['group'] = 2;
  $handler->display->display_options['filters']['field_os2web_news_page_archive_value']['default_date'] = 'now';
  /* Filterkriterie: Indhold: Arkiveringsdato (field_os2web_news_page_archive) */
  $handler->display->display_options['filters']['field_os2web_news_page_archive_value_1']['id'] = 'field_os2web_news_page_archive_value_1';
  $handler->display->display_options['filters']['field_os2web_news_page_archive_value_1']['table'] = 'field_data_field_os2web_news_page_archive';
  $handler->display->display_options['filters']['field_os2web_news_page_archive_value_1']['field'] = 'field_os2web_news_page_archive_value';
  $handler->display->display_options['filters']['field_os2web_news_page_archive_value_1']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_os2web_news_page_archive_value_1']['group'] = 2;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mere';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Antal elementer';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Forskydning';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« første';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ forrige';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'næste ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'sidste »';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'col-md-6 col-sm-6 col-xs-12 switch_elements all';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontekstuelt filter: Indhold: Nyhedstype (field_os2web_news_page_type) */
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['id'] = 'field_os2web_news_page_type_tid';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['table'] = 'field_data_field_os2web_news_page_type';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['field'] = 'field_os2web_news_page_type_tid';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['validate_options']['vocabularies'] = array(
    'os2web_news_page_newstypes' => 'os2web_news_page_newstypes',
  );
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['validate_options']['type'] = 'convert';
  /* Kontekstuelt filter: Indhold: Har taksonomiterm ID (med dybde) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['term_node_tid_depth']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '7';

  /* Display: Block_tab_udbud */
  $handler = $view->new_display('block', 'Block_tab_udbud', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Sidefod: Global: Tekstområde */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a class="btn btn-primary" href="/nyheder/udbud">Alle</a>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['footer']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Opførsel ved ingen resultater: Global: Tekstområde */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<div class="bg-white well">Der er i øjeblikket ingen aktuelle udbud.</div>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Indhold: Oprettelsesdato */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd. M. Y';
  /* Felt: Indhold: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '30';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Felt: Indhold: Primære billede */
  $handler->display->display_options['fields']['field_os2web_base_field_lead_img']['id'] = 'field_os2web_base_field_lead_img';
  $handler->display->display_options['fields']['field_os2web_base_field_lead_img']['table'] = 'field_data_field_os2web_base_field_lead_img';
  $handler->display->display_options['fields']['field_os2web_base_field_lead_img']['field'] = 'field_os2web_base_field_lead_img';
  $handler->display->display_options['fields']['field_os2web_base_field_lead_img']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_base_field_lead_img']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_base_field_lead_img']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_base_field_lead_img']['alter']['text'] = '<div class="col-md-3 col-sm-6 col-xs-4">
[field_os2web_base_field_lead_img]
</div>
<div class="col-md-9 col-sm-6 col-xs-8">
<div>[created]</div>
<h4>[title]</h4>
</div>
<div class="clearfix">';
  $handler->display->display_options['fields']['field_os2web_base_field_lead_img']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_base_field_lead_img']['empty'] = '<div>[created]</div>
<h4>[title]</h4>
<div class="clearfix">';
  $handler->display->display_options['fields']['field_os2web_base_field_lead_img']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_os2web_base_field_lead_img']['settings'] = array(
    'image_style' => 'media_thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_os2web_base_field_lead_img']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_os2web_base_field_lead_img']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_os2web_base_field_lead_img']['separator'] = '';
  /* Felt: Indhold: Intro / Resume (maks 2 linier!) */
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['id'] = 'field_os2web_base_field_summary';
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['table'] = 'field_data_field_os2web_base_field_summary';
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['field'] = 'field_os2web_base_field_summary';
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['alter']['max_length'] = '80';
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['element_label_colon'] = FALSE;
  /* Felt: Global: Tilpasset tekst */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="col-md-12 col-sm-12 col-xs-12 quicktabs-nyheder-row">
   <div class="col-md-12 quicktabs-row-border">
     <div>[created]</div>
     <h4>[title]</h4>
      [field_os2web_base_field_summary]
  </div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Felt: Indhold: Nyhedstype */
  $handler->display->display_options['fields']['field_os2web_news_page_type']['id'] = 'field_os2web_news_page_type';
  $handler->display->display_options['fields']['field_os2web_news_page_type']['table'] = 'field_data_field_os2web_news_page_type';
  $handler->display->display_options['fields']['field_os2web_news_page_type']['field'] = 'field_os2web_news_page_type';
  $handler->display->display_options['fields']['field_os2web_news_page_type']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_news_page_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_news_page_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_news_page_type']['alter']['text'] = 'Alle ';
  $handler->display->display_options['fields']['field_os2web_news_page_type']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_news_page_type']['alter']['path'] = 'nyheder/[field_os2web_news_page_type] ';
  $handler->display->display_options['fields']['field_os2web_news_page_type']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_news_page_type']['element_class'] = 'btn btn-primary';
  $handler->display->display_options['fields']['field_os2web_news_page_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_news_page_type']['settings'] = array(
    'linked_field' => array(
      'linked' => 0,
      'destination' => '',
      'advanced' => array(
        'title' => '',
        'target' => '',
        'class' => '',
        'rel' => '',
        'text' => '',
      ),
    ),
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontekstuelt filter: Indhold: Nyhedstype (field_os2web_news_page_type) */
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['id'] = 'field_os2web_news_page_type_tid';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['table'] = 'field_data_field_os2web_news_page_type';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['field'] = 'field_os2web_news_page_type_tid';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['validate_options']['vocabularies'] = array(
    'os2web_news_page_newstypes' => 'os2web_news_page_newstypes',
  );
  $handler->display->display_options['block_description'] = 'tab';

  /* Display: Side */
  $handler = $view->new_display('page', 'Side', 'page_1');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Indhold: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Felt: Indhold: Oprettelsesdato */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'day';
  /* Felt: Indhold: Oprettelsesdato */
  $handler->display->display_options['fields']['created_1']['id'] = 'created_1';
  $handler->display->display_options['fields']['created_1']['table'] = 'node';
  $handler->display->display_options['fields']['created_1']['field'] = 'created';
  $handler->display->display_options['fields']['created_1']['label'] = '';
  $handler->display->display_options['fields']['created_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created_1']['date_format'] = 'month';
  /* Felt: Indhold: Intro / Resume (maks 2 linier!) */
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['id'] = 'field_os2web_base_field_summary';
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['table'] = 'field_data_field_os2web_base_field_summary';
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['field'] = 'field_os2web_base_field_summary';
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['element_label_colon'] = FALSE;
  /* Felt: Global: Tilpasset tekst */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="front-s-news-item front-s-news-item-">
  <div class="front-s-news-item-text clearfix">
       <div class="col-md-2 col-sm-2 col-xs-2">
            <div class="news-text-date">
                  <span class="news-date-day">[created]</span>
                   <span class="news-date-month">[created_1]</span>
             </div>
        </div>

       <div class="col-md-10 col-sm-10 col-xs-10">
               [title]
              <div>
                    [field_os2web_base_field_summary]      
              </div>
        </div>
  </div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontekstuelt filter: Indhold: Nyhedstype (field_os2web_news_page_type) */
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['id'] = 'field_os2web_news_page_type_tid';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['table'] = 'field_data_field_os2web_news_page_type';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['field'] = 'field_os2web_news_page_type_tid';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['validate_options']['vocabularies'] = array(
    'os2web_news_page_newstypes' => 'os2web_news_page_newstypes',
  );
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['path'] = 'nyheder/%';

  /* Display: Block_tab_Byrådsmøde */
  $handler = $view->new_display('block', 'Block_tab_Byrådsmøde', 'block_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Sidefod: Global: Tekstområde */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a class="btn btn-primary" href="http://portal.svendborg.dk/SitePages/Home.aspx?RootFolder=%2Fdagsordener%2FByr%C3%A5det%20%28%C3%85ben%29&FolderCTID=0x01200064623F16242C5144BA0C582FFB25C83700D598BBF91722064299CA3465D8735E1E&View={3793E986-5C71-40A7-8019-F38A3E43F653}c" target="_blank">Alle byrådsmøder</a>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['footer']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Opførsel ved ingen resultater: Global: Ufiltreret tekst */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<div class="bg-white well">Der er intet aktuelt byrådsmøde.</div>';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Indhold: Oprettelsesdato */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd. M. Y';
  /* Felt: Indhold: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '30';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Felt: Indhold: Intro / Resume (maks 2 linier!) */
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['id'] = 'field_os2web_base_field_summary';
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['table'] = 'field_data_field_os2web_base_field_summary';
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['field'] = 'field_os2web_base_field_summary';
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['alter']['max_length'] = '80';
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['element_label_colon'] = FALSE;
  /* Felt: Global: Tilpasset tekst */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="col-md-12 col-sm-12 col-xs-12 quicktabs-nyheder-row">
   <div class="col-md-12 quicktabs-row-border">
     <div>[created]</div>
     <h4>[title]</h4>
      [field_os2web_base_field_summary]
  </div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Felt: Indhold: Nyhedstype */
  $handler->display->display_options['fields']['field_os2web_news_page_type']['id'] = 'field_os2web_news_page_type';
  $handler->display->display_options['fields']['field_os2web_news_page_type']['table'] = 'field_data_field_os2web_news_page_type';
  $handler->display->display_options['fields']['field_os2web_news_page_type']['field'] = 'field_os2web_news_page_type';
  $handler->display->display_options['fields']['field_os2web_news_page_type']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_news_page_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_news_page_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_news_page_type']['alter']['text'] = 'Se Alle';
  $handler->display->display_options['fields']['field_os2web_news_page_type']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_news_page_type']['alter']['path'] = 'nyheder/[field_os2web_news_page_type] ';
  $handler->display->display_options['fields']['field_os2web_news_page_type']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_news_page_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_news_page_type']['settings'] = array(
    'linked_field' => array(
      'linked' => 0,
      'destination' => '',
      'advanced' => array(
        'title' => '',
        'target' => '',
        'class' => '',
        'rel' => '',
        'text' => '',
      ),
    ),
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontekstuelt filter: Indhold: Nyhedstype (field_os2web_news_page_type) */
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['id'] = 'field_os2web_news_page_type_tid';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['table'] = 'field_data_field_os2web_news_page_type';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['field'] = 'field_os2web_news_page_type_tid';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['validate_options']['vocabularies'] = array(
    'os2web_news_page_newstypes' => 'os2web_news_page_newstypes',
  );
  $handler->display->display_options['block_description'] = 'tab';

  /* Display: frontpage and carousel */
  $handler = $view->new_display('block', 'frontpage and carousel', 'front');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mere';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Antal elementer';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Forskydning';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« første';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ forrige';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'næste ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'sidste »';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'col-md-6 col-sm-6 col-xs-12 switch_elements all';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
    3 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterie: Indhold: Udgivet */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterie: Indhold: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'os2web_base_news' => 'os2web_base_news',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filterkriterie: Indhold: Primære billede (field_os2web_base_field_lead_img:fid) */
  $handler->display->display_options['filters']['field_os2web_base_field_lead_img_fid']['id'] = 'field_os2web_base_field_lead_img_fid';
  $handler->display->display_options['filters']['field_os2web_base_field_lead_img_fid']['table'] = 'field_data_field_os2web_base_field_lead_img';
  $handler->display->display_options['filters']['field_os2web_base_field_lead_img_fid']['field'] = 'field_os2web_base_field_lead_img_fid';
  $handler->display->display_options['filters']['field_os2web_base_field_lead_img_fid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_os2web_base_field_lead_img_fid']['group'] = 1;
  /* Filterkriterie: Indhold: Arkiveringsdato (field_os2web_news_page_archive) */
  $handler->display->display_options['filters']['field_os2web_news_page_archive_value']['id'] = 'field_os2web_news_page_archive_value';
  $handler->display->display_options['filters']['field_os2web_news_page_archive_value']['table'] = 'field_data_field_os2web_news_page_archive';
  $handler->display->display_options['filters']['field_os2web_news_page_archive_value']['field'] = 'field_os2web_news_page_archive_value';
  $handler->display->display_options['filters']['field_os2web_news_page_archive_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_os2web_news_page_archive_value']['group'] = 2;
  $handler->display->display_options['filters']['field_os2web_news_page_archive_value']['default_date'] = 'now';
  /* Filterkriterie: Indhold: Arkiveringsdato (field_os2web_news_page_archive) */
  $handler->display->display_options['filters']['field_os2web_news_page_archive_value_1']['id'] = 'field_os2web_news_page_archive_value_1';
  $handler->display->display_options['filters']['field_os2web_news_page_archive_value_1']['table'] = 'field_data_field_os2web_news_page_archive';
  $handler->display->display_options['filters']['field_os2web_news_page_archive_value_1']['field'] = 'field_os2web_news_page_archive_value';
  $handler->display->display_options['filters']['field_os2web_news_page_archive_value_1']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_os2web_news_page_archive_value_1']['group'] = 2;
  /* Filterkriterie: Indhold: Forfremmet til forside */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  $handler->display->display_options['filters']['promote']['group'] = 3;
  /* Filterkriterie: Indhold: Forfrem til (field_os2web_base_field_promote) */
  $handler->display->display_options['filters']['field_os2web_base_field_promote_tid']['id'] = 'field_os2web_base_field_promote_tid';
  $handler->display->display_options['filters']['field_os2web_base_field_promote_tid']['table'] = 'field_data_field_os2web_base_field_promote';
  $handler->display->display_options['filters']['field_os2web_base_field_promote_tid']['field'] = 'field_os2web_base_field_promote_tid';
  $handler->display->display_options['filters']['field_os2web_base_field_promote_tid']['value'] = array(
    6955 => '6955',
  );
  $handler->display->display_options['filters']['field_os2web_base_field_promote_tid']['group'] = 3;
  $handler->display->display_options['filters']['field_os2web_base_field_promote_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_os2web_base_field_promote_tid']['vocabulary'] = 'os2web_base_tax_promoteto';
  $handler->display->display_options['block_description'] = 'frontpage and carousel';

  /* Display: frontpage and carousel small */
  $handler = $view->new_display('block', 'frontpage and carousel small', 'block_3');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mere';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Antal elementer';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Forskydning';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« første';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ forrige';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'næste ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'sidste »';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'col-md-6 col-sm-6 col-xs-12 switch_elements all';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
    3 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterie: Indhold: Udgivet */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterie: Indhold: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'os2web_base_news' => 'os2web_base_news',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filterkriterie: Indhold: Primære billede (field_os2web_base_field_lead_img:fid) */
  $handler->display->display_options['filters']['field_os2web_base_field_lead_img_fid']['id'] = 'field_os2web_base_field_lead_img_fid';
  $handler->display->display_options['filters']['field_os2web_base_field_lead_img_fid']['table'] = 'field_data_field_os2web_base_field_lead_img';
  $handler->display->display_options['filters']['field_os2web_base_field_lead_img_fid']['field'] = 'field_os2web_base_field_lead_img_fid';
  $handler->display->display_options['filters']['field_os2web_base_field_lead_img_fid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_os2web_base_field_lead_img_fid']['group'] = 1;
  /* Filterkriterie: Indhold: Arkiveringsdato (field_os2web_news_page_archive) */
  $handler->display->display_options['filters']['field_os2web_news_page_archive_value']['id'] = 'field_os2web_news_page_archive_value';
  $handler->display->display_options['filters']['field_os2web_news_page_archive_value']['table'] = 'field_data_field_os2web_news_page_archive';
  $handler->display->display_options['filters']['field_os2web_news_page_archive_value']['field'] = 'field_os2web_news_page_archive_value';
  $handler->display->display_options['filters']['field_os2web_news_page_archive_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_os2web_news_page_archive_value']['group'] = 2;
  $handler->display->display_options['filters']['field_os2web_news_page_archive_value']['default_date'] = 'now';
  /* Filterkriterie: Indhold: Arkiveringsdato (field_os2web_news_page_archive) */
  $handler->display->display_options['filters']['field_os2web_news_page_archive_value_1']['id'] = 'field_os2web_news_page_archive_value_1';
  $handler->display->display_options['filters']['field_os2web_news_page_archive_value_1']['table'] = 'field_data_field_os2web_news_page_archive';
  $handler->display->display_options['filters']['field_os2web_news_page_archive_value_1']['field'] = 'field_os2web_news_page_archive_value';
  $handler->display->display_options['filters']['field_os2web_news_page_archive_value_1']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_os2web_news_page_archive_value_1']['group'] = 2;
  /* Filterkriterie: Indhold: Forfremmet til forside */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  $handler->display->display_options['filters']['promote']['group'] = 3;
  /* Filterkriterie: Indhold: Forfrem til (field_os2web_base_field_promote) */
  $handler->display->display_options['filters']['field_os2web_base_field_promote_tid']['id'] = 'field_os2web_base_field_promote_tid';
  $handler->display->display_options['filters']['field_os2web_base_field_promote_tid']['table'] = 'field_data_field_os2web_base_field_promote';
  $handler->display->display_options['filters']['field_os2web_base_field_promote_tid']['field'] = 'field_os2web_base_field_promote_tid';
  $handler->display->display_options['filters']['field_os2web_base_field_promote_tid']['value'] = array(
    6955 => '6955',
  );
  $handler->display->display_options['filters']['field_os2web_base_field_promote_tid']['group'] = 3;
  $handler->display->display_options['filters']['field_os2web_base_field_promote_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_os2web_base_field_promote_tid']['vocabulary'] = 'os2web_base_tax_promoteto';
  /* Filterkriterie: Indhold: Nyhedstype (field_os2web_news_page_type) */
  $handler->display->display_options['filters']['field_os2web_news_page_type_tid']['id'] = 'field_os2web_news_page_type_tid';
  $handler->display->display_options['filters']['field_os2web_news_page_type_tid']['table'] = 'field_data_field_os2web_news_page_type';
  $handler->display->display_options['filters']['field_os2web_news_page_type_tid']['field'] = 'field_os2web_news_page_type_tid';
  $handler->display->display_options['filters']['field_os2web_news_page_type_tid']['operator'] = 'not';
  $handler->display->display_options['filters']['field_os2web_news_page_type_tid']['value'] = array(
    4099 => '4099',
  );
  $handler->display->display_options['filters']['field_os2web_news_page_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_os2web_news_page_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_os2web_news_page_type_tid']['vocabulary'] = 'os2web_news_page_newstypes';
  $handler->display->display_options['block_description'] = 'frontpage and carousel';

  /* Display: Block_tab_høringer */
  $handler = $view->new_display('block', 'Block_tab_høringer', 'block_4');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Sidefod: Global: Tekstområde */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a class="btn btn-primary" href="/nyheder/hoeringer">Alle</a>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['footer']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Opførsel ved ingen resultater: Global: Tekstområde */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<div class="bg-white well">Der er i øjeblikket ingen aktuelle høringer.</div>';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Indhold: Oprettelsesdato */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd. M. Y';
  /* Felt: Indhold: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '30';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Felt: Indhold: Intro / Resume (maks 2 linier!) */
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['id'] = 'field_os2web_base_field_summary';
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['table'] = 'field_data_field_os2web_base_field_summary';
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['field'] = 'field_os2web_base_field_summary';
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['alter']['max_length'] = '80';
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['element_label_colon'] = FALSE;
  /* Felt: Global: Tilpasset tekst */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="col-md-12 col-sm-12 col-xs-12 quicktabs-nyheder-row">
   <div class="col-md-12 quicktabs-row-border">
     <div>[created]</div>
     <h4>[title]</h4>
      [field_os2web_base_field_summary]
  </div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Felt: Indhold: Nyhedstype */
  $handler->display->display_options['fields']['field_os2web_news_page_type']['id'] = 'field_os2web_news_page_type';
  $handler->display->display_options['fields']['field_os2web_news_page_type']['table'] = 'field_data_field_os2web_news_page_type';
  $handler->display->display_options['fields']['field_os2web_news_page_type']['field'] = 'field_os2web_news_page_type';
  $handler->display->display_options['fields']['field_os2web_news_page_type']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_news_page_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_news_page_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_news_page_type']['alter']['text'] = 'Alle ';
  $handler->display->display_options['fields']['field_os2web_news_page_type']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_news_page_type']['alter']['path'] = 'nyheder/[field_os2web_news_page_type] ';
  $handler->display->display_options['fields']['field_os2web_news_page_type']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_news_page_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_news_page_type']['settings'] = array(
    'linked_field' => array(
      'linked' => 0,
      'destination' => '',
      'advanced' => array(
        'title' => '',
        'target' => '',
        'class' => '',
        'rel' => '',
        'text' => '',
      ),
    ),
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontekstuelt filter: Indhold: Nyhedstype (field_os2web_news_page_type) */
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['id'] = 'field_os2web_news_page_type_tid';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['table'] = 'field_data_field_os2web_news_page_type';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['field'] = 'field_os2web_news_page_type_tid';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_os2web_news_page_type_tid']['validate_options']['vocabularies'] = array(
    'os2web_news_page_newstypes' => 'os2web_news_page_newstypes',
  );
  $handler->display->display_options['block_description'] = 'tab';
  $translatables['svendborg_news_view'] = array(
    t('Master'),
    t('mere'),
    t('Udfør'),
    t('Gendan'),
    t('Sortér efter'),
    t('Stigende'),
    t('Faldende'),
    t('Alle'),
    t('Block'),
    t('Antal elementer'),
    t('- Alle -'),
    t('Forskydning'),
    t('« første'),
    t('‹ forrige'),
    t('næste ›'),
    t('sidste »'),
    t('Block_tab_udbud'),
    t('<a class="btn btn-primary" href="/nyheder/udbud">Alle</a>'),
    t('<div class="bg-white well">Der er i øjeblikket ingen aktuelle udbud.</div>'),
    t('<div class="col-md-3 col-sm-6 col-xs-4">
[field_os2web_base_field_lead_img]
</div>
<div class="col-md-9 col-sm-6 col-xs-8">
<div>[created]</div>
<h4>[title]</h4>
</div>
<div class="clearfix">'),
    t('<div>[created]</div>
<h4>[title]</h4>
<div class="clearfix">'),
    t('<div class="col-md-12 col-sm-12 col-xs-12 quicktabs-nyheder-row">
   <div class="col-md-12 quicktabs-row-border">
     <div>[created]</div>
     <h4>[title]</h4>
      [field_os2web_base_field_summary]
  </div>
</div>'),
    t('Alle '),
    t('tab'),
    t('Side'),
    t('<div class="front-s-news-item front-s-news-item-">
  <div class="front-s-news-item-text clearfix">
       <div class="col-md-2 col-sm-2 col-xs-2">
            <div class="news-text-date">
                  <span class="news-date-day">[created]</span>
                   <span class="news-date-month">[created_1]</span>
             </div>
        </div>

       <div class="col-md-10 col-sm-10 col-xs-10">
               [title]
              <div>
                    [field_os2web_base_field_summary]      
              </div>
        </div>
  </div>
</div>'),
    t('Block_tab_Byrådsmøde'),
    t('<a class="btn btn-primary" href="http://portal.svendborg.dk/SitePages/Home.aspx?RootFolder=%2Fdagsordener%2FByr%C3%A5det%20%28%C3%85ben%29&FolderCTID=0x01200064623F16242C5144BA0C582FFB25C83700D598BBF91722064299CA3465D8735E1E&View={3793E986-5C71-40A7-8019-F38A3E43F653}c" target="_blank">Alle byrådsmøder</a>'),
    t('<div class="bg-white well">Der er intet aktuelt byrådsmøde.</div>'),
    t('Se Alle'),
    t('frontpage and carousel'),
    t('frontpage and carousel small'),
    t('Block_tab_høringer'),
    t('<a class="btn btn-primary" href="/nyheder/hoeringer">Alle</a>'),
    t('<div class="bg-white well">Der er i øjeblikket ingen aktuelle høringer.</div>'),
  );
  $export['svendborg_news_view'] = $view;

  return $export;
}
