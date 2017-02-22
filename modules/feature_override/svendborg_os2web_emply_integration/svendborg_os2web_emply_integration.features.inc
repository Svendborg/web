<?php
/**
 * @file
 * svendborg_os2web_emply_integration.features.inc
 */

/**
 * Implements hook_views_default_views_alter().
 */
function svendborg_os2web_emply_integration_views_default_views_alter(&$data) {
  if (isset($data['job_liste'])) {
    $data['job_liste']->display['default']->display_options['header']['area_text_custom']['content'] = '<p>Her kan du få et overblik over ledige stillinger i Svendborg Kommune.<br />
    Svendborg Kommune vil gerne gøre det nemt for dig at blive opmærksom på de jobs, som er relevante for dig.</p>'; /* WAS: '<p>Her kan du få et overblik over ledige stillinger i Fredericia Kommune.<br />
    Fredericia Kommune vil gerne gøre det nemt for dig at blive opmærksom på de jobs, som er relevante for dig.</p>' */
    $data['job_liste']->display['default']->display_options['title'] = 'Job i Svendborg Kommune'; /* WAS: 'Job i Fredericia Kommune' */
  }
}
