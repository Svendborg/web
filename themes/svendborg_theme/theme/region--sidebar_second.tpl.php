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
 * - $selfservices: Any selfservice links provided from the current node.
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
<?php if ($content): ?>
  <aside<?php print $attributes; ?>>
    <?php if(!empty($page['page']['os2web_selfservicelinks']) && (!isset($page['page']['term_is_top']) || $page['page']['term_is_top'] == FALSE)) : ?>
      <div class="panel panel-default with-arrow">
        <div class="panel-heading">
          <h3 class="panel-title"><?php print t('Selvbetjeningslinks'); ?></h3>
        </div>
        <div class="panel-body">
          <ul class='nav'>
          <?php foreach ($page['page']['os2web_selfservicelinks'] as $link) : ?>
            <li>
              <a href="<?php print $link['url']; ?>"><?php print $link['title']; ?></a>
            </li>
          <?php endforeach; ?>
         </ul>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($page['page']['os2web_borger_dk_legislation'])): ?>
      <div class="panel panel-primary with-arrow">
        <div class="panel-heading">
          <h3 class="panel-title"><?php print t('Hvad siger loven'); ?></h3>
        </div>
        <div class="panel-body">
          <ul class="nav">
          <?php foreach ($page['page']['os2web_borger_dk_legislation'] as $link) : ?>
            <li>
              <a href="<?php print $link['url']; ?>"><?php print $link['title']; ?></a>
            </li>
          <?php endforeach; ?>
         </ul>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($page['page']['related_links'])) : ?>
      <div class="panel panel-primary with-arrow">
        <div class="panel-heading">
          <h3 class="panel-title"><?php print t('Læs også'); ?></h3>
        </div>
        <div class="panel-body">
          <ul class="nav">
          <?php foreach ($page['page']['related_links'] as $link) : ?>
            <li>
              <?php if (isset($link['url'])): ?>
                <?php print l($link['title'], $link['url'], array('attributes' => array('class' => $link['class']))); ?>
              <?php else: ?>
                <?php print l($link['title'], drupal_get_path_alias('node/' . $link['nid']), array('attributes' => array('class' => $link['class']))); ?>
              <?php endif; ?>
            </li>
          <?php endforeach; ?>
         </ul>
        </div>
      </div>
    <?php endif; ?>

    <?php if ($content_attributes): ?><div<?php print $content_attributes; ?>><?php endif; ?>
    <?php print $content; ?>
    <?php if ($content_attributes): ?></div><?php endif; ?>
  </aside>
<?php endif; ?>
