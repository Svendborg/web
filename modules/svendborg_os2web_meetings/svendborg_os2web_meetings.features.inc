<?php
/**
 * @file
 * svendborg_os2web_meetings.features.inc
 */

/**
 * Implements hook_views_default_views_alter().
 */
function svendborg_os2web_meetings_views_default_views_alter(&$data) {
  if (isset($data['os2web_meetings'])) {
    $data['os2web_meetings']->display['page']->display_options['defaults']['use_ajax'] = FALSE; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_1']->display_options['fields']['field_os2web_meetings_type'] = array(
      'id' => 'field_os2web_meetings_type',
      'table' => 'field_data_field_os2web_meetings_type',
      'field' => 'field_os2web_meetings_type',
      'label' => '',
      'element_label_colon' => FALSE,
    ); /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_2']->display_options['link_to_view'] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['fields']['field_os2web_meetings_type'] = array(
      'id' => 'field_os2web_meetings_type',
      'table' => 'field_data_field_os2web_meetings_type',
      'field' => 'field_os2web_meetings_type',
      'label' => '',
      'element_label_colon' => FALSE,
    ); /* WAS: '' */
    unset($data['os2web_meetings']->display['panel_pane_1']->display_options['fields']['field_os2web_meetings_committee']['exclude']);
    unset($data['os2web_meetings']->display['panel_pane_1']->display_options['fields']['views_conditional']);
    unset($data['os2web_meetings']->display['panel_pane_3']->display_options['fields']['field_os2web_meetings_committee']['exclude']);
    unset($data['os2web_meetings']->display['panel_pane_3']->display_options['fields']['views_conditional']);
  }
}
