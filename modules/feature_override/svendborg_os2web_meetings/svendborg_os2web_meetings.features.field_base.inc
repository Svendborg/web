<?php
/**
 * @file
 * svendborg_os2web_meetings.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function svendborg_os2web_meetings_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_os2web_meetings_partic'.
  $field_bases['field_os2web_meetings_partic'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_os2web_meetings_partic',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  return $field_bases;
}
