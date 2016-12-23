<?php
/**
 * @file
 * os2web_borger_dk.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function os2web_borger_dk_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create os2web_borger_dk_article content'.
  $permissions['create os2web_borger_dk_article content'] = array(
    'name' => 'create os2web_borger_dk_article content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Editor' => 'Editor',
      'Kommunikation' => 'Kommunikation',
      'Webmaster' => 'Webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any os2web_borger_dk_article content'.
  $permissions['delete any os2web_borger_dk_article content'] = array(
    'name' => 'delete any os2web_borger_dk_article content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Editor' => 'Editor',
      'Webmaster' => 'Webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own os2web_borger_dk_article content'.
  $permissions['delete own os2web_borger_dk_article content'] = array(
    'name' => 'delete own os2web_borger_dk_article content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Editor' => 'Editor',
      'Kommunikation' => 'Kommunikation',
      'Webmaster' => 'Webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any os2web_borger_dk_article content'.
  $permissions['edit any os2web_borger_dk_article content'] = array(
    'name' => 'edit any os2web_borger_dk_article content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Editor' => 'Editor',
      'Webmaster' => 'Webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own os2web_borger_dk_article content'.
  $permissions['edit own os2web_borger_dk_article content'] = array(
    'name' => 'edit own os2web_borger_dk_article content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Editor' => 'Editor',
      'Kommunikation' => 'Kommunikation',
      'Webmaster' => 'Webmaster',
    ),
    'module' => 'node',
  );

  return $permissions;
}
