<?php
/**
 * @file
 * manage_menu_additional_items.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function manage_menu_additional_items_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_postliste-import:import/os2web_postlister.
  $menu_links['management_postliste-import:import/os2web_postlister'] = array(
    'menu_name' => 'management',
    'link_path' => 'import/os2web_postlister',
    'router_path' => 'import/%',
    'link_title' => 'Postliste Import',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'management_postliste-import:import/os2web_postlister',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Postliste Import');

  return $menu_links;
}
