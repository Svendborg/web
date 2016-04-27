<?php if ($page['navigation']): ?>
  <?php print render($page['navigation']); ?>
<?php endif; ?>

<div class='front-main-container-wrapper'>
  <div class='main-container container'>

    <?php print render($page['header']); ?>
    <div class='row'>

      <!-- page--front.tpl.php-->
      <div class="row-no-padding front-buttons col-md-push-1 col-md-10 col-sm-12 col-xs-12">
        <?php module_load_include('module', 'svendborg_views', 'svendborg_views.module'); ?>
        <?php print $page['front_big_menu']; ?>
      </div>

      <div class="front-search-box col-md-push-3 col-md-6 col-sm-push-3 col-sm-6 col-xs-12">
        <?php $block_search_form = module_invoke('search', 'block_view', 'search'); ?>
        <?php print render($block_search_form); ?>
      </div>

      <div class="col-md-push-1 col-md-10 col-xs-12">
        <div id="front-news-branding" class="front-news-branding col-md-12 col-sm-12 col-xs-12 carousel slide" data-ride="carousel">
          <?php print $page['front_large_carousel']; ?>
        </div>
      </div>
    </div>
    <div class="front-seperator-first"></div>
  </div>

  <div class='front-main-container-shadow'></div>
</div>

<div class="lcontainer-fluid clearfix front-s-news">
  <div class="container front-s-news-inner">
    <div class="row">
      <?php print $page['front_small_carousel']; ?>
    </div>
  </div>
</div>

<div class='lcontainer-fluid clearfix front-news-bottom'>
  <div class='container'>
    <div class='front-news-bottom-inner'>
      <div>
        <span>&#216;nsker du at se alle nyheder   <a href='/nyheder' class='btn btn-primary'>Klik her</a></span>
      </div>
    </div>
  </div>
</div>

<?php print render($page['footer']); ?>
