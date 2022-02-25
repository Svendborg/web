<article id="node-<?php print $node->nid; ?>" class="<?php print $classes . " all"; ?> smallteaser clearfix"<?php print $attributes; ?> date-filter="<?php if (isset($top_parent_term)) print $top_parent_term ?>">
  <?php if (!$page) : ?>
    <?php 
      $nyhedstype       =    field_get_items('node', $node, 'field_os2web_news_page_type'); 
      $nyhedstypevalgt  =    $nyhedstype[0];
      
      if ($nyhedstypevalgt['tid'] !== '6977') :
          if (isset($content['field_os2web_base_field_lead_img'])) : ?>
                <div class="front-s-news-item-img">
                  <?php
                    $img = field_get_items('node', $node, 'field_os2web_base_field_lead_img');
                    $image = $img[0];
                    $style = 'svendborg_content_image';
                    $public_filename = image_style_url($style, $image["uri"]);
                    $path = drupal_get_path_alias('node/' . $node->nid);
                    print '<a href="/' . $path . '" alt="' . $node->title . '">';
                    print $html = '<img title = "' . $image["title"] . '" src="' . $public_filename . '"/></a>';
                  ?>
                </div>
        <?php endif;
      endif; ?>
      
          <div class="front-s-news-item-text clearfix row">
            <div class="col-md-2 col-sm-3 col-xs-2">
               <div class="news-text-date">
                 <span class="news-date-day"><?php print date('j', $created); ?></span>
                 <span class="news-date-month"><?php $m = date('M', $created); print t($m);?></span>
               </div>
            </div>

            <div class="col-md-10 col-sm-9 col-xs-9 row">
                  <div>
                    <a class="news-title node-title" href="<?php global $base_url; print $base_url . $node_url; ?>"><?php print $node->title; ?></a>
                  </div>
                  <div>
                      <p><?php print render($content['field_os2web_base_field_summary']); ?></p>
                  </div>
            </div>

      </div>
  <?php endif; ?>

  <?php
    // Hide comments, tags, and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    hide($content['field_tags']);
    hide($content['field_os2web_base_field_image']);
    hide($content['field_os2web_base_field_lead_img']);
  ?>

  <?php if (!empty($content['field_tags']) || !empty($content['links'])): ?>
    <?php hide($content['field_tags']); ?>
    <?php hide($content['links']); ?>
  <?php endif; ?>
  <?php hide($content['comments']); ?>
</article>
