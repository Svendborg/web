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
  if (isset($data['node-os2web_base_news-field_os2web_base_hide_contact'])) {
    $data['node-os2web_base_news-field_os2web_base_hide_contact']['display']['default']['type'] = 'hidden'; /* WAS: 'list_default' */
    $data['node-os2web_base_news-field_os2web_base_hide_contact']['display']['default']['weight'] = 9; /* WAS: 23 */
    $data['node-os2web_base_news-field_os2web_base_hide_contact']['display']['spotbox'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    unset($data['node-os2web_base_news-field_os2web_base_hide_contact']['display']['default']['module']);
  }
  if (isset($data['node-os2web_base_news-field_os2web_base_hide_sidebar'])) {
    $data['node-os2web_base_news-field_os2web_base_hide_sidebar']['display']['default']['type'] = 'hidden'; /* WAS: 'list_default' */
    $data['node-os2web_base_news-field_os2web_base_hide_sidebar']['display']['default']['weight'] = 14; /* WAS: 22 */
    $data['node-os2web_base_news-field_os2web_base_hide_sidebar']['display']['spotbox'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    unset($data['node-os2web_base_news-field_os2web_base_hide_sidebar']['display']['default']['module']);
  }
  if (isset($data['node-os2web_base_news-field_os2web_news_date_end'])) {
    $data['node-os2web_base_news-field_os2web_news_date_end']['display']['default']['type'] = 'hidden'; /* WAS: 'date_default' */
    $data['node-os2web_base_news-field_os2web_news_date_end']['display']['default']['weight'] = 6; /* WAS: 21 */
    unset($data['node-os2web_base_news-field_os2web_news_date_end']['display']['default']['module']);
    unset($data['node-os2web_base_news-field_os2web_news_date_end']['display']['default']['settings']['format_type']);
    unset($data['node-os2web_base_news-field_os2web_news_date_end']['display']['default']['settings']['fromto']);
    unset($data['node-os2web_base_news-field_os2web_news_date_end']['display']['default']['settings']['multiple_from']);
    unset($data['node-os2web_base_news-field_os2web_news_date_end']['display']['default']['settings']['multiple_number']);
    unset($data['node-os2web_base_news-field_os2web_news_date_end']['display']['default']['settings']['multiple_to']);
  }
  if (isset($data['node-os2web_base_news-field_os2web_news_date_start'])) {
    $data['node-os2web_base_news-field_os2web_news_date_start']['display']['default']['type'] = 'hidden'; /* WAS: 'date_default' */
    $data['node-os2web_base_news-field_os2web_news_date_start']['display']['default']['weight'] = 5; /* WAS: 20 */
    unset($data['node-os2web_base_news-field_os2web_news_date_start']['display']['default']['module']);
    unset($data['node-os2web_base_news-field_os2web_news_date_start']['display']['default']['settings']['format_type']);
    unset($data['node-os2web_base_news-field_os2web_news_date_start']['display']['default']['settings']['fromto']);
    unset($data['node-os2web_base_news-field_os2web_news_date_start']['display']['default']['settings']['multiple_from']);
    unset($data['node-os2web_base_news-field_os2web_news_date_start']['display']['default']['settings']['multiple_number']);
    unset($data['node-os2web_base_news-field_os2web_news_date_start']['display']['default']['settings']['multiple_to']);
  }
}

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
      'navigation' => 1,
      'indicators' => 1,
      'pause' => 0,
    ); /* WAS: '' */
    $data['os2web_news_lists']->display['panel_pane_1']->display_options['style_plugin'] = 'views_bootstrap_carousel_plugin_style'; /* WAS: 'default' */
  }
}
