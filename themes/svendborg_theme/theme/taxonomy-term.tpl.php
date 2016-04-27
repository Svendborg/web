<?php

/**
 * @file
 * Svendborg template ot taxonomy pages.
 *
 * Available variables:
 * - $name: (deprecated) The unsanitized name of the term. Use $term_name
 *   instead.
 * - $content: An array of items for the content of the term (fields and
 *   description). Use render($content) to print them all, or print a subset
 *   such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $term_url: Direct URL of the current term.
 * - $term_name: Name of the current term.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the following:
 *   - taxonomy-term: The current template type, i.e., "theming hook".
 *   - vocabulary-[vocabulary-name]: The vocabulary to which the term belongs to.
 *     For example, if the term is a "Tag" it would result in "vocabulary-tag".
 * - $term_is_top : (svendborg) Boolean wether this term is a top term.
 *
 * Other variables:
 * - $term: Full term object. Contains data that may not be safe.
 * - $view_mode: View mode, e.g. 'full', 'teaser'...
 * - $page: Flag for the full page state.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the term. Increments each time it's output.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * @see template_preprocess()
 * @see template_preprocess_taxonomy_term()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
<article id="taxonomy-term-<?php print $term->tid; ?>" class="<?php print $classes; ?> clearfix">
  <?php
    hide($content['field_svendborg_hide_sidebar']);
    hide($content['field_list_as_spotboks']);
    hide($content['field_os2web_base_field_hidlinks']);
    hide($content['field_alternative_display']);
  ?>
  <?php if (!$page): ?>
    <h1><a href="<?php print $term_url; ?>"><?php print $term_name; ?></a></h1>
  <?php endif; ?>

  <?php if ($page && !$term_is_top) : ?>
  <header>
    <?php if (isset($content['field_os2web_base_field_image'])): ?>
      <?php print render($content['field_os2web_base_field_image']); ?>
    <?php endif; ?>
    <h1 class="page-header"><?php print $term_name; ?></h1>
  </header>

  <?php
    hide($content['os2web_spotbox']);
    hide($content['field_os2web_base_field_spotbox']);
    hide($content['field_list_as_spotboks']);
    hide($content['field_os2web_base_field_selfserv']);
    print "<div class='wrap'>";
    print render($content);
    print "</div>";?>

  <?php endif; ?>
</article>

<?php if($page): ?>
<div class="row">
    <div class="col-md-12 col-sm-12 row-no-padding clearfix">

    <?php if(!$term_display_alternative) :?>
    <?php
      // Get news carousel.
      $view = views_get_view('os2web_news_lists');
      $view->set_display('panel_pane_1');
      $view->set_arguments(array('Branding', 'none', $term_name));
      $view->set_items_per_page(3);
      $view->pre_execute();
      $view->execute();
    ?>
      <?php if (!empty($view->result)) : ?>
      <div class="col-sm-12 col-md-12 extra-bottom-padding">
        <?php print $view->render(); ?>
      </div>
      <?php endif; ?>
    <?php elseif($term_is_top): ?>
    <div class="bg-white content-img-header">
      <header>
        <?php if (isset($content['field_os2web_base_field_image'])): ?>
          <?php print render($content['field_os2web_base_field_image']); ?>
        <?php endif; ?>
      </header>
      <div class="padding-20">
        <h1><?php print $term_name; ?></h1>
        <?php print render($content) ?>
      </div>
    </div>
    <?php endif;?>

    <?php
      // Get Sub terms.
      $view = views_get_view('subtermer');
      $view->set_display('panel_pane_1');
      $view->pre_execute();
      if (!$term_is_top) :
        $view->display_handler->default_display->options['style_options']['row_class'] = 'col-md-6 call-to-action';
      endif;
      $view->execute();
      if (!empty($view->result)) : ?>
    <div class="col-sm-12 col-md-12 bottom-padding">
      <?php print $view->render(); ?>
    </div>
    <?php endif; ?>

    <?php if(!empty($os2web_spotboxes)) : ?>
    <div class="os2web_spotboxes col-md-12 col-sm-12 clearfix">
      <div class="row">
        <?php print render($os2web_spotboxes); ?>
      </div>
    </div>
    <?php endif; ?>
  </div>
</div>

<?php endif; ?>
