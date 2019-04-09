<?php
/**
 * @file
 * svendborg_os2web_base.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function svendborg_os2web_base_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: field_instance
  $overrides["field_instance.taxonomy_term-os2web_base_tax_site_structure-field_os2web_base_field_image.display|default|settings|image_style"] = 'svendborg_content_image';
  $overrides["field_instance.taxonomy_term-os2web_base_tax_site_structure-field_os2web_base_field_image.settings|epsacrop|styles|fredericia_content_image"]["DELETED"] = TRUE;
  $overrides["field_instance.taxonomy_term-os2web_base_tax_site_structure-field_os2web_base_field_image.settings|epsacrop|styles|fredericia_spotbox"]["DELETED"] = TRUE;
  $overrides["field_instance.taxonomy_term-os2web_base_tax_site_structure-field_os2web_base_field_image.settings|epsacrop|styles|svendborg_content_image"] = 'svendborg_content_image';
  $overrides["field_instance.taxonomy_term-os2web_base_tax_site_structure-field_os2web_base_field_image.settings|epsacrop|styles|svendborg_spotbox"] = 0;
  $overrides["field_instance.taxonomy_term-os2web_base_tax_site_structure-field_os2web_base_field_image.settings|wysiwyg_insert"] = 0;
  $overrides["field_instance.taxonomy_term-os2web_base_tax_site_structure-field_os2web_base_field_image.widget|settings|allowed_schemes|oembed"] = 0;
  $overrides["field_instance.taxonomy_term-os2web_base_tax_site_structure-field_os2web_base_field_image.widget|settings|allowed_schemes|private"] = 0;
  $overrides["field_instance.taxonomy_term-os2web_base_tax_site_structure-field_os2web_base_field_image.widget|settings|browser_plugins|youtube"]["DELETED"] = TRUE;
  $overrides["field_instance.taxonomy_term-os2web_base_tax_site_structure-field_os2web_base_field_image.widget|settings|progress_indicator"]["DELETED"] = TRUE;
  $overrides["field_instance.taxonomy_term-os2web_base_tax_site_structure-field_os2web_base_hide_contact.display|default|module"]["DELETED"] = TRUE;
  $overrides["field_instance.taxonomy_term-os2web_base_tax_site_structure-field_os2web_base_hide_contact.display|default|type"] = 'hidden';
  $overrides["field_instance.taxonomy_term-os2web_base_tax_site_structure-field_os2web_base_hide_contact.display|default|weight"] = 4;
  $overrides["field_instance.taxonomy_term-os2web_base_tax_site_structure-field_os2web_base_hide_sidebar.display|default|module"]["DELETED"] = TRUE;
  $overrides["field_instance.taxonomy_term-os2web_base_tax_site_structure-field_os2web_base_hide_sidebar.display|default|type"] = 'hidden';
  $overrides["field_instance.taxonomy_term-os2web_base_tax_site_structure-field_os2web_base_hide_sidebar.display|default|weight"] = 7;

 return $overrides;
}
