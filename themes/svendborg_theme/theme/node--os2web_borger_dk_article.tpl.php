
<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php print render($title_prefix); ?>

  <div id='region-content' class="content"<?php print $content_attributes; ?>>

    <?php
      if ($node->type == 'os2web_borger_dk_article') {
        drupal_add_js(drupal_get_path('module', 'os2web_borger_dk') . '/js/os2web_borger_dk.js', 'file');
        drupal_add_css(drupal_get_path('module', 'os2web_borger_dk') . '/css/os2web_borger_dk.css', 'file');
      }
    ?>

    <?php print render($content['field_os2web_borger_dk_image']);?>

    <header>
      <h1<?php print $title_attributes; ?>>
        <?php print $node->title; ?>
      </h1>
    </header>
    <div class="wrap">
      <?php print render($title_suffix); ?>
      <div class='borger_dk-region-div3'>
        <?php if (isset($content['field_os2web_borger_dk_header'])): ?>
          <div class='borger_dk_header_text field-item' id='borger_dk_header_text'>
            <?php print render($content['field_os2web_borger_dk_header']); ?>
          </div>
        <?php endif; ?>
      </div>

      <div class="content clearfix"<?php print $content_attributes; ?>>
        <?php if (isset($content['field_os2web_borger_dk_pre_text'])): ?>
          <div class='borger_dk-field_os2web-borger-dk-pre_text'>
            <?php print render($content['field_os2web_borger_dk_pre_text']); ?>
          </div>
        <?php endif; ?>

        <div class='panel-separator'></div>

        <?php if (isset($content['body'])): ?>
          <div class='borger_dk-body node-body inner' id='borger_dk-body'>
            <div class='borger_dk_body_intro_text'>
              <span class='intro_text_text'>Læs om <?php print $node->title; ?></span>
              <div class='intro_text_buttons'>
                <span>Åben/luk alle</span><a href='#' class='gplus_all gplus_gminus'><span class='gplus_button'>+</span></a>
                <a href='#' class='gminus_all gplus_gminus'><span class='gminus_button'>-</span></a>
              </div>
            </div>
            <?php if (isset($content_body)): ?>
              <?php print render($content_body); ?>
            <?php endif; ?>
          </div>
        <?php endif; ?>

        <div class='panel-separator'></div>

        <?php if (isset($content['field_os2web_borger_dk_post_text'])): ?>
          <div class='borger_dk-field_os2web-borger-dk-post_text'>
            <?php print render($content['field_os2web_borger_dk_post_text']); ?>
          </div>
        <?php endif; ?>

        <div class='panel-separator'></div>

        <?php if (isset($content['field_os2web_borger_dk_shortlist'])): ?>
          <div class='borger_dk-field_os2web-borger-dk-shortlist'>
            <?php print render($content['field_os2web_borger_dk_shortlist']); ?>
          </div>
        <?php endif; ?>

        <div class='panel-separator'></div>

        <?php if (isset($content['field_os2web_borger_dk_byline'])): ?>
          <div class='borger_dk-field_os2web-borger-dk-byline'>
            <?php print render($content['field_os2web_borger_dk_byline']); ?>
          </div>
        <?php endif; ?>

      </div>

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
