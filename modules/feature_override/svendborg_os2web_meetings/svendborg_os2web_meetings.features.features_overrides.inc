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

  // Exported overrides for: field_instance
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
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_bullets.display|default|weight"] = 6;
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_committee.display|default|type"] = 'taxonomy_term_reference_link';
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_committee.display|default|weight"] = 2;
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_date.display|default|settings|show_repeat_rule"]["DELETED"] = TRUE;
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_full_doc.display|default|weight"] = 5;
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_location.display|default|type"] = 'taxonomy_term_reference_link';
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_location.display|default|weight"] = 3;
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_type.display|default|label"] = 'inline';
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_type.display|default|module"] = 'list';
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_type.display|default|type"] = 'list_default';
  $overrides["field_instance.node-os2web_meetings_meeting-field_os2web_meetings_type.display|default|weight"] = 1;

  // Exported overrides for: views_view
  $overrides["views_view.os2web_meetings.display|page|display_options|defaults|use_ajax"] = FALSE;
  $overrides["views_view.os2web_meetings.display|panel_pane_1|display_options|fields|field_os2web_meetings_committee|exclude"]["DELETED"] = TRUE;
  $overrides["views_view.os2web_meetings.display|panel_pane_1|display_options|fields|field_os2web_meetings_type"] = array(
    'id' => 'field_os2web_meetings_type',
    'table' => 'field_data_field_os2web_meetings_type',
    'field' => 'field_os2web_meetings_type',
    'label' => '',
    'element_label_colon' => FALSE,
  );
  $overrides["views_view.os2web_meetings.display|panel_pane_1|display_options|fields|views_conditional"]["DELETED"] = TRUE;
  $overrides["views_view.os2web_meetings.display|panel_pane_2|display_options|link_to_view"] = 0;
  $overrides["views_view.os2web_meetings.display|panel_pane_3|display_options|fields|field_os2web_meetings_committee|exclude"]["DELETED"] = TRUE;
  $overrides["views_view.os2web_meetings.display|panel_pane_3|display_options|fields|field_os2web_meetings_type"] = array(
    'id' => 'field_os2web_meetings_type',
    'table' => 'field_data_field_os2web_meetings_type',
    'field' => 'field_os2web_meetings_type',
    'label' => '',
    'element_label_colon' => FALSE,
  );
  $overrides["views_view.os2web_meetings.display|panel_pane_3|display_options|fields|title|label"] = 'Titel';
  $overrides["views_view.os2web_meetings.display|panel_pane_3|display_options|fields|views_conditional"]["DELETED"] = TRUE;

 return $overrides;
}
