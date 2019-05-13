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
    $data['node-os2web_meetings_bullet-field_os2web_meetings_enclosures']['widget']['settings']['filefield_sources']['source_reference']['search_all_fields'] = 0; /* WAS: '' */
  }
  if (isset($data['node-os2web_meetings_meeting-field_os2web_meetings_addendum'])) {
    $data['node-os2web_meetings_meeting-field_os2web_meetings_addendum']['display']['default']['weight'] = 4; /* WAS: 3 */
    $data['node-os2web_meetings_meeting-field_os2web_meetings_addendum']['widget']['weight'] = 13; /* WAS: 16 */
  }
  if (isset($data['node-os2web_meetings_meeting-field_os2web_meetings_bullets'])) {
    $data['node-os2web_meetings_meeting-field_os2web_meetings_bullets']['display']['default']['weight'] = 6; /* WAS: 5 */
    $data['node-os2web_meetings_meeting-field_os2web_meetings_bullets']['widget']['weight'] = 12; /* WAS: 14 */
  }
  if (isset($data['node-os2web_meetings_meeting-field_os2web_meetings_committee'])) {
    $data['node-os2web_meetings_meeting-field_os2web_meetings_committee']['display']['default']['type'] = 'taxonomy_term_reference_link'; /* WAS: 'taxonomy_term_reference_plain' */
    $data['node-os2web_meetings_meeting-field_os2web_meetings_committee']['display']['default']['weight'] = 2; /* WAS: 1 */
    $data['node-os2web_meetings_meeting-field_os2web_meetings_committee']['display']['search_index']['type'] = 'taxonomy_term_reference_link'; /* WAS: 'taxonomy_term_reference_plain' */
    $data['node-os2web_meetings_meeting-field_os2web_meetings_committee']['widget']['weight'] = 10; /* WAS: 12 */
  }
  if (isset($data['node-os2web_meetings_meeting-field_os2web_meetings_date'])) {
    $data['node-os2web_meetings_meeting-field_os2web_meetings_date']['display']['default']['settings']['format_type'] = 'meeting_date'; /* WAS: 'ec_date_view' */
    $data['node-os2web_meetings_meeting-field_os2web_meetings_date']['display']['default']['settings']['show_remaining_days'] = 0; /* WAS: FALSE */
    unset($data['node-os2web_meetings_meeting-field_os2web_meetings_date']['display']['default']['settings']['show_repeat_rule']);
  }
  if (isset($data['node-os2web_meetings_meeting-field_os2web_meetings_full_doc'])) {
    $data['node-os2web_meetings_meeting-field_os2web_meetings_full_doc']['display']['default']['weight'] = 5; /* WAS: 4 */
    $data['node-os2web_meetings_meeting-field_os2web_meetings_full_doc']['widget']['weight'] = 8; /* WAS: 10 */
  }
  if (isset($data['node-os2web_meetings_meeting-field_os2web_meetings_location'])) {
    $data['node-os2web_meetings_meeting-field_os2web_meetings_location']['display']['default']['type'] = 'taxonomy_term_reference_link'; /* WAS: 'taxonomy_term_reference_plain' */
    $data['node-os2web_meetings_meeting-field_os2web_meetings_location']['display']['default']['weight'] = 3; /* WAS: 2 */
    $data['node-os2web_meetings_meeting-field_os2web_meetings_location']['display']['search_index']['type'] = 'taxonomy_term_reference_link'; /* WAS: 'taxonomy_term_reference_plain' */
    $data['node-os2web_meetings_meeting-field_os2web_meetings_location']['widget']['weight'] = 11; /* WAS: 13 */
  }
  if (isset($data['node-os2web_meetings_meeting-field_os2web_meetings_searchdata'])) {
    $data['node-os2web_meetings_meeting-field_os2web_meetings_searchdata']['display']['default']['label'] = 'above'; /* WAS: 'hidden' */
    $data['node-os2web_meetings_meeting-field_os2web_meetings_searchdata']['display']['default']['weight'] = 14; /* WAS: 13 */
    $data['node-os2web_meetings_meeting-field_os2web_meetings_searchdata']['display']['search_index']['label'] = 'above'; /* WAS: 'hidden' */
    $data['node-os2web_meetings_meeting-field_os2web_meetings_searchdata']['display']['search_index']['weight'] = 0; /* WAS: 13 */
    $data['node-os2web_meetings_meeting-field_os2web_meetings_searchdata']['widget']['active'] = 0; /* WAS: 1 */
    $data['node-os2web_meetings_meeting-field_os2web_meetings_searchdata']['widget']['weight'] = 14; /* WAS: 31 */
    unset($data['node-os2web_meetings_meeting-field_os2web_meetings_searchdata']['display']['includeable']);
    unset($data['node-os2web_meetings_meeting-field_os2web_meetings_searchdata']['display']['list']);
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
    $data['os2web_meetings']->display['panel_pane_1']->display_options['fields']['field_os2web_meetings_type'] = array(
      'id' => 'field_os2web_meetings_type',
      'table' => 'field_data_field_os2web_meetings_type',
      'field' => 'field_os2web_meetings_type',
      'label' => '',
      'element_label_colon' => FALSE,
    ); /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_2']->display_options['defaults']['fields'] = FALSE; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_2']->display_options['fields'] = array(
      'nid' => array(
        'id' => 'nid',
        'table' => 'node',
        'field' => 'nid',
        'label' => '',
        'exclude' => TRUE,
        'element_label_colon' => FALSE,
      ),
      'title' => array(
        'id' => 'title',
        'table' => 'node',
        'field' => 'title',
        'exclude' => TRUE,
        'alter' => array(
          'path' => 'os2web_meetings_meeting/[nid]',
        ),
      ),
      'field_os2web_meetings_committee' => array(
        'id' => 'field_os2web_meetings_committee',
        'table' => 'field_data_field_os2web_meetings_committee',
        'field' => 'field_os2web_meetings_committee',
        'label' => '',
        'alter' => array(
          'make_link' => TRUE,
          'path' => 'node/[nid]',
        ),
        'element_label_colon' => FALSE,
        'type' => 'taxonomy_term_reference_plain',
      ),
      'field_os2web_meetings_date' => array(
        'id' => 'field_os2web_meetings_date',
        'table' => 'field_data_field_os2web_meetings_date',
        'field' => 'field_os2web_meetings_date',
        'label' => '',
        'alter' => array(
          'make_link' => TRUE,
          'path' => 'node/[nid]',
        ),
        'element_label_colon' => FALSE,
        'settings' => array(
          'format_type' => 'os2web_meetings_short_date',
          'fromto' => 'value',
          'multiple_number' => '',
          'multiple_from' => '',
          'multiple_to' => '',
          'show_repeat_rule' => 'show',
        ),
      ),
    ); /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['defaults']['empty'] = FALSE; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['defaults']['exposed_form'] = FALSE; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['empty'] = array(
      'area' => array(
        'id' => 'area',
        'table' => 'views',
        'field' => 'area',
        'empty' => TRUE,
        'format' => 'filtered_html',
      ),
    ); /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['exposed_form'] = array(
      'type' => 'basic',
      'options' => array(
        'submit_button' => 'Udfør',
        'reset_button' => TRUE,
        'reset_button_label' => 'Nulstil',
        'exposed_sorts_label' => 'Sortér efter',
        'sort_asc_label' => 'Stigende',
        'sort_desc_label' => 'Faldende',
      ),
    ); /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['fields']['field_os2web_meetings_type'] = array(
      'id' => 'field_os2web_meetings_type',
      'table' => 'field_data_field_os2web_meetings_type',
      'field' => 'field_os2web_meetings_type',
      'label' => '',
      'exclude' => TRUE,
      'element_label_colon' => FALSE,
    ); /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_committee_tid']['expose']['remember'] = TRUE; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_committee_tid']['expose']['remember_roles'][1] = 1; /* WAS: 0 */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_committee_tid']['expose']['remember_roles'][10] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_committee_tid']['expose']['remember_roles'][11] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_committee_tid']['expose']['remember_roles'][12] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_committee_tid']['expose']['remember_roles'][13] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_committee_tid']['expose']['remember_roles'][14] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_committee_tid']['expose']['remember_roles'][15] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_committee_tid']['expose']['remember_roles'][16] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_committee_tid']['expose']['remember_roles'][17] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_committee_tid']['expose']['remember_roles'][4] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_committee_tid']['expose']['remember_roles'][5] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_committee_tid']['expose']['remember_roles'][6] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_committee_tid']['expose']['remember_roles'][7] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_committee_tid']['expose']['remember_roles'][8] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_committee_tid']['expose']['remember_roles'][9] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_date_value_1']['default_date'] = '+2 month'; /* WAS: '+14 days' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_date_value_1']['expose']['remember'] = TRUE; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_date_value_1']['expose']['remember_roles'][1] = 1; /* WAS: 0 */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_date_value_1']['expose']['remember_roles'][10] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_date_value_1']['expose']['remember_roles'][11] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_date_value_1']['expose']['remember_roles'][12] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_date_value_1']['expose']['remember_roles'][13] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_date_value_1']['expose']['remember_roles'][14] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_date_value_1']['expose']['remember_roles'][15] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_date_value_1']['expose']['remember_roles'][16] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_date_value_1']['expose']['remember_roles'][17] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_date_value_1']['expose']['remember_roles'][4] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_date_value_1']['expose']['remember_roles'][5] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_date_value_1']['expose']['remember_roles'][6] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_date_value_1']['expose']['remember_roles'][7] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_date_value_1']['expose']['remember_roles'][8] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_date_value_1']['expose']['remember_roles'][9] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_date_value']['default_date'] = '-1 month'; /* WAS: '-12 months' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_date_value']['expose']['remember'] = TRUE; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_date_value']['expose']['remember_roles'][1] = 1; /* WAS: 0 */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_date_value']['expose']['remember_roles'][10] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_date_value']['expose']['remember_roles'][11] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_date_value']['expose']['remember_roles'][12] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_date_value']['expose']['remember_roles'][13] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_date_value']['expose']['remember_roles'][14] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_date_value']['expose']['remember_roles'][15] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_date_value']['expose']['remember_roles'][16] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_date_value']['expose']['remember_roles'][17] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_date_value']['expose']['remember_roles'][4] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_date_value']['expose']['remember_roles'][5] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_date_value']['expose']['remember_roles'][6] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_date_value']['expose']['remember_roles'][7] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_date_value']['expose']['remember_roles'][8] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_date_value']['expose']['remember_roles'][9] = 0; /* WAS: '' */
    $data['os2web_meetings']->display['panel_pane_3']->display_options['filters']['field_os2web_meetings_searchdata_value_1'] = array(
      'id' => 'field_os2web_meetings_searchdata_value_1',
      'table' => 'field_data_field_os2web_meetings_searchdata',
      'field' => 'field_os2web_meetings_searchdata_value',
      'operator' => 'allwords',
      'group' => 1,
      'exposed' => TRUE,
      'expose' => array(
        'operator_id' => 'field_os2web_meetings_searchdata_value_1_op',
        'label' => 'Keyword',
        'operator' => 'field_os2web_meetings_searchdata_value_1_op',
        'identifier' => 'field_os2web_meetings_searchdata_value',
        'remember' => TRUE,
        'remember_roles' => array(
          2 => 2,
          1 => 1,
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
        ),
      ),
    ); /* WAS: '' */
    unset($data['os2web_meetings']->display['panel_pane_1']->display_options['fields']['field_os2web_meetings_committee']['exclude']);
    unset($data['os2web_meetings']->display['panel_pane_1']->display_options['fields']['views_conditional']);
    unset($data['os2web_meetings']->display['panel_pane_3']->display_options['fields']['field_os2web_meetings_committee']['exclude']);
    unset($data['os2web_meetings']->display['panel_pane_3']->display_options['fields']['views_conditional']);
  }
}
