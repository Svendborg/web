<?php
/**
 * @file
 * Default theme implementation to display a block.
 *
 * Available variables:
 * - $block->subject: Block title.
 * - $content: Block content.
 * - $block->module: Module that generated the block.
 * - $block->delta: An ID for the block, unique within each module.
 * - $block->region: The block region embedding the current block.
 * - $classes: String of classes that can be used to style contextually through

 * Helper variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $block_zebra: Outputs 'odd' and 'even' dependent on each block region.
 * - $zebra: Same output as $block_zebra but independent of any block region.
 * - $block_id: Counter dependent on each block region.
 * - $id: Same output as $block_id but independent of any block region.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 * - $block_html_id: A valid HTML ID and guaranteed unique.
 *
 * @see bootstrap_preprocess_block()
 * @see template_preprocess()
 * @see template_preprocess_block()
 * @see bootstrap_process_block()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
<section id="<?php print $block_html_id; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php print render($title_prefix); ?>
  <?php if ($title && $block_html_id == "block-views-news-filter-block"): ?>
  <div class="panel panel-primary with-big-arrow">
    <div class="panel-heading">
      <h3 class="panel-title"><?php print $title; ?></h3>
    </div>

 
    <?php if ($block_html_id == "block-views-news-filter-block"): ?>
    <div class="panel-body">
    <?php endif;?>
        <?php print render($title_suffix); ?>
        <?php print $content ?>
    <?php if ($block_html_id == "block-views-news-filter-block"): ?>
    </div>
    <?php endif;?>
  </div>
  <?php else: ?>
  <?php print render($title_suffix); ?>
        <?php print $content ?>
  <?php endif;?>
</section>
