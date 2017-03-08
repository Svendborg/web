<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <header>
      <?php if(isset($content['field_os2web_base_field_video'])) : ?>
        <?php hide($content['field_os2web_base_field_lead_img']); ?>
        <?php print render($content['field_os2web_base_field_video']); ?>
      <?php else: ?>
        <?php print render($content['field_os2web_base_field_lead_img']); ?>
      <?php endif; ?>
    
    <time pubdate="pubdate">
      <i></i><?php print format_date($created, 'custom', 'j. F Y'); ?>
    </time>
    <?php print render($title_prefix); ?>
    <?php if (!empty($title)): ?>
    <h1<?php print $title_attributes; ?>><?php print $title; ?></h1>
    <?php endif; ?>
    <?php print render($title_suffix); ?>
  </header>

  <div class="wrap">
    <?php
      // Hide comments, tags, and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      hide($content['field_tags']);
      hide($content['field_os2web_base_field_image']);
      hide($content['field_os2web_base_field_lead_img']);
      hide($content['field_svendborg_hide_sidebar']);
      hide($content['field_svendborg_hide_contact']);
      hide($content['field_os2web_base_field_hidlinks']);

      print render($content['field_os2web_base_field_summary']);

      print render($content['body']);
      
      if(isset($content['field_os2web_base_field_sympage'])) {
      print render($content['field_os2web_base_field_sympage']);        
      }

      
      print render($content);

      print $author_node_info;

    ?>

  </div>
  <?php if (!empty($content['field_tags']) || !empty($content['links'])): ?>
  <footer>
    <?php print render($content['field_tags']); ?>
    <?php print render($content['links']); ?>
  </footer>
  <?php endif; ?>

</article>

