<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php print render($title_prefix); ?>

  <div id='region-content' class="content"<?php print $content_attributes; ?>>

    <?php
    if ($node->type == 'borger_dk_article') {
      drupal_add_js(drupal_get_path('module', 'bellcom_borgerdk_migrate') . '/js/os2web_borger_dk.js', 'file');
      drupal_add_css(drupal_get_path('module', 'bellcom_borgerdk_migrate') . '/css/os2web_borger_dk.css', 'file');
    }
    ?>

    <?php print render($content['field_borger_dk_image']); ?>

    <header>
      <h1<?php print $title_attributes; ?>>
        <?php print $node->title; ?>
      </h1>
    </header>
    <div class="wrap">
      <?php print render($title_suffix); ?>
      <?php print render($content['field_borger_dk_article_ref']); ?>

      <div class='panel-separator'></div>

      <?php if (isset($content['field_borger_dk_shortlist'])): ?>
        <div class='borger_dk-field_os2web-borger-dk-shortlist'>
          <?php print render($content['field_borger_dk_shortlist']); ?>
        </div>
      <?php endif; ?>

      <?php print $author_node_info; ?>
    </div>

    <?php
    // Only display the wrapper div if there are links.
    $links = render($content['links']);
    if ($links):
      ?>
      <div class="link-wrapper">
        <?php print $links; ?>
      </div>
    <?php endif; ?>

    <?php print render($content['comments']); ?>
  </div>
</article>
