<?php
/**
 * @file
 * svendborg_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function svendborg_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "elasticsearch_connector" && $api == "elasticsearch_connector_defaults") {
    return array("version" => "1");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function svendborg_search_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function svendborg_search_default_search_api_index() {
  $items = array();
  $items['svendborg_public'] = entity_import('search_api_index', '{
    "name" : "Svendborg public",
    "machine_name" : "svendborg_public",
    "description" : null,
    "server" : "svendborg_public",
    "item_type" : "multiple",
    "options" : {
      "datasource" : { "types" : [ "node", "taxonomy_term" ] },
      "index_directly" : 1,
      "cron_limit" : "500",
      "index_name" : { "index" : "svendborg_public", "cluster_id" : "svendborg_public" },
      "collect_index_statistics" : 0,
      "log_only_not_found" : 0,
      "index_statistics_ttl" : "365d",
      "fields" : {
        "bellcom_elasticsearch_multi_index_files" : { "type" : "text", "boost" : "0.1" },
        "node" : { "type" : "integer", "entity_type" : "node" },
        "node:body:value" : { "type" : "text" },
        "node:field_os2search_file_ref:file" : { "type" : "integer", "entity_type" : "file" },
        "node:field_os2web_base_field_edi_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "node:field_os2web_base_field_edi_tags:name" : { "type" : "list\\u003Ctext\\u003E", "boost" : "13.0" },
        "node:field_os2web_base_field_selfserv:field_vist_navn" : { "type" : "list\\u003Ctext\\u003E" },
        "node:field_os2web_base_field_struct:name" : { "type" : "list\\u003Ctext\\u003E", "boost" : "0.8" },
        "node:field_os2web_base_field_summary:value" : { "type" : "text", "boost" : "2.0" },
        "node:field_os2web_base_field_sympage" : { "type" : "integer", "entity_type" : "node" },
        "node:field_os2web_base_field_sympage:body:value" : { "type" : "text" },
        "node:field_os2web_base_field_sympage:field_os2web_base_field_text" : { "type" : "text" },
        "node:field_os2web_base_field_sympage:title" : { "type" : "text" },
        "node:field_os2web_base_field_text" : { "type" : "text", "boost" : "2.0" },
        "node:field_os2web_base_field_webform" : { "type" : "integer", "entity_type" : "node" },
        "node:field_os2web_paragraphs" : {
          "type" : "list\\u003Cinteger\\u003E",
          "entity_type" : "field_collection_item"
        },
        "node:field_os2web_paragraphs:field_os2web_paragraph_ref:body:value" : { "type" : "list\\u003Ctext\\u003E" },
        "node:field_os2web_paragraphs:field_os2web_paragraph_ref:title" : { "type" : "list\\u003Ctext\\u003E" },
        "node:field_os2web_paragraphs:field_os2web_paragraph_title" : { "type" : "list\\u003Ctext\\u003E", "boost" : "3.0" },
        "node:nid" : { "type" : "string" },
        "node:status" : { "type" : "duration" },
        "node:title" : { "type" : "text", "boost" : "5.0" },
        "node:type" : { "type" : "string" },
        "node:vid" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" },
        "taxonomy_term" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "taxonomy_term:description" : { "type" : "text" },
        "taxonomy_term:name" : { "type" : "text", "boost" : "8.0" },
        "taxonomy_term:tid" : { "type" : "integer" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "0",
            "bundles" : {
              "node:os2search_dokument" : "node:os2search_dokument",
              "node:os2web_base_contentpage" : "node:os2web_base_contentpage",
              "node:borger_dk_article" : "node:borger_dk_article",
              "node:os2web_base_news" : "node:os2web_base_news",
              "taxonomy_term:os2web_taxonomies_tax_portal_cat" : "taxonomy_term:os2web_taxonomies_tax_portal_cat",
              "taxonomy_term:os2web_base_tax_site_structure" : "taxonomy_term:os2web_base_tax_site_structure"
            }
          }
        },
        "search_api_attachments_alter_settings" : {
          "status" : 1,
          "weight" : "0",
          "settings" : {
            "excluded_extensions" : "aif art avi bmp gif ico mov oga ogv png psd ra ram rgb flv",
            "number_indexed" : "0",
            "max_file_size" : "0",
            "excluded_private" : 1
          }
        },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "bellcom_elasticsearch_multi_index_files_alter_settings" : {
          "status" : 1,
          "weight" : "0",
          "settings" : {
            "excluded_extensions" : "aif art avi bmp gif ico mov oga ogv png psd ra ram rgb flv",
            "fields_extract" : "field_os2search_file_ref"
          }
        },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : { "node:title" : true } }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "node:title" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : { "node:title" : true } }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "node:title" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "node:title" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_porter_stemmer" : {
          "status" : 0,
          "weight" : "35",
          "settings" : { "fields" : { "node:title" : true }, "exceptions" : "texan=texa" }
        },
        "search_api_elasticsearch_highlighting" : {
          "status" : 1,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "excerpt_fragments" : "3",
            "concatenator" : "...",
            "highlight" : "never"
          }
        },
        "search_api_elasticsearch_prefix_search" : {
          "status" : 0,
          "weight" : "35",
          "settings" : { "fields" : { "node:title" : true } }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "40",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always",
            "highlight_partial" : 0
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function svendborg_search_default_search_api_server() {
  $items = array();
  $items['svendborg_public'] = entity_import('search_api_server', '{
    "name" : "Svendborg public",
    "machine_name" : "svendborg_public",
    "description" : "",
    "class" : "search_api_elasticsearch_connector",
    "options" : { "cluster" : "", "facet_limit" : "10" },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
