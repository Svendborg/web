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
  // Exported field_instance: 'node-os2web_base_news-field_os2web_paragraphs'.
  $field_instances['node-os2web_base_news-field_os2web_paragraphs'] = array(
    'bundle' => 'os2web_base_news',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'field_collection_fieldset',
        'settings' => array(
          'add' => 'Tilføj',
          'collapsed' => 1,
          'collapsible' => 1,
          'delete' => 'Slet',
          'description' => 1,
          'edit' => 'Redigér',
          'legend' => 'field_os2web_paragraph_title',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_fieldset_view',
        'weight' => 4,
      ),
      'spotbox' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_os2web_paragraphs',
    'label' => 'Afsnit',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 68,
    ),
  );

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
  t('Afsnit');
  t('Kontaktblok');

  return $field_instances;
}
