<?php
/**
 * @file
 * svendborg_os2web_news_page.features.inc
 */

/**
 * Implements hook_views_default_views_alter().
 */
function svendborg_os2web_news_page_views_default_views_alter(&$data) {
  if (isset($data['os2web_news_lists'])) {
    $data['os2web_news_lists']->display['panel_pane_1']->display_options['fields']['field_os2web_base_field_lead_img']['settings']['image_style'] = 'svendborg_content_image'; /* WAS: 'fredericia_content_image' */
    $data['os2web_news_lists']->display['panel_pane_1']->display_options['row_options'] = array(
      'image' => 'field_os2web_base_field_lead_img',
      'title' => 'title',
      'description' => '',
    ); /* WAS: '' */
    $data['os2web_news_lists']->display['panel_pane_1']->display_options['row_plugin'] = 'views_bootstrap_carousel_plugin_rows'; /* WAS: 'fields' */
    $data['os2web_news_lists']->display['panel_pane_1']->display_options['style_options'] = array(
      'interval' => 5000,
      'navigation' => 0,
      'indicators' => 1,
      'pause' => 1,
    ); /* WAS: '' */
    $data['os2web_news_lists']->display['panel_pane_1']->display_options['style_plugin'] = 'views_bootstrap_carousel_plugin_style'; /* WAS: 'default' */
  }
}
