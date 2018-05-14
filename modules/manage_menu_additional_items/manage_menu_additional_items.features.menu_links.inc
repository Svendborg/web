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

  // Exported menu link: management_add-postliste-import:node/add/postliste-import.
  $menu_links['management_add-postliste-import:node/add/postliste-import'] = array(
    'menu_name' => 'management',
    'link_path' => 'node/add/postliste-import',
    'router_path' => 'node/add/postliste-import',
    'link_title' => 'Add Postliste Import',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'management_add-postliste-import:node/add/postliste-import',
      'roles_for_menu' => array(
        'show' => array(
          12 => 12,
        ),
        'hide' => array(),
      ),
      'alter' => TRUE,
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
  t('Add Postliste Import');

  return $menu_links;
}
