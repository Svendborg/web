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

  // Exported overrides for: views_view
  $overrides["views_view.os2web_news_lists.display|panel_pane_1|display_options|fields|field_os2web_base_field_lead_img|settings|image_style"] = 'svendborg_content_image';
  $overrides["views_view.os2web_news_lists.display|panel_pane_1|display_options|row_options"] = array(
    'image' => 'field_os2web_base_field_lead_img',
    'title' => 'title',
    'description' => '',
  );
  $overrides["views_view.os2web_news_lists.display|panel_pane_1|display_options|row_plugin"] = 'views_bootstrap_carousel_plugin_rows';
  $overrides["views_view.os2web_news_lists.display|panel_pane_1|display_options|style_options"] = array(
    'interval' => 5000,
    'navigation' => 0,
    'indicators' => 1,
    'pause' => 1,
  );
  $overrides["views_view.os2web_news_lists.display|panel_pane_1|display_options|style_plugin"] = 'views_bootstrap_carousel_plugin_style';

 return $overrides;
}
