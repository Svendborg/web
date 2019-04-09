<?php
/**
 * @file
 * svendborg_os2web_spotbox.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function svendborg_os2web_spotbox_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: field_instance
  $overrides["field_instance.node-os2web_spotbox_box-field_os2web_spotbox_big_image.display|default|settings|image_style"] = 'svendborg_content_image';
  $overrides["field_instance.node-os2web_spotbox_box-field_os2web_spotbox_big_image.display|spotbox|settings|image_style"] = 'os2web_spotbox_image';
  $overrides["field_instance.node-os2web_spotbox_box-field_os2web_spotbox_big_image.settings|epsacrop|styles|fredericia_content_image"]["DELETED"] = TRUE;
  $overrides["field_instance.node-os2web_spotbox_box-field_os2web_spotbox_big_image.settings|epsacrop|styles|fredericia_spotbox"]["DELETED"] = TRUE;
  $overrides["field_instance.node-os2web_spotbox_box-field_os2web_spotbox_big_image.settings|epsacrop|styles|svendborg_content_image"] = 0;
  $overrides["field_instance.node-os2web_spotbox_box-field_os2web_spotbox_big_image.settings|epsacrop|styles|svendborg_spotbox"] = 'svendborg_spotbox';
  $overrides["field_instance.node-os2web_spotbox_box-field_os2web_spotbox_big_image.settings|wysiwyg_insert"] = 0;
  $overrides["field_instance.node-os2web_spotbox_box-field_os2web_spotbox_big_image.widget|settings|allowed_schemes|oembed"] = 0;
  $overrides["field_instance.node-os2web_spotbox_box-field_os2web_spotbox_big_image.widget|settings|allowed_schemes|private"] = 0;
  $overrides["field_instance.node-os2web_spotbox_box-field_os2web_spotbox_big_image.widget|settings|browser_plugins|youtube"]["DELETED"] = TRUE;
  $overrides["field_instance.node-os2web_spotbox_box-field_os2web_spotbox_big_image.widget|settings|progress_indicator"]["DELETED"] = TRUE;

 return $overrides;
}
