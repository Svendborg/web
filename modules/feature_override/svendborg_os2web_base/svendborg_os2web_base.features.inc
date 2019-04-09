<?php
/**
 * @file
 * svendborg_os2web_base.features.inc
 */

/**
 * Implements hook_field_default_field_instances_alter().
 */
function svendborg_os2web_base_field_default_field_instances_alter(&$data) {
  if (isset($data['taxonomy_term-os2web_base_tax_site_structure-field_os2web_base_field_image'])) {
    $data['taxonomy_term-os2web_base_tax_site_structure-field_os2web_base_field_image']['display']['default']['settings']['image_style'] = 'svendborg_content_image'; /* WAS: 'fredericia_content_image' */
    $data['taxonomy_term-os2web_base_tax_site_structure-field_os2web_base_field_image']['settings']['epsacrop']['styles']['svendborg_content_image'] = 0; /* WAS: '' */
    $data['taxonomy_term-os2web_base_tax_site_structure-field_os2web_base_field_image']['settings']['epsacrop']['styles']['svendborg_spotbox'] = 0; /* WAS: '' */
    $data['taxonomy_term-os2web_base_tax_site_structure-field_os2web_base_field_image']['settings']['wysiwyg_insert'] = 0; /* WAS: '' */
    $data['taxonomy_term-os2web_base_tax_site_structure-field_os2web_base_field_image']['widget']['settings']['allowed_schemes']['oembed'] = 0; /* WAS: '' */
    $data['taxonomy_term-os2web_base_tax_site_structure-field_os2web_base_field_image']['widget']['settings']['allowed_schemes']['private'] = 0; /* WAS: '' */
    unset($data['taxonomy_term-os2web_base_tax_site_structure-field_os2web_base_field_image']['settings']['epsacrop']['styles']['fredericia_content_image']);
    unset($data['taxonomy_term-os2web_base_tax_site_structure-field_os2web_base_field_image']['settings']['epsacrop']['styles']['fredericia_spotbox']);
    unset($data['taxonomy_term-os2web_base_tax_site_structure-field_os2web_base_field_image']['widget']['settings']['browser_plugins']['youtube']);
    unset($data['taxonomy_term-os2web_base_tax_site_structure-field_os2web_base_field_image']['widget']['settings']['progress_indicator']);
  }
  if (isset($data['taxonomy_term-os2web_base_tax_site_structure-field_os2web_base_hide_contact'])) {
    $data['taxonomy_term-os2web_base_tax_site_structure-field_os2web_base_hide_contact']['display']['default']['type'] = 'hidden'; /* WAS: 'list_default' */
    $data['taxonomy_term-os2web_base_tax_site_structure-field_os2web_base_hide_contact']['display']['default']['weight'] = 4; /* WAS: 9 */
    unset($data['taxonomy_term-os2web_base_tax_site_structure-field_os2web_base_hide_contact']['display']['default']['module']);
  }
  if (isset($data['taxonomy_term-os2web_base_tax_site_structure-field_os2web_base_hide_sidebar'])) {
    $data['taxonomy_term-os2web_base_tax_site_structure-field_os2web_base_hide_sidebar']['display']['default']['type'] = 'hidden'; /* WAS: 'list_default' */
    $data['taxonomy_term-os2web_base_tax_site_structure-field_os2web_base_hide_sidebar']['display']['default']['weight'] = 7; /* WAS: 8 */
    unset($data['taxonomy_term-os2web_base_tax_site_structure-field_os2web_base_hide_sidebar']['display']['default']['module']);
  }
}
