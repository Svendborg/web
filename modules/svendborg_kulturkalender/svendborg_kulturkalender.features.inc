<?php
/**
 * @file
 * svendborg_kulturkalender.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function svendborg_kulturkalender_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function svendborg_kulturkalender_node_info() {
  $items = array(
    'kulturkalender' => array(
      'name' => t('Kulturkalender'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  return $items;
}
