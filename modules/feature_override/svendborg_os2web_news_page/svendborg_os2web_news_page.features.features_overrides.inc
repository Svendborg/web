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

  // Exported overrides for: field_base
  $overrides["field_base.field_os2web_base_field_contact.settings|referenceable_types|borger_dk_article"] = 0;
  $overrides["field_base.field_os2web_base_field_contact.settings|referenceable_types|interne_sider"] = 0;
  $overrides["field_base.field_os2web_base_field_contact.settings|referenceable_types|keyboard_shortcut"] = 0;
  $overrides["field_base.field_os2web_base_field_contact.settings|referenceable_types|kontaktblok"]["DELETED"] = TRUE;
  $overrides["field_base.field_os2web_base_field_contact.settings|referenceable_types|os2search_dokument"] = 0;
  $overrides["field_base.field_os2web_base_field_contact.settings|referenceable_types|os2web_acadre_postlists"] = 0;
  $overrides["field_base.field_os2web_base_field_contact.settings|referenceable_types|os2web_meetings_bullet"] = 0;
  $overrides["field_base.field_os2web_base_field_contact.settings|referenceable_types|os2web_meetings_bullet_attach"] = 0;
  $overrides["field_base.field_os2web_base_field_contact.settings|referenceable_types|os2web_meetings_meeting"] = 0;
  $overrides["field_base.field_os2web_base_field_contact.settings|referenceable_types|os2web_ofir_job"] = 0;
  $overrides["field_base.field_os2web_base_field_contact.settings|referenceable_types|postliste_import"] = 0;
  $overrides["field_base.field_os2web_base_field_contact.settings|referenceable_types|spotbokse2"]["DELETED"] = TRUE;

  // Exported overrides for: field_instance
  $overrides["field_instance.node-os2web_base_news-field_os2web_base_field_lead_img.display|default|settings|slideshow_image_style"] = 'svendborg_content_image';
  $overrides["field_instance.node-os2web_base_news-field_os2web_base_field_lead_img.settings|epsacrop|styles|fredericia_content_image"]["DELETED"] = TRUE;
  $overrides["field_instance.node-os2web_base_news-field_os2web_base_field_lead_img.settings|epsacrop|styles|fredericia_spotbox"]["DELETED"] = TRUE;
  $overrides["field_instance.node-os2web_base_news-field_os2web_base_field_lead_img.settings|epsacrop|styles|svendborg_content_image"] = 'svendborg_content_image';
  $overrides["field_instance.node-os2web_base_news-field_os2web_base_field_lead_img.settings|epsacrop|styles|svendborg_spotbox"] = 0;
  $overrides["field_instance.node-os2web_base_news-field_os2web_base_field_lead_img.settings|wysiwyg_insert"] = 0;
  $overrides["field_instance.node-os2web_base_news-field_os2web_base_field_lead_img.widget|settings|allowed_schemes|oembed"] = 0;
  $overrides["field_instance.node-os2web_base_news-field_os2web_base_field_lead_img.widget|settings|allowed_schemes|private"] = 0;
  $overrides["field_instance.node-os2web_base_news-field_os2web_base_field_lead_img.widget|settings|browser_plugins|youtube"]["DELETED"] = TRUE;
  $overrides["field_instance.node-os2web_base_news-field_os2web_base_field_lead_img.widget|settings|progress_indicator"]["DELETED"] = TRUE;
  $overrides["field_instance.node-os2web_base_news-field_os2web_base_hide_contact.display|default|module"]["DELETED"] = TRUE;
  $overrides["field_instance.node-os2web_base_news-field_os2web_base_hide_contact.display|default|type"] = 'hidden';
  $overrides["field_instance.node-os2web_base_news-field_os2web_base_hide_contact.display|default|weight"] = 10;
  $overrides["field_instance.node-os2web_base_news-field_os2web_base_hide_contact.display|spotbox"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-os2web_base_news-field_os2web_base_hide_sidebar.display|default|module"]["DELETED"] = TRUE;
  $overrides["field_instance.node-os2web_base_news-field_os2web_base_hide_sidebar.display|default|type"] = 'hidden';
  $overrides["field_instance.node-os2web_base_news-field_os2web_base_hide_sidebar.display|default|weight"] = 11;
  $overrides["field_instance.node-os2web_base_news-field_os2web_base_hide_sidebar.display|spotbox"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-os2web_base_news-field_os2web_news_date_end.display|default|module"]["DELETED"] = TRUE;
  $overrides["field_instance.node-os2web_base_news-field_os2web_news_date_end.display|default|settings|format_type"]["DELETED"] = TRUE;
  $overrides["field_instance.node-os2web_base_news-field_os2web_news_date_end.display|default|settings|fromto"]["DELETED"] = TRUE;
  $overrides["field_instance.node-os2web_base_news-field_os2web_news_date_end.display|default|settings|multiple_from"]["DELETED"] = TRUE;
  $overrides["field_instance.node-os2web_base_news-field_os2web_news_date_end.display|default|settings|multiple_number"]["DELETED"] = TRUE;
  $overrides["field_instance.node-os2web_base_news-field_os2web_news_date_end.display|default|settings|multiple_to"]["DELETED"] = TRUE;
  $overrides["field_instance.node-os2web_base_news-field_os2web_news_date_end.display|default|type"] = 'hidden';
  $overrides["field_instance.node-os2web_base_news-field_os2web_news_date_end.display|default|weight"] = 9;
  $overrides["field_instance.node-os2web_base_news-field_os2web_news_date_start.display|default|module"]["DELETED"] = TRUE;
  $overrides["field_instance.node-os2web_base_news-field_os2web_news_date_start.display|default|settings|format_type"]["DELETED"] = TRUE;
  $overrides["field_instance.node-os2web_base_news-field_os2web_news_date_start.display|default|settings|fromto"]["DELETED"] = TRUE;
  $overrides["field_instance.node-os2web_base_news-field_os2web_news_date_start.display|default|settings|multiple_from"]["DELETED"] = TRUE;
  $overrides["field_instance.node-os2web_base_news-field_os2web_news_date_start.display|default|settings|multiple_number"]["DELETED"] = TRUE;
  $overrides["field_instance.node-os2web_base_news-field_os2web_news_date_start.display|default|settings|multiple_to"]["DELETED"] = TRUE;
  $overrides["field_instance.node-os2web_base_news-field_os2web_news_date_start.display|default|type"] = 'hidden';
  $overrides["field_instance.node-os2web_base_news-field_os2web_news_date_start.display|default|weight"] = 8;

  // Exported overrides for: views_view
  $overrides["views_view.os2web_news_lists.display|panel_pane_1|display_options|fields|field_os2web_base_field_lead_img|settings|image_style"] = 'svendborg_content_image';
  $overrides["views_view.os2web_news_lists.display|panel_pane_1|display_options|row_options"] = array(
    'image' => 'field_os2web_base_field_lead_img',
    'title' => 'title',
    'description' => '',
  );
  $overrides["views_view.os2web_news_lists.display|panel_pane_1|display_options|row_plugin"] = 'views_bootstrap_carousel_plugin_rows';
  $overrides["views_view.os2web_news_lists.display|panel_pane_1|display_options|style_plugin"] = 'views_bootstrap_carousel_plugin_style';

 return $overrides;
}
