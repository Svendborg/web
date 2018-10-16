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
  $overrides["views_view.os2web_meetings.display|panel_pane_3|display_options|fields|views_conditional"]["DELETED"] = TRUE;

 return $overrides;
}
