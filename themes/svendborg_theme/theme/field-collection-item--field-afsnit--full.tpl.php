<?php
/**
 * @file
 * Default theme implementation for field collection items.
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The (sanitized) field collection item label.
 * - $url: Direct url of the current entity if specified.
 * - $page: Flag for the full page state.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-field-collection-item
 *   - field-collection-item-{field_name}
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
<?php
if ($content['field_section_enabled']['#items'][0]['value'] <> 0):
?>
  <?php
  $sectionId = str_replace(' ', '_', $title);
  ?>
  <div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <div class="content"<?php print $content_attributes; ?>>
      <h3>
        <?php
        print render($content['field_section_heading']);
        ?>
      </h3>
      <?php
      print render($content['field_section_text']);
      ?>
      <h4>
        <?php
        print render($content['field_section_button_title']);
        ?>
      </h4>

      <?php if (!empty($content['field_section_button_url']['#items'][0]['value'])): ?>
        <a type="button" class="btn btn-primary" href="<?php print($content['field_section_button_url']['#items'][0]['value']) ?>">
          <?php print($content['field_section_button_text']['#items'][0]['value']) ?>
        </a>
      <?php else : ?>
        <!-- Button trigger modal -->
        <button type="button" class="btn btn-primary" data-toggle="modal" data-target="#<?php print($sectionId); ?>">
          <?php print($content['field_section_button_text']['#items'][0]['value']) ?>
        </button>
        <!-- Modal -->
        <div class="modal fade" id="<?php print($sectionId); ?>" tabindex="-1" role="dialog" aria-labelledby="<?php print($sectionId); ?>Label" aria-hidden="true">
          <div class="modal-dialog" role="document">
            <div class="modal-content">
              <div class="modal-header">
                <h3 class="modal-title" id="<?php print($sectionId); ?>Label"><?php print($content['field_section_popup_heading']['#items'][0]['value']) ?></h3>
                <button type="button" class="close" data-dismiss="modal" aria-label="Close">
                  <span aria-hidden="true">&times;</span>
                </button>
              </div>
              <div class="modal-body">
                <?php print render($content['field_section_popup_text']); ?>
              </div>
              <div class="modal-footer">
                <button type="button" class="btn btn-primary" data-dismiss="modal">Close</button>
              </div>
            </div>
          </div>
        </div>
      <?php endif; ?>
    </div>
  </div>
<?php endif; ?>