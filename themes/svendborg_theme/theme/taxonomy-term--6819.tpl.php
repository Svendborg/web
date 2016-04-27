<div class="front-main-container-wrapper">

  <div class="row">
    <div class="region region-content col-md-8 col-sm-8 col-xs-12">

      <h1>Nyheder og aktuelt</h1>
      <div  id="nyheder-carousel-large" class="carousel slide" data-ride="carousel">
        <?php
          drupal_add_js(drupal_get_path('theme', 'svendborg_theme') . '/js/jquery.imagesloaded.js');
          print $news_term_branding;
        ?>
      </div>

      <div class="nyheder-seperator"></div>
      <div class="nyheder-content" id="nyheder-content-isotoper">
        <div class="row">
          <?php print $news_term_content; ?>
        </div>
      </div>
    </div>

    <!-- right sidebar -->
    <div class="region region-sidebar-second col-md-4 col-sm-4 col-xs-12">
      <?php print $news_term_right_sidebar; ?>

      <!-- spotboxes.-->
      <div class="">
        <?php if(!empty($os2web_spotboxes)) : ?>
        <div class="os2web_spotboxes col-md-12 col-sm-12 clearfix row-no-padding">
          <div class="row">
            <?php print render($os2web_spotboxes); ?>
          </div>
        </div>
        <?php endif; ?>
      </div>

    </div>
  </div>
</div>
