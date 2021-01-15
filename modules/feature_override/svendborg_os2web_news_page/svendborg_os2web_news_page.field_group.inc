<?php

/**
 * @file
 * svendborg_os2web_news_page.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function svendborg_os2web_news_page_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_afsnit|node|os2web_base_news|form';
  $field_group->group_name = 'group_afsnit';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_news';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_os2web_base_news_tabs';
  $field_group->data = array(
    'label' => 'Afsnit',
    'weight' => '7',
    'children' => array(
      0 => 'field_os2web_paragraphs',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-afsnit field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_afsnit|node|os2web_base_news|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Afsnit');

  return $field_groups;
}
