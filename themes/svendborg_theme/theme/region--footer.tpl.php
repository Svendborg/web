<?php
/**
 * @file
 * region--sidebar.tpl.php
 *
 * Default theme implementation to display the "sidebar_first" and
 * "sidebar_second" regions.
 *
 * Available variables:
 * - $content: The content for this region, typically blocks.
 * - $attributes: String of attributes that contain things like classes and ids.
 * - $content_attributes: The attributes used to wrap the content. If empty,
 *   the content will not be wrapped.
 * - $region: The name of the region variable as defined in the theme's .info
 *   file.
 * - $page: The page variables from bootstrap_process_page().
 *
 * Helper variables:
 * - $is_admin: Flags true when the current user is an administrator.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 *
 * @see bootstrap_preprocess_region().
 * @see bootstrap_process_page().
 *
 * @ingroup themeable
 */
?>
  <footer class="region region_footer lcontainer-fluid">
    <div class="lcontainer-fluid clearfix"  id="footer-menu">
      <div class="container footer-menu">
        <div class="row">
      <?php
        $tree = menu_tree_all_data('menu-indholdsmenu', $link = NULL, $max_depth = 3);

        $count = 0;
        foreach ($tree as $key => $menu_item) {
          if (!$menu_item['link']['hidden']) {
            if ($count > 3) {
              continue;
            }
            $path = $alias = drupal_get_path_alias($menu_item['link']['link_path']);
            print "<div class='menu-". $menu_item['link']['mlid']. " footer-indholsdmenu col-xs-12 col-sm-6 col-md-3'>";
print "<h2 class='menu-footer " . $menu_item['link']['link_title']. "'>
            <a title='" . $menu_item['link']['link_title'] . "' href='/". $path ."' class='" . $menu_item['link']['link_title']. "'>" . $menu_item['link']['link_title'] . "</a></h2>";
            if($menu_item['link']['has_children'] && !$menu_item['link']['hidden']) {

              $tree_display =menu_tree_output($menu_item['below']);
              print render($tree_display);
            }
            print "</div>";
            $count += 1;
          }
        }

      ?>
      <?php if ($content_attributes): ?><div<?php print $content_attributes; ?>><?php endif; ?>
      <?php //print $content; ?>
      <?php if ($content_attributes): ?></div><?php endif; ?>
      </div>
      </div>
    </div>
    <!-- footer contacts social-icons -->
    <div class="lcontainer-fluid clearfix" id="footer-contacts">
      <div class="container">
        <div class="row">
        <div class="col-md-3 col-xs-12 col-sm-6 col-md-push-9 col-sm-push-6 social-icons">
          <a href="https://www.facebook.com/Svendborg" title="Svendborg Kommune Facebook" class="footer_fb" target="_blank">facebook</a>
          <a href="http://www.linkedin.com/company/svendborg-kommune" title="Svendborg Kommune Linkedin" class="footer_linkedin" target="_blank">linkedin</a>
          <a href="http://www.youtube.com/user/wwwsvendborgdk" title="Svendborg Kommune Youtube" class="footer_flickr" target="_blank">youtube</a>
        </div>
        <div class="col-md-9 col-sm-6 col-xs-12 col-md-pull-3 col-sm-pull-6">
          <div class='footer-logo'>
            <img id="footer-logo" alt="Svendborg" src="/<?php print drupal_get_path('theme','svendborg_theme'); ?>/images/footer_logo.png" title="<?php print $page['site_name'] ?>" />

          </div>
        </div>
        <div class="col-md-12 col-sm-12 col-xs-12 footer-address">
          <span>Ramsherred 5 ∙ 5700 Svendborg ∙ Telefon 62 23 30 00 ∙ </span>
          <a href="/kontakt" title="Kontakt kommunen">Se kontakt og åbningstider her</a>
        </div>
        </div>
      </div>
    </div>
    <!-- footer bg-image -->
    <div class="lcontainer-fluid clearfix footer-bg-image">
      <img class="" alt="Svendborg" src="/<?php print drupal_get_path('theme','svendborg_theme'); ?>/images/footer_bottom_bg.png" />
    </div>
  </footer>
