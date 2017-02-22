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

  // Exported overrides for: views_view
  $overrides["views_view.job_liste.display|default|display_options|header|area_text_custom|content"] = '<p>Her kan du få et overblik over ledige stillinger i Svendborg Kommune.<br />
  Svendborg Kommune vil gerne gøre det nemt for dig at blive opmærksom på de jobs, som er relevante for dig.</p>';
  $overrides["views_view.job_liste.display|default|display_options|title"] = 'Job i Svendborg Kommune';

 return $overrides;
}
