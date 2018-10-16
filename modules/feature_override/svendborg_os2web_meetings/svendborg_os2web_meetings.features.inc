<?php
/**
 * @file
 * svendborg_os2web_meetings.features.inc
 */

/**
 * Implements hook_field_default_field_instances_alter().
 */
function svendborg_os2web_meetings_field_default_field_instances_alter(&$data) {
  if (isset($data['node-os2web_meetings_bullet-field_os2web_meetings_enclosures'])) {
    $data['node-os2web_meetings_bullet-field_os2web_meetings_enclosures']['settings']['epsacrop'] = array(
      'styles' => array(
        'os2web_spotbox_image' => 0,
        'svendborg_content_image' => 0,
        'svendborg_spotbox' => 0,
      ),
    ); /* WAS: '' */
    $data['node-os2web_meetings_bullet-field_os2web_meetings_enclosures']['widget']['settings']['filefield_sources']['filefield_sources']['clipboard'] = 0; /* WAS: '' */
    $data['node-os2web_meetings_bullet-field_os2web_meetings_enclosures']['widget']['settings']['filefield_sources']['filefield_sources']['upload'] = 'upload'; /* WAS: '' */
    $data['node-os2web_meetings_bullet-field_os2web_meetings_enclosures']['widget']['settings']['filefield_sources']['source_imce'] = array(
      'imce_mode' => 0,
    ); /* WAS: '' */
    unset($data['node-os2web_meetings_bullet-field_os2web_meetings_enclosures']['widget']['settings']['filefield_sources']['filefield_sources']['plupload']);
  }
  if (isset($data['node-os2web_meetings_meeting-field_os2web_meetings_addendum'])) {
    $data['node-os2web_meetings_meeting-field_os2web_meetings_addendum']['display']['default']['weight'] = 4; /* WAS: 3 */
  }
  if (isset($data['node-os2web_meetings_meeting-field_os2web_meetings_bullets'])) {
    $data['node-os2web_meetings_meeting-field_os2web_meetings_bullets']['display']['default']['weight'] = 6; /* WAS: 5 */
  }
  if (isset($data['node-os2web_meetings_meeting-field_os2web_meetings_committee'])) {
    $data['node-os2web_meetings_meeting-field_os2web_meetings_committee']['display']['default']['type'] = 'taxonomy_term_reference_link'; /* WAS: 'taxonomy_term_reference_plain' */
    $data['node-os2web_meetings_meeting-field_os2web_meetings_committee']['display']['default']['weight'] = 2; /* WAS: 1 */
  }
  if (isset($data['node-os2web_meetings_meeting-field_os2web_meetings_date'])) {
    unset($data['node-os2web_meetings_meeting-field_os2web_meetings_date']['display']['default']['settings']['show_repeat_rule']);
  }
  if (isset($data['node-os2web_meetings_meeting-field_os2web_meetings_full_doc'])) {
    $data['node-os2web_meetings_meeting-field_os2web_meetings_full_doc']['display']['default']['weight'] = 5; /* WAS: 4 */
  }
  if (isset($data['node-os2web_meetings_meeting-field_os2web_meetings_location'])) {
    $data['node-os2web_meetings_meeting-field_os2web_meetings_location']['display']['default']['type'] = 'taxonomy_term_reference_link'; /* WAS: 'taxonomy_term_reference_plain' */
    $data['node-os2web_meetings_meeting-field_os2web_meetings_location']['display']['default']['weight'] = 3; /* WAS: 2 */
  }
  if (isset($data['node-os2web_meetings_meeting-field_os2web_meetings_type'])) {
    $data['node-os2web_meetings_meeting-field_os2web_meetings_type']['display']['default']['label'] = 'inline'; /* WAS: 'above' */
    $data['node-os2web_meetings_meeting-field_os2web_meetings_type']['display']['default']['module'] = 'list'; /* WAS: '' */
    $data['node-os2web_meetings_meeting-field_os2web_meetings_type']['display']['default']['type'] = 'list_default'; /* WAS: 'hidden' */
    $data['node-os2web_meetings_meeting-field_os2web_meetings_type']['display']['default']['weight'] = 1; /* WAS: 6 */
  }
}

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
    $data['os2web_meetings']->display['panel_pane_3']->display_options['fields']['title']['label'] = 'Titel'; /* WAS: '' */
    unset($data['os2web_meetings']->display['panel_pane_1']->display_options['fields']['field_os2web_meetings_committee']['exclude']);
    unset($data['os2web_meetings']->display['panel_pane_1']->display_options['fields']['views_conditional']);
    unset($data['os2web_meetings']->display['panel_pane_3']->display_options['fields']['field_os2web_meetings_committee']['exclude']);
    unset($data['os2web_meetings']->display['panel_pane_3']->display_options['fields']['views_conditional']);
  }
}
