<?php
/**
 * @file
 * svendborg_os2web_emply_integration.features.inc
 */

/**
 * Implements hook_field_default_field_instances_alter().
 */
function svendborg_os2web_emply_integration_field_default_field_instances_alter(&$data) {
  if (isset($data['taxonomy_term-os2web_job_designs-field_os2web_job_image'])) {
    $data['taxonomy_term-os2web_job_designs-field_os2web_job_image']['display']['default']['settings']['image_style'] = 'svendborg_content_image'; /* WAS: '' */
    $data['taxonomy_term-os2web_job_designs-field_os2web_job_image']['settings']['epsacrop']['styles']['svendborg_content_image'] = 0; /* WAS: '' */
    $data['taxonomy_term-os2web_job_designs-field_os2web_job_image']['settings']['epsacrop']['styles']['svendborg_spotbox'] = 0; /* WAS: '' */
    $data['taxonomy_term-os2web_job_designs-field_os2web_job_image']['settings']['wysiwyg_insert'] = 0; /* WAS: '' */
    $data['taxonomy_term-os2web_job_designs-field_os2web_job_image']['widget']['settings']['allowed_schemes']['oembed'] = 0; /* WAS: '' */
    $data['taxonomy_term-os2web_job_designs-field_os2web_job_image']['widget']['settings']['allowed_schemes']['private'] = 0; /* WAS: '' */
    unset($data['taxonomy_term-os2web_job_designs-field_os2web_job_image']['settings']['epsacrop']['styles']['fredericia_content_image']);
    unset($data['taxonomy_term-os2web_job_designs-field_os2web_job_image']['settings']['epsacrop']['styles']['fredericia_spotbox']);
    unset($data['taxonomy_term-os2web_job_designs-field_os2web_job_image']['settings']['epsacrop']['styles']['os2web_gallery_thumbnails']);
    unset($data['taxonomy_term-os2web_job_designs-field_os2web_job_image']['widget']['settings']['browser_plugins']['youtube']);
    unset($data['taxonomy_term-os2web_job_designs-field_os2web_job_image']['widget']['settings']['progress_indicator']);
  }
}

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
