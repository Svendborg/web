<?php
/**
 * @file
 * svendborg_os2web_spotbox.features.inc
 */

/**
 * Implements hook_field_default_field_instances_alter().
 */
function svendborg_os2web_spotbox_field_default_field_instances_alter(&$data) {
  if (isset($data['node-os2web_spotbox_box-field_os2web_spotbox_big_image'])) {
    $data['node-os2web_spotbox_box-field_os2web_spotbox_big_image']['display']['default']['settings']['image_style'] = 'svendborg_content_image'; /* WAS: 'fredericia_spotbox' */
    $data['node-os2web_spotbox_box-field_os2web_spotbox_big_image']['display']['spotbox']['settings']['image_style'] = 'os2web_spotbox_image'; /* WAS: 'os2web_spotbox_image_300' */
    $data['node-os2web_spotbox_box-field_os2web_spotbox_big_image']['settings']['epsacrop']['styles']['svendborg_content_image'] = 0; /* WAS: '' */
    $data['node-os2web_spotbox_box-field_os2web_spotbox_big_image']['settings']['epsacrop']['styles']['svendborg_spotbox'] = 'svendborg_spotbox'; /* WAS: '' */
    $data['node-os2web_spotbox_box-field_os2web_spotbox_big_image']['settings']['wysiwyg_insert'] = 0; /* WAS: '' */
    $data['node-os2web_spotbox_box-field_os2web_spotbox_big_image']['widget']['settings']['allowed_schemes']['oembed'] = 0; /* WAS: '' */
    $data['node-os2web_spotbox_box-field_os2web_spotbox_big_image']['widget']['settings']['allowed_schemes']['private'] = 0; /* WAS: '' */
    unset($data['node-os2web_spotbox_box-field_os2web_spotbox_big_image']['settings']['epsacrop']['styles']['fredericia_content_image']);
    unset($data['node-os2web_spotbox_box-field_os2web_spotbox_big_image']['settings']['epsacrop']['styles']['fredericia_spotbox']);
    unset($data['node-os2web_spotbox_box-field_os2web_spotbox_big_image']['widget']['settings']['browser_plugins']['youtube']);
    unset($data['node-os2web_spotbox_box-field_os2web_spotbox_big_image']['widget']['settings']['progress_indicator']);
  }
}
