<?php if($content): ?>
<div class="header_svendborg">
    <div id="top_menu">
        <div class="container">
            <div class="row">
              <?php
              $tree = menu_tree_all_data('menu-top-navigation-venstre', $link = NULL, $max_depth = 2);
              if ($tree) {
              print "<div class='menu-top-navigation-venstre col-md-3 col-sm-3 col-xs-3'>";
              menu_tree_trim_active_path($tree);
              $tree_display = menu_tree_output($tree);
              print render($tree_display);
              print "</div>";
              }
              $tree_1 = menu_tree_all_data('menu-top-navigation-hoejre', $link = NULL, $max_depth = 2);
              if ($tree_1) {
              print "<div class='menu-top-navigation-hoejre col-md-9 col-sm-9 col-xs-9'>";
              menu_tree_trim_active_path($tree_1);
              $tree_display = menu_tree_output($tree_1);
              print render($tree_display);
              print "</div>";
              }
              ?>
            </div>
        </div>
    </div>
    <header class="region region-navigation header_fixed container">
        <div class="row">
          <?php if ($content_attributes): ?>
            <div class="header_fixed_inner navbar-default"><?php endif; ?>
                <div id="fixed-navbar">
                    <div class="navbar-header col-md-3 col-sm-3 col-xs-12">

                      <?php if ($content): ?>
                        <button type="button" class="navbar-toggle"
                                data-toggle="collapse"
                                data-target=".navbar-collapse">
                            <span class="sr-only"><?php print t('Toggle navigation'); ?></span>
                            <span class="icon-bar"></span>
                            <span class="icon-bar"></span>
                            <span class="icon-bar"></span>
                        </button>
                      <?php endif; ?>
                    </div>
                  <?php if ($content): ?>
                    <div class="col-md-9 col-sm-9 col-xs-12 navbar-collapse collapse navbar-default header_main_menu">

                        <nav role="navigation">
                          <?php if ($is_front) {
                          $menu_classes = "col-md-11 col-sm-11 col-xs-12";
                          $search_classes = "col-md-1 col-sm-1 col-xs-12";
                          }
                          else {
                          $menu_classes = "col-md-9 col-sm-8 col-xs-12";
                          $search_classes = "col-md-3 col-sm-4 col-xs-12";
                          }
                          ?>
                            <div class="<?php print $search_classes; ?> search_box">
                              <?php print $content; ?>
                            </div>
                        </nav>
                    </div>

                  <?php endif; ?>

    <?php if ($content_attributes): ?></div><?php endif; ?>
            </div>
        </div>
    </header>
</div>
<?php endif; ?>
