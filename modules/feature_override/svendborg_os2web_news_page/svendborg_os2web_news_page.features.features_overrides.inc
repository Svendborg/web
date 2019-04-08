<?php
/**
 * @file
 * svendborg_os2web_news_page.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function svendborg_os2web_news_page_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: field_instance
  $overrides["field_instance.node-os2web_base_news-field_os2web_base_field_lead_img.display|default|settings|slideshow_image_style"] = 'svendborg_content_image';

  // Exported overrides for: views_view
  $overrides["views_view.os2web_news_lists.display|panel_pane_1|display_options|fields|field_os2web_base_field_lead_img|settings|image_style"] = 'svendborg_content_image';

 return $overrides;
}
