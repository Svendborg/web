<?php

/**
 * @author: Stanislav Kutasevits, stan@bellcom.dk
 **/
$time_start = microtime(TRUE);
print('==========================' . PHP_EOL);
print('Started svendborg_search_create_os2search_dokuments.php' . PHP_EOL);

$result = db_select('file_managed', 'f')
  ->fields('f', array('fid', 'filename', 'filemime', 'uri'))
  ->condition('f.filemime', 'application/pdf')
  ->execute()
  ->fetchAll();

foreach($result as $file) {
  if (file_exists($file->uri)) {
    print('==========================' . PHP_EOL);
    print 'Checking file ' . $file->filename . ' [' . $file->fid . ']' . PHP_EOL;

    //checking file node exists
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'os2search_dokument')
      ->propertyCondition('status', NODE_PUBLISHED)
      ->fieldCondition('field_os2search_file_ref', 'fid', $file->fid);
    $result = $query->execute();

    if (isset($result['node'])) {
      $nid = reset(array_keys($result['node']));
      print "File node exists [$nid]. Skipping..." . PHP_EOL;
    } else {
      global $user;

      $document_node = new stdClass();
      $document_node->title = $file->filename;
      $document_node->type = 'os2search_dokument';
      node_object_prepare($document_node);
      $document_node->language = LANGUAGE_NONE;
      $document_node->uid = $user->uid;
      $document_node->status = 1;
      $document_node->promote = 0;
      $document_node->comment = 0;
      $file->display = 1;
      $document_node->field_os2search_file_ref['und'][0] = (array) $file;

      node_submit($document_node);
      node_save($document_node);

      print "New node created [" . $document_node->nid ."]" . PHP_EOL;
    }
  }
}

print('==========================' . PHP_EOL);
print('Finished svendborg_search_create_os2search_dokuments.php' . PHP_EOL);
print('Total execution time: ' . (microtime(TRUE) - $time_start) . ' seconds' . PHP_EOL);
print('==========================' . PHP_EOL);