<?php

/**
 * @file
 * svendborg_search.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function svendborg_search_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'elasticsearch_connector_get_default_connector';
  $strongarm->value = 'svendborg_public';
  $export['elasticsearch_connector_get_default_connector'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'facetapi:block_cache:search_api@svendborg_public';
  $strongarm->value = -1;
  $export['facetapi:block_cache:search_api@svendborg_public'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_api_attachments_debug';
  $strongarm->value = 1;
  $export['search_api_attachments_debug'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_api_attachments_extracting_servlet_path';
  $strongarm->value = 'update/extract';
  $export['search_api_attachments_extracting_servlet_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_api_attachments_extract_using';
  $strongarm->value = 'pdftotext';
  $export['search_api_attachments_extract_using'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_api_attachments_preserve_cache';
  $strongarm->value = 0;
  $export['search_api_attachments_preserve_cache'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_api_attachments_python_pdf2txt_path';
  $strongarm->value = '/usr/bin';
  $export['search_api_attachments_python_pdf2txt_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_api_attachments_python_pdf2txt_script';
  $strongarm->value = 'pdf2txt';
  $export['search_api_attachments_python_pdf2txt_script'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_api_attachments_tika_jar';
  $strongarm->value = 'tika-app-1.4.jar';
  $export['search_api_attachments_tika_jar'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_api_attachments_tika_path';
  $strongarm->value = '';
  $export['search_api_attachments_tika_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_api_facets_search_ids';
  $strongarm->value = array(
    'svendborg_public' => array(),
    'svendborg_multi_index' => array(
      'search_api_views:svendborg_elastic_search:page' => 'search_api_views:svendborg_elastic_search:page',
    ),
    'svendborg_meeting_index' => array(
      'search_api_views:svendborg_elasticsearch_meetings_search:page' => 'search_api_views:svendborg_elasticsearch_meetings_search:page',
    ),
  );
  $export['search_api_facets_search_ids'] = $strongarm;

  return $export;
}
