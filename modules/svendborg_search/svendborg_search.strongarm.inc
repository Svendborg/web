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
  $strongarm->name = 'date_format_search_api_facetapi_DAY';
  $strongarm->value = 'F j, Y';
  $export['date_format_search_api_facetapi_DAY'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_search_api_facetapi_HOUR';
  $strongarm->value = 'H:__';
  $export['date_format_search_api_facetapi_HOUR'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_search_api_facetapi_MINUTE';
  $strongarm->value = 'H:i';
  $export['date_format_search_api_facetapi_MINUTE'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_search_api_facetapi_MONTH';
  $strongarm->value = 'F Y';
  $export['date_format_search_api_facetapi_MONTH'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_search_api_facetapi_SECOND';
  $strongarm->value = 'H:i:S';
  $export['date_format_search_api_facetapi_SECOND'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_search_api_facetapi_YEAR';
  $strongarm->value = 'Y';
  $export['date_format_search_api_facetapi_YEAR'] = $strongarm;

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
  $strongarm->name = 'field_bundle_settings_node__os2search_dokument';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '40',
        ),
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '30',
        ),
        'redirect' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__os2search_dokument'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_os2search_dokument';
  $strongarm->value = '0';
  $export['language_content_type_os2search_dokument'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_os2search_dokument';
  $strongarm->value = array();
  $export['menu_options_os2search_dokument'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_os2search_dokument';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_os2search_dokument'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_os2search_dokument';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_os2search_dokument'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_os2search_dokument';
  $strongarm->value = '1';
  $export['node_preview_os2search_dokument'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_os2search_dokument';
  $strongarm->value = 0;
  $export['node_submitted_os2search_dokument'] = $strongarm;

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
    'svendborg_public' => array(
      'search_api_views:svendborg_elastic_search:page' => 'search_api_views:svendborg_elastic_search:page',
    ),
  );
  $export['search_api_facets_search_ids'] = $strongarm;

  return $export;
}
