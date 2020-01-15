<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
?>

<?php
$fc_id = (int) $output;
if ($fc_id) {
  $fc = array_pop(entity_load('field_collection_item', array($fc_id)));
  $fc_title = $fc->field_os2web_paragraph_title['und'][0]['value'];
  if ($node = $fc->hostEntity()) {
    foreach($node->field_os2web_paragraphs['und'] as $key => $value) {
      if ($value['value'] == $fc_id) {
        $delta = ($key == 0)? '' : '--'. (string)($key+1);
      }
    }
    print (l($node->title . ': ' . $fc_title, url(drupal_get_path_alias('node/' . $node->nid ) , array('absolute' => true, 'alias' => true )) . '#bootstrap-panel'.$delta ));
  }
}
?>
