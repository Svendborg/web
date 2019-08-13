<?php

/**
 * @file
 * svendborg_os2web_contentpage.features.inc
 */

/**
 * Implements hook_field_default_field_bases_alter().
 */
function svendborg_os2web_contentpage_field_default_field_bases_alter(&$data) {
  if (isset($data['field_svendborg_hide_sidebar'])) {
    unset($data['field_svendborg_hide_sidebar']['foreign keys']);
  }
}

/**
 * Implements hook_field_default_field_instances_alter().
 */
function svendborg_os2web_contentpage_field_default_field_instances_alter(&$data) {
  if (isset($data['node-os2web_base_contentpage-field_os2web_base_field_image'])) {
    $data['node-os2web_base_contentpage-field_os2web_base_field_image']['display']['default']['settings']['slideshow_image_style'] = 'svendborg_content_image'; /* WAS: 'fredericia_content_image' */
    $data['node-os2web_base_contentpage-field_os2web_base_field_image']['display']['includeable'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-os2web_base_contentpage-field_os2web_base_field_image']['settings']['epsacrop']['styles']['svendborg_content_image'] = 'svendborg_content_image'; /* WAS: '' */
    $data['node-os2web_base_contentpage-field_os2web_base_field_image']['settings']['epsacrop']['styles']['svendborg_spotbox'] = 0; /* WAS: '' */
    $data['node-os2web_base_contentpage-field_os2web_base_field_image']['settings']['wysiwyg_insert'] = 0; /* WAS: '' */
    $data['node-os2web_base_contentpage-field_os2web_base_field_image']['widget']['settings']['allowed_schemes']['oembed'] = 0; /* WAS: '' */
    $data['node-os2web_base_contentpage-field_os2web_base_field_image']['widget']['settings']['allowed_schemes']['private'] = 0; /* WAS: '' */
    unset($data['node-os2web_base_contentpage-field_os2web_base_field_image']['settings']['epsacrop']['styles']['fredericia_content_image']);
    unset($data['node-os2web_base_contentpage-field_os2web_base_field_image']['settings']['epsacrop']['styles']['fredericia_spotbox']);
    unset($data['node-os2web_base_contentpage-field_os2web_base_field_image']['widget']['settings']['browser_plugins']['youtube']);
    unset($data['node-os2web_base_contentpage-field_os2web_base_field_image']['widget']['settings']['progress_indicator']);
  }
  if (isset($data['node-os2web_base_contentpage-field_os2web_base_hide_contact'])) {
    $data['node-os2web_base_contentpage-field_os2web_base_hide_contact']['display']['default']['type'] = 'hidden'; /* WAS: 'list_default' */
    $data['node-os2web_base_contentpage-field_os2web_base_hide_contact']['display']['default']['weight'] = 11; /* WAS: 23 */
    $data['node-os2web_base_contentpage-field_os2web_base_hide_contact']['display']['includeable'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-os2web_base_contentpage-field_os2web_base_hide_contact']['display']['spotbox'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    unset($data['node-os2web_base_contentpage-field_os2web_base_hide_contact']['display']['default']['module']);
  }
  if (isset($data['node-os2web_base_contentpage-field_os2web_base_hide_sidebar'])) {
    $data['node-os2web_base_contentpage-field_os2web_base_hide_sidebar']['display']['default']['type'] = 'hidden'; /* WAS: 'list_default' */
    $data['node-os2web_base_contentpage-field_os2web_base_hide_sidebar']['display']['default']['weight'] = 10; /* WAS: 22 */
    $data['node-os2web_base_contentpage-field_os2web_base_hide_sidebar']['display']['includeable'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-os2web_base_contentpage-field_os2web_base_hide_sidebar']['display']['spotbox'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    unset($data['node-os2web_base_contentpage-field_os2web_base_hide_sidebar']['display']['default']['module']);
  }
  if (isset($data['node-os2web_base_contentpage-field_svendborg_hide_sidebar'])) {
    $data['node-os2web_base_contentpage-field_svendborg_hide_sidebar']['display']['default']['weight'] = 11; /* WAS: 6 */
    $data['node-os2web_base_contentpage-field_svendborg_hide_sidebar']['display']['includeable'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 11,
    ); /* WAS: '' */
  }
}
