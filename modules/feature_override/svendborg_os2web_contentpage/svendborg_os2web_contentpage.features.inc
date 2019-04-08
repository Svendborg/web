<?php
/**
 * @file
 * svendborg_os2web_contentpage.features.inc
 */

/**
 * Implements hook_field_default_field_instances_alter().
 */
function svendborg_os2web_contentpage_field_default_field_instances_alter(&$data) {
  if (isset($data['node-os2web_base_contentpage-field_os2web_base_field_image'])) {
    $data['node-os2web_base_contentpage-field_os2web_base_field_image']['display']['default']['settings']['slideshow_image_style'] = 'svendborg_content_image'; /* WAS: 'fredericia_content_image' */
    $data['node-os2web_base_contentpage-field_os2web_base_field_image']['settings']['epsacrop']['styles']['svendborg_content_image'] = 0; /* WAS: '' */
    $data['node-os2web_base_contentpage-field_os2web_base_field_image']['settings']['epsacrop']['styles']['svendborg_spotbox'] = 0; /* WAS: '' */
    $data['node-os2web_base_contentpage-field_os2web_base_field_image']['settings']['wysiwyg_insert'] = 0; /* WAS: '' */
    $data['node-os2web_base_contentpage-field_os2web_base_field_image']['widget']['settings']['allowed_schemes']['oembed'] = 0; /* WAS: '' */
    $data['node-os2web_base_contentpage-field_os2web_base_field_image']['widget']['settings']['allowed_schemes']['private'] = 0; /* WAS: '' */
    unset($data['node-os2web_base_contentpage-field_os2web_base_field_image']['settings']['epsacrop']['styles']['fredericia_content_image']);
    unset($data['node-os2web_base_contentpage-field_os2web_base_field_image']['settings']['epsacrop']['styles']['fredericia_spotbox']);
    unset($data['node-os2web_base_contentpage-field_os2web_base_field_image']['widget']['settings']['browser_plugins']['youtube']);
    unset($data['node-os2web_base_contentpage-field_os2web_base_field_image']['widget']['settings']['progress_indicator']);
  }
}
