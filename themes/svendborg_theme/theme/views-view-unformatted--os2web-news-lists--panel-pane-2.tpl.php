<?php

/**
 * @file
 * Svendborg template for News list panel_pane2. Adds some panel around it.
 *
 * @ingroup views_templates
 */
?>
<div class="panel panel-primary with-arrow">
  <div class="panel-heading">
    <?php if (!empty($title)): ?>
      <h3 class="panel-title"><?php print $title; ?></h3>
    <?php else: ?>
      <h3 class="panel-title"><?php print t('Nyheder og aktuelt'); ?></h3>
    <?php endif; ?>
  </div>
  <div class="panel-body">
    <div class="panel-body-inner">
      <?php foreach ($rows as $id => $row): ?>
        <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
          <?php print $row; ?>
        </div>
      <?php endforeach; ?>
    </div>
  </div>
  <div class="panel-footer no-border">
    <a href="/nyheder" class="btn btn-primary">
      <?php print t('Se alle nyheder her'); ?>
    </a>
  </div>
</div>
