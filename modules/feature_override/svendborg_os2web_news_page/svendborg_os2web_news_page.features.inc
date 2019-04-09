<?php
/**
 * @file
 * svendborg_os2web_news_page.features.inc
 */

/**
 * Implements hook_field_default_field_instances_alter().
 */
function svendborg_os2web_news_page_field_default_field_instances_alter(&$data) {
  if (isset($data['node-os2web_base_news-field_os2web_base_field_lead_img'])) {
    $data['node-os2web_base_news-field_os2web_base_field_lead_img']['display']['default']['settings']['slideshow_image_style'] = 'svendborg_content_image'; /* WAS: 'fredericia_content_image' */
    $data['node-os2web_base_news-field_os2web_base_field_lead_img']['settings']['epsacrop']['styles']['svendborg_content_image'] = 'svendborg_content_image'; /* WAS: '' */
    $data['node-os2web_base_news-field_os2web_base_field_lead_img']['settings']['epsacrop']['styles']['svendborg_spotbox'] = 0; /* WAS: '' */
    $data['node-os2web_base_news-field_os2web_base_field_lead_img']['settings']['wysiwyg_insert'] = 0; /* WAS: '' */
    $data['node-os2web_base_news-field_os2web_base_field_lead_img']['widget']['settings']['allowed_schemes']['oembed'] = 0; /* WAS: '' */
    $data['node-os2web_base_news-field_os2web_base_field_lead_img']['widget']['settings']['allowed_schemes']['private'] = 0; /* WAS: '' */
    unset($data['node-os2web_base_news-field_os2web_base_field_lead_img']['settings']['epsacrop']['styles']['fredericia_content_image']);
    unset($data['node-os2web_base_news-field_os2web_base_field_lead_img']['settings']['epsacrop']['styles']['fredericia_spotbox']);
    unset($data['node-os2web_base_news-field_os2web_base_field_lead_img']['widget']['settings']['browser_plugins']['youtube']);
    unset($data['node-os2web_base_news-field_os2web_base_field_lead_img']['widget']['settings']['progress_indicator']);
  }
}

/**
 * Implements hook_views_default_views_alter().
 */
function svendborg_os2web_news_page_views_default_views_alter(&$data) {
  if (isset($data['os2web_news_lists'])) {
    $data['os2web_news_lists']->display['panel_pane_1']->display_options['fields']['field_os2web_base_field_lead_img']['settings']['image_style'] = 'svendborg_content_image'; /* WAS: 'fredericia_content_image' */
  }
}
