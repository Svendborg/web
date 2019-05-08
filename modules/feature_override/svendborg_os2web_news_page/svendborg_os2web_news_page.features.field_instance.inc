<?php
/**
 * @file
 * svendborg_os2web_news_page.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function svendborg_os2web_news_page_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'taxonomy_term-os2web_news_page_newstypes-field_os2web_base_field_contact'.
  $field_instances['taxonomy_term-os2web_news_page_newstypes-field_os2web_base_field_contact'] = array(
    'bundle' => 'os2web_news_page_newstypes',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_os2web_base_field_contact',
    'label' => 'Kontaktblok',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'node_reference',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'autocomplete_path' => 'node_reference/autocomplete',
        'size' => 60,
      ),
      'type' => 'node_reference_autocomplete',
      'weight' => 45,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Kontaktblok');

  return $field_instances;
}
