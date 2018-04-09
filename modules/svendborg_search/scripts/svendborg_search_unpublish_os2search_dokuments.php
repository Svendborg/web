<?php

/**
 * @author: Stanislav Kutasevits, stan@bellcom.dk
 **/
$time_start = microtime(TRUE);
print('==========================' . PHP_EOL);
print('Started svendborg_search_unpublish_os2search_dokuments.php' . PHP_EOL);

$result = db_select('file_managed', 'f')
  ->fields('f', array('fid', 'filename', 'filemime', 'uri'))
  ->condition('f.filemime', 'application/pdf')
  ->execute()
  ->fetchAll();

foreach($result as $file) {
  if (file_exists($file->uri)) {
    print('==========================' . PHP_EOL);
    print 'Checking file ' . $file->filename . ' [' . $file->fid . ']' . PHP_EOL;

    $usages = file_usage_list($file);

    $nids = $usages['file']['node'];

    if (!empty($nids)) {
      $usage_nodes = node_load_multiple(array_keys($nids));

      $unpublish_document_nodes = TRUE;

      // Check if we need to unpublish all os2web_dokument nodes.
      foreach ($usage_nodes as $usage_node) {
        if ($usage_node->type !== 'os2search_dokument' && $usage_node->status == NODE_PUBLISHED) {
          print "File nodes will not be unpublished, because node [$usage_node->nid] references the file and is still published." . PHP_EOL;
          $unpublish_document_nodes = FALSE;
        }
      }

      // Unpublished os2search_dokument nodes.
      if ($unpublish_document_nodes) {
        print "File nodes will be unpublished." . PHP_EOL;
        foreach ($usage_nodes as $usage_node) {
          if ($usage_node->type === 'os2search_dokument' && $usage_node->status == NODE_PUBLISHED) {

            print "Unpublishing os2web_dokument node [$usage_node->nid]." . PHP_EOL;
            $usage_node->status = NODE_NOT_PUBLISHED;
            node_save($usage_node);
            print "DONE Unpublishing os2web_dokument node [$usage_node->nid]." . PHP_EOL;
          }
        }
      }
    }
  }
}

print('==========================' . PHP_EOL);
print('Finished svendborg_search_unpublish_os2search_dokuments.php' . PHP_EOL);
print('Total execution time: ' . (microtime(TRUE) - $time_start) . ' seconds' . PHP_EOL);
print('==========================' . PHP_EOL);