<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php print render($title_prefix); ?>
  <?php print render($title_suffix); ?>
  <div class="caption">
  <?php $spotbox_url = (empty($spotbox_url) && isset($variables['elements']['#spotbox_url'])) ? $variables['elements']['#spotbox_url'] : $spotbox_url; ?>
    <?php if(!empty($spotbox_url)) : ?>
      <a href="<?php print $spotbox_url ?>">
    <?php endif; ?>

    <?php if(!empty($content['field_os2web_spotbox_text'])) : ?>
      <h3><?php print render($content['field_os2web_spotbox_text']); ?></h3>
    <?php endif; ?>

    <?php if(!empty($content['field_os2web_spotbox_big_image'])) : ?>
      <?php print render($content['field_os2web_spotbox_big_image']); ?>
    <?php endif; ?>
    <?php print render($content['field_os2web_spotbox_video']); ?>

    <?php if(!empty($spotbox_url)) : ?>
      </a>
    <?php endif; ?>
  </div>

</div> <!-- /.node -->
