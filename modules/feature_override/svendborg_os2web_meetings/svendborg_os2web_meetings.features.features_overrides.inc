<?php
/**
 * @file
 * svendborg_os2web_meetings.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function svendborg_os2web_meetings_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: field_base
  $overrides["field_base.field_os2web_meetings_searchdata.module"] = 'computed_field';
  $overrides["field_base.field_os2web_meetings_searchdata.settings|code"] = 'if (function_exists(\'_svendborg_os2web_meetings_generate_search_data\')) {
    $entity_field[0][\'value\'] = _svendborg_os2web_meetings_generate_search_data($entity);
  } else {
    $entity_field[0][\'value\'] = \'ccc\';
  }';
  $overrides["field_base.field_os2web_meetings_searchdata.settings|database"] = array(
    'data_default' => '',
    'data_index' => 0,
    'data_length' => 32,
    'data_not_NULL' => 0,
    'data_precision' => 10,
    'data_scale' => 2,
    'data_size' => 'normal',
    'data_type' => 'longtext',
  );
  $overrides["field_base.field_os2web_meetings_searchdata.settings|display_format"] = '$display_output = $entity_field_item[\'value\'];';
  $overrides["field_base.field_os2web_meetings_searchdata.settings|recalculate"] = 0;
  $overrides["field_base.field_os2web_meetings_searchdata.settings|store"] = 1;
  $overrides["field_base.field_os2web_meetings_searchdata.type"] = 'computed';

  // Exported overrides for: field_instance
  $overrides["field_instance.node-os2web_meetings_bullet-field_os2web_meetings_enclosures.label"] = 'Enclosures';
  $overrides["field_instance.node-os2web_meetings_bullet-field_os2web_meetings_enclosures.settings|epsacrop"] = array(
    'styles' => array(
      'os2web_spotbox_image' => 0,
      'svendborg_content_image' => 0,
      'svendborg_spotbox' => 0,
    ),
  );
  $overrides["field_instance.node-os2web_meetings_bullet-field_os2web_meetings_enclosures.widget|settings|filefield_sources|filefield_sources|clipboard"] = 0;
  $overrides["field_instance.node-os2web_meetings_bullet-field_os2web_meetings_enclosures.widget|settings|filefield_sources|filefield_sources|plupload"]["DELETED"] = TRUE;
  $overrides["field_instance.node-os2web_meetings_bullet-field_os2web_meetings_enclosures.widget|settings|filefield_sources|filefield_sources|upload"] = 'upload';
  $overrides["field_instance.node-os2web_meetings_bullet-field_os2web_meetings_enclosures.widget|settings|filefield_sources|source_imce"] = array(
    'imce_mode' => 0,
  );
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_addendum.display|default|weight"] = 4;
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_addendum.widget|weight"] = 13;
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_bullets.display|default|weight"] = 6;
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_bullets.widget|weight"] = 12;
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_committee.display|default|type"] = 'taxonomy_term_reference_link';
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_committee.display|default|weight"] = 2;
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_committee.display|search_index|type"] = 'taxonomy_term_reference_link';
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_committee.widget|weight"] = 10;
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_date.display|default|settings|format_type"] = 'meeting_date';
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_date.display|default|settings|show_remaining_days"] = 0;
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_date.display|default|settings|show_repeat_rule"]["DELETED"] = TRUE;
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_full_doc.display|default|weight"] = 5;
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_full_doc.widget|weight"] = 8;
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_location.display|default|type"] = 'taxonomy_term_reference_link';
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_location.display|default|weight"] = 3;
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_location.display|search_index|type"] = 'taxonomy_term_reference_link';
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_location.widget|weight"] = 11;
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_searchdata.default_value"]["DELETED"] = TRUE;
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_searchdata.display|default|label"] = 'above';
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_searchdata.display|default|weight"] = 14;
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_searchdata.display|includeable"]["DELETED"] = TRUE;
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_searchdata.display|list"]["DELETED"] = TRUE;
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_searchdata.display|search_index|label"] = 'above';
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_searchdata.display|search_index|weight"] = 0;
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_searchdata.settings|text_processing"]["DELETED"] = TRUE;
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_searchdata.widget|active"] = 0;
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_searchdata.widget|module"] = 'computed_field';
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_searchdata.widget|settings|rows"]["DELETED"] = TRUE;
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_searchdata.widget|type"] = 'computed';
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_searchdata.widget|weight"] = 14;
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_type.display|default|label"] = 'inline';
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_type.display|default|module"] = NULL;
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_type.display|default|type"] = 'list_default';
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_type.display|default|weight"] = 1;

  // Exported overrides for: views_view
  $overrides["views_view.os2web_meetings.display|panel_pane_1|display_options|fields|field_os2web_meetings_committee|exclude"]["DELETED"] = TRUE;
  $overrides["views_view.os2web_meetings.display|panel_pane_1|display_options|fields|field_os2web_meetings_type"] = array(
    'id' => 'field_os2web_meetings_type',
    'table' => 'field_data_field_os2web_meetings_type',
    'field' => 'field_os2web_meetings_type',
    'label' => '',
    'element_label_colon' => FALSE,
  );
  $overrides["views_view.os2web_meetings.display|panel_pane_1|display_options|fields|views_conditional"]["DELETED"] = TRUE;
  $overrides["views_view.os2web_meetings.display|panel_pane_3|display_options|fields|field_os2web_meetings_committee|exclude"]["DELETED"] = TRUE;
  $overrides["views_view.os2web_meetings.display|panel_pane_3|display_options|fields|field_os2web_meetings_type"] = array(
    'id' => 'field_os2web_meetings_type',
    'table' => 'field_data_field_os2web_meetings_type',
    'field' => 'field_os2web_meetings_type',
    'label' => '',
    'element_label_colon' => FALSE,
  );
  $overrides["views_view.os2web_meetings.display|panel_pane_3|display_options|fields|views_conditional"]["DELETED"] = TRUE;
  $overrides["views_view.os2web_meetings.display|panel_pane_3|display_options|filters|field_os2web_meetings_searchdata_value_1"] = array(
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
      'remember_roles' => array(
        2 => 2,
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
      ),
    ),
  );

 return $overrides;
}
