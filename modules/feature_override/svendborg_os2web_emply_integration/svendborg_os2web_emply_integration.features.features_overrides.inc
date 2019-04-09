<?php
/**
 * @file
 * svendborg_os2web_emply_integration.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function svendborg_os2web_emply_integration_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: field_instance
  $overrides["field_instance.taxonomy_term-os2web_job_designs-field_os2web_job_image.display|default|settings|image_style"] = 'svendborg_content_image';
  $overrides["field_instance.taxonomy_term-os2web_job_designs-field_os2web_job_image.settings|epsacrop|styles|fredericia_content_image"]["DELETED"] = TRUE;
  $overrides["field_instance.taxonomy_term-os2web_job_designs-field_os2web_job_image.settings|epsacrop|styles|fredericia_spotbox"]["DELETED"] = TRUE;
  $overrides["field_instance.taxonomy_term-os2web_job_designs-field_os2web_job_image.settings|epsacrop|styles|os2web_gallery_thumbnails"]["DELETED"] = TRUE;
  $overrides["field_instance.taxonomy_term-os2web_job_designs-field_os2web_job_image.settings|epsacrop|styles|svendborg_content_image"] = 0;
  $overrides["field_instance.taxonomy_term-os2web_job_designs-field_os2web_job_image.settings|epsacrop|styles|svendborg_spotbox"] = 0;
  $overrides["field_instance.taxonomy_term-os2web_job_designs-field_os2web_job_image.settings|wysiwyg_insert"] = 0;
  $overrides["field_instance.taxonomy_term-os2web_job_designs-field_os2web_job_image.widget|settings|allowed_schemes|oembed"] = 0;
  $overrides["field_instance.taxonomy_term-os2web_job_designs-field_os2web_job_image.widget|settings|allowed_schemes|private"] = 0;
  $overrides["field_instance.taxonomy_term-os2web_job_designs-field_os2web_job_image.widget|settings|browser_plugins|youtube"]["DELETED"] = TRUE;
  $overrides["field_instance.taxonomy_term-os2web_job_designs-field_os2web_job_image.widget|settings|progress_indicator"]["DELETED"] = TRUE;

  // Exported overrides for: views_view
  $overrides["views_view.job_liste.display|default|display_options|header|area_text_custom|content"] = '<p>Her kan du få et overblik over ledige stillinger i Svendborg Kommune.<br />
          Svendborg Kommune vil gerne gøre det nemt for dig at blive opmærksom på de jobs, som er relevante for dig.</p>';
  $overrides["views_view.job_liste.display|default|display_options|title"] = 'Job i Svendborg Kommune';

 return $overrides;
}
