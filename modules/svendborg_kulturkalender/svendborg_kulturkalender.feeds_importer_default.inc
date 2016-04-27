<?php
/**
 * @file
 * svendborg_kulturkalender.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function svendborg_kulturkalender_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'svendborg_kulturkalender';
  $feeds_importer->config = array(
    'name' => 'Svendborg Kulturkalender',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:7' => '@id',
          'xpathparser:0' => '@id',
          'xpathparser:6' => 'headline',
          'xpathparser:5' => 'subtitle',
          'xpathparser:1' => 'place',
          'xpathparser:2' => 'concat(   substring(     \'http://\',     1,     not(number(       starts-with(link, \'http\')     ))     * number(boolean(string-length(link)))     * 7   ),   link )',
          'xpathparser:3' => 'ticketprice',
          'xpathparser:8' => 'ticketsale',
          'xpathparser:9' => 'dateend',
          'xpathparser:10' => 'datebegin',
          'xpathparser:13' => 'time',
          'xpathparser:11' => 'category',
          'xpathparser:12' => 'category/@id',
        ),
        'rawXML' => array(
          'xpathparser:7' => 0,
          'xpathparser:0' => 0,
          'xpathparser:6' => 0,
          'xpathparser:5' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:8' => 0,
          'xpathparser:9' => 0,
          'xpathparser:10' => 0,
          'xpathparser:13' => 0,
          'xpathparser:11' => 0,
          'xpathparser:12' => 0,
        ),
        'context' => '/events/event',
        'exp' => array(
          'errors' => 0,
          'debug' => array(
            'context' => 0,
            'xpathparser:7' => 0,
            'xpathparser:0' => 0,
            'xpathparser:6' => 0,
            'xpathparser:5' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:8' => 0,
            'xpathparser:9' => 0,
            'xpathparser:10' => 0,
            'xpathparser:13' => 0,
            'xpathparser:11' => 0,
            'xpathparser:12' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '0',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:7',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'xpathparser:0',
            'target' => 'field_kulturkalender_event_id',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:6',
            'target' => 'title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:5',
            'target' => 'body',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:1',
            'target' => 'field_kulturkalender_place',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:2',
            'target' => 'field_kulturkalender_link:url',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:3',
            'target' => 'field_kulturkalender_pris',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'xpathparser:8',
            'target' => 'field_kulturkalender_billet_salg',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'xpathparser:9',
            'target' => 'field_kulturkalender_dato:end',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'xpathparser:10',
            'target' => 'field_kulturkalender_dato:start',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'xpathparser:13',
            'target' => 'field_kulturkalender_time_meta',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'xpathparser:11',
            'target' => 'field_kulturkalender_kategori',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'xpathparser:12',
            'target' => 'field_kulturkalender_kategori_id',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'kulturkalender',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '1800',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['svendborg_kulturkalender'] = $feeds_importer;

  return $export;
}
