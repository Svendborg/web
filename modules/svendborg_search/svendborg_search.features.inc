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
 * Implements hook_node_info().
 */
function svendborg_search_node_info() {
  $items = array(
    'os2search_dokument' => array(
      'name' => t('OS2Search Dokument'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
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
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [] },
      "index_directly" : 1,
      "cron_limit" : "500",
      "index_name" : { "index" : "svendborg_public", "cluster_id" : "svendborg_public" },
      "collect_index_statistics" : 0,
      "log_only_not_found" : 0,
      "index_statistics_ttl" : "365d",
      "fields" : {
        "attachments_field_os2search_file_ref" : { "type" : "text" },
        "author" : { "type" : "integer", "entity_type" : "user" },
        "body:value" : { "type" : "text" },
        "changed" : { "type" : "date" },
        "field_os2search_file_ref:file" : { "type" : "integer", "entity_type" : "file" },
        "field_os2web_base_field_struct" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_os2web_base_field_struct:parents_all" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "boolean" },
        "title" : { "type" : "text" },
        "type" : { "type" : "string" },
        "url" : { "type" : "uri" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "0",
            "bundles" : {
              "os2web_base_rotating_image" : "os2web_base_rotating_image",
              "os2web_borger_dk_article" : "os2web_borger_dk_article",
              "os2web_base_gallery" : "os2web_base_gallery",
              "os2web_base_contentpage" : "os2web_base_contentpage",
              "os2web_ofir_job" : "os2web_ofir_job",
              "os2web_base_news" : "os2web_base_news",
              "os2search_dokument" : "os2search_dokument",
              "webform" : "webform",
              "os2web_base_iframe" : "os2web_base_iframe"
            }
          }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
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
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_metatag_alter_callback" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : { "field_os2web_base_field_struct:parents_all" : "field_os2web_base_field_struct:parents_all" } }
        }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true } }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : { "title" : true } }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "title" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_porter_stemmer" : {
          "status" : 0,
          "weight" : "35",
          "settings" : { "fields" : { "title" : true }, "exceptions" : "texan=texa" }
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
          "settings" : { "fields" : { "title" : true } }
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
