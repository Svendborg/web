<?php

/**
 * @file
 * Default theme implementation for entities.
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The (sanitized) entity label.
 * - $url: Direct url of the current entity if specified.
 * - $page: Flag for the full page state.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-{ENTITY_TYPE}
 *   - {ENTITY_TYPE}-{BUNDLE}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
?>

<?php $entity = $variables['borgerdk_microarticle']; ?>
<div class="microArticle" id="microArtricle<?php print $entity->entity_id; ?>">
  <h2 class="mArticle" id="mArticle<?php print $entity->entity_id; ?>">
    <?php
      $content['title']['#label_display'] = 'hidden';
      print render($content['title']);
    ?>
  </h2>
  <a href="#" class="gplus">+</a>
  <div class="mArticle<?php print $entity->entity_id; ?> mArticle" style="display: none;">
    <?php
      $content['content']['#label_display'] = 'hidden';
      print render($content['content']);
    ?>
  </div>
</div>