<?php
/**
 * @file
 * template.php
 */

/**
 * Implements template_preprocess_page().
 */
function svendborg_theme_preprocess_page(&$variables) {
  // Remove all Taxonomy auto listings here.
  $term = NULL;
  if (arg(0) == 'taxonomy' && arg(1) == 'term' && is_numeric(arg(2))) {
    $term = taxonomy_term_load(arg(2));
    $term_name = $term->vocabulary_machine_name;
    unset($variables['page']['content']['system_main']['no_content']);
    // There will not be nodes and other normal term content on terms
    // "os2web_base_tax_site_structure" pages.
    if ($term_name == "os2web_base_tax_site_structure") {
      unset($variables['page']['content']['system_main']['nodes']);
      unset($variables['page']['content']['system_main']['pager']);
    }
    else {
      // On Other term pages, there will be a view with nodes.
      $view = views_get_view('taxonomy_term');
      $view->set_display('block_1');
      $view->set_arguments(array(arg(2)));
      $view->set_items_per_page(20);
      $view->pre_execute();
      $view->execute();
      $variables['page']['content']['system_main'] = array(
        '#markup' => '<h1>' . $term->name . '</h1>' . $view->render(),
      );
    }

    // Variable that defines that this term is the top of the hieraki.
    $term_is_top = _svendborg_theme_term_is_top($term->tid);
    // Get wether this is a top term, and provide a variable for the templates.
    $variables['page']['term_is_top'] = $term_is_top;
  }

  $node = NULL;
  if (isset($variables['node']) && !empty($variables['node']->nid)) {
    $node = $variables['node'];
  }
  $sidebar_second_hidden = FALSE;
  $sidebar_first_hidden = FALSE;

  // Get all the nodes selvbetjeningslinks and give them to the template.
  if ($node || $term) {
    $variables['page']['os2web_selfservicelinks'] = os2web_related_links_get_selfservice_links($node, $term);
  }

  // Get borger.dk legislation links and give them to the template.
  if (($node && $item = field_get_items('node', $node, 'field_os2web_borger_dk_legislati'))) {
    $variables['page']['os2web_borger_dk_legislation'] = os2web_related_links_get_borger_dk_links($item);
  }

  // Get all related links to this node.
  // 1. Get all unique related links from the node.
  $related_links = array();
  module_load_include('module', 'os2web_related_links');
  if ($node) {
    $related_links = os2web_related_links_get_links($node, 'node');
  }
  elseif ($term) {
    $related_links = os2web_related_links_get_links($term, 'taxonomy_term');
  }

  // If this is a node with an embedded webform.
  // We need to load it here, in order to get messages loaded.
  if ($node && $webform = field_get_items('node', $node, 'field_os2web_base_field_webform')) {
    $variables['node']->content['os2web_webform'] = array(
      'os2web_webform' => array(
        '#markup' => _svendborg_theme_get_webform($webform[0]['nid']),
      ),
    );
  }

  if (!empty($related_links)) {
    // Provide the related links to the templates.
    $variables['page']['related_links'] = $related_links;
  }

  // When a node's menu link is deaktivated and has no siblings, menu_block is
  // empty, and then sidebar_first are hidden. We want to force the
  // sidebar_first to still be shown.
  $active_trail = menu_get_active_trail();
  $current_trail = end($active_trail);

  if (isset($current_trail['hidden']) && $current_trail['hidden'] && empty($variables['page']['sidebar_first'])) {
    $variables['page']['sidebar_first'] = array(
      '#theme_wrappers' => array('region'),
      '#region' => 'sidebar_first',
      'dummy_content' => array(
        '#markup' => ' ',
      ),
    );
  }

  // Hack to force the sidebar_second to be rendered if we have anything to put
  // in it.
  if (!$sidebar_second_hidden && empty($variables['page']['sidebar_second']) && (!empty($variables['page']['related_links']) || !empty($variables['page']['os2web_selfservicelinks']))) {
    $variables['page']['sidebar_second'] = array(
      '#theme_wrappers' => array('region'),
      '#region' => 'sidebar_second',
      'dummy_content' => array(
        '#markup' => ' ',
      ),
    );
  }

  // On taxonomy pages, add a news list in second sidebar.
  if ($term) {
    $view = views_get_view('os2web_news_lists');
    $view->set_display('panel_pane_2');
    $view->set_arguments(array('all', 'Branding', $term->tid));
    $view->set_items_per_page(3);
    $view->pre_execute();
    $view->execute();
    if (!empty($view->result)) {
      if (empty($variables['page']['sidebar_second'])) {
        $variables['page']['sidebar_second'] = array(
          '#theme_wrappers' => array('region'),
          '#region' => 'sidebar_second',
        );
      }
      $variables['page']['sidebar_second']['os2web_news_lists'] = array('#markup' => $view->render());
    }
    if ($term_is_top && $term->vocabulary_machine_name == "os2web_base_tax_site_structure") {
      $variables['page']['sidebar_first'] = array();
    }
  }

  // Spotbox handling. Find all spotboxes for this node, and add them to
  // content_bottom.
  if (($node && $spotboxes = field_get_items('node', $node, 'field_os2web_base_field_spotbox')) ||
      ($term && !$term_is_top && $spotboxes = field_get_items('taxonomy_term', $term, 'field_os2web_base_field_spotbox'))) {

    if (empty($variables['page']['sidebar_second'])) {
      $spotbox_render = drupal_render(_svendborg_theme_get_spotboxes($spotboxes));
    }
    else {
      $spotbox_render = drupal_render(_svendborg_theme_get_spotboxes($spotboxes, 'col-xs-6 col-sm-6 col-md-6 col-lg-6'));
    }

    $variables['page']['content']['os2web_spotbox'] = array(
      'os2web_spotbox' => array(
        '#markup' => $spotbox_render,
      ),
      '#theme_wrappers' => array('container'),
      '#attributes' => array(
        'class' => array('row', 'spotboxes'),
      ),
    );
  }

  // If node has hidden the sidebar, set content to null.
  if (($node && $hide_sidebar_field = field_get_items('node', $node, 'field_svendborg_hide_sidebar')) ||
      ($term && $hide_sidebar_field = field_get_items('taxonomy_term', $term, 'field_svendborg_hide_sidebar'))) {
    if ($hide_sidebar_field[0]['value']) {
      $variables['page']['sidebar_second'] = array();
      $sidebar_second_hidden = TRUE;
    }
  }

  // Add out fonts from Google Fonts API.
  drupal_add_html_head(array(
    '#tag' => 'link',
    '#attributes' => array(
      'href' => '//fonts.googleapis.com/css?family=Titillium+Web:400,600,700|Open+Sans:400,700',
      'rel' => 'stylesheet',
      'type' => 'text/css',
    ),
  ), 'google_font_svendborg_theme');

  // Add google site verification.
  drupal_add_html_head(
    array(
      '#tag' => 'meta',
      '#type' => 'html_tag',
      '#attributes' => array(
        'name' => 'google-site-verification',
        'content' => 'RERf3yjIX_1JFNkt2dpPZvqH_XeG8eum3P4PHXIpqqM',
      ),
    ),
    'meta_keywords'
  );

  // Pass the theme path to js.
  drupal_add_js('jQuery.extend(Drupal.settings, { "pathToTheme": "' . path_to_theme() . '" });', 'inline');

  if (drupal_is_front_page()) {
    // Frontpage circle menu, see module svendborg_circle_menu.
    $variables['page']['front_big_menu'] = svendborg_circle_menu_get_menu_link_markup();

    // Frontpage large carousel.
    $variables['page']['front_large_carousel'] = _svendborg_theme_get_large_carousel();

    // Frontpage small carousel.
    $variables['page']['front_small_carousel'] = _svendborg_theme_get_front_small_carousel();
  }
}

/**
 * Implements template_preprocess_taxonomy_term().
 */
function svendborg_theme_preprocess_taxonomy_term(&$variables) {

  $term = taxonomy_term_load($variables['tid']);
  $variables['term_display_alternative'] = FALSE;
  // Get wether this is a top term, and provide a variable for the templates.
  $term_is_top = _svendborg_theme_term_is_top($term->tid);
  $variables['term_is_top'] = $term_is_top;

  // Provide the spotboxes to Nyheder page or top terms. These pages does not
  // use the right sidebar so we need them in taxonomy-term.tpl
  if (isset($term->tid) && ($term->tid == 6819 || $term_is_top)) {
    $spotboxes = field_get_items('taxonomy_term', $term, 'field_os2web_base_field_spotbox');
    if ($term->tid == 6819) {
      $variables['theme_hook_suggestions'][] = 'taxonomy_term__' . $term->tid;
      $variables['news_term_branding'] = _svendborg_theme_get_large_carousel();
      $variables['news_term_content'] = _svendborg_theme_get_term_news_content();
      $variables['news_term_right_sidebar'] = _svendborg_theme_get_term_news_filer_and_quicktabs();
      $variables['os2web_spotboxes'] = ($spotboxes) ? _svendborg_theme_get_spotboxes($spotboxes, 'col-xs-6 col-sm-6 col-md-6 col-lg-6') : '';
    }
    else {
      $variables['os2web_spotboxes'] = ($spotboxes) ? _svendborg_theme_get_spotboxes($spotboxes, 'col-xs-6 col-sm-4 col-md-4 col-lg-4') : '';
    }
  }
  if (isset($term->field_alternative_display['und'][0]['value']) &&
        $term->field_alternative_display['und'][0]['value'] == 1) {
    $variables['term_display_alternative'] = TRUE;
  }

}

/**
 * Implements THEME_preprocess_html().
 */
function svendborg_theme_preprocess_html(&$variables) {
  // Add conditional stylesheets for IE.
  drupal_add_css(path_to_theme() . '/css/ie.css', array(
    'group' => CSS_THEME,
    'browsers' => array('IE' => 'lte IE 8', '!IE' => FALSE),
    'preprocess' => FALSE,
    'weight' => 115,
  ));

  if (arg(0) == 'taxonomy' && arg(1) == 'term' && is_numeric(arg(2))) {
    // Add wether the term is top to the classes array.
    $term_is_top = _svendborg_theme_term_is_top(arg(2));

    if ($term_is_top) {
      $variables['classes_array'][] = 'term-is-top';
    }
    else {
      $variables['classes_array'][] = 'term-is-not-top';
    }
  }

  // Setup IE meta tag to force IE rendering mode.
  $meta_ie_render_engine = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'http-equiv' => 'X-UA-Compatible',
      'content' => 'IE=8,IE=Edge,chrome=1',
    ),
    '#weight' => '-99999',
  );
  // Add header meta tag for IE to head.
  drupal_add_html_head($meta_ie_render_engine, 'meta_ie_render_engine');
}
/**
 * Implements hook_preprocess_node().
 */
function svendborg_theme_preprocess_node(&$vars) {

  // Add css class "node--NODETYPE--VIEWMODE" to nodes.
  $vars['classes_array'][] = 'node--' . $vars['type'] . '--' . $vars['view_mode'];

  $term_class = get_the_classes($vars['nid']);
  if ($term_class != '') {
    $vars['classes_array'][] = $vars['top_parent_term'] = $term_class;
  }
  $vars['author_node_info'] = '';
  if (user_is_logged_in()) {
    $vars['author_node_info'] = _svendborg_theme_get_author_view($vars['nid']);
  }
  // Make "node--NODETYPE--VIEWMODE.tpl.php" templates available for nodes.
  $vars['theme_hook_suggestions'][] = 'node__' . $vars['type'] . '__' . $vars['view_mode'];

  // Borger.dk article content display with settings,
  if ($vars['type'] == 'os2web_borger_dk_article') {
    $content_fields = _svendborg_theme_get_borger_dk_content($vars['node']);
    foreach ($content_fields as $type => $value) {
      // If field is disabled to display, set $vars field to empty.
      if (empty($value) || !isset($value)) {
        $vars[$type] = '';
      }
    }
    // Microartilce settings.
    $vars['content_body'] = $content_fields['body'];
    $vars['content_body'] = $content_fields['body'];
  }
}
/**
 * Retrieve the top term tid for node class array.
 */
function get_the_classes($nid) {
  $top_parent_term = '';
  $node = node_load($nid);
  if ($portalkategori = field_get_items('node', $node, 'field_os2web_base_field_struct')) {

    // This will be your top parent term if any was found.
    $parent_terms = taxonomy_get_parents_all($portalkategori[0]['tid']);

    foreach ($parent_terms as $parent) {
      $parent_parents = taxonomy_get_parents_all($parent->tid);
      if ($parent_parents != FALSE) {
        // This is top parent term.
        $top_parent_term = $parent->tid;
      }
    }
  }
  return $top_parent_term;
}
/**
 * Implements theme_breadcrumb().
 *
 * Output breadcrumb as an unorderd list with unique and first/last classes.
 */
function svendborg_theme_breadcrumb($variables) {
  $breadcrumbs = $variables['breadcrumb'];

  if (!empty($breadcrumbs)) {
    // The facets integrate with the breadcrumbs, we don't want this.
    if (arg(0) == 'search' && isset($_GET['f'])) {
      // And since every facet adds a level to the breadcrumb, we do this.
      for ($i = 0; $i < count($_GET['f']); $i++) {
        array_pop($breadcrumbs);
      }
    }

    // Provide a navigational heading to give context for breadcrumb links to
    // screen-reader users. Make the heading invisible with .element-invisible.
    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';
    $crumbs = '<ul class="breadcrumb">';

    foreach ($breadcrumbs as $breadcrumb) {
      $classes = array();
      if ($breadcrumb == reset($breadcrumbs)) {
        $classes[] = 'first';
      }
      if ($breadcrumb == end($breadcrumbs)) {
        $classes[] = 'last';
      }
      if (is_array($breadcrumb)) {
        if (isset($breadcrumb['class'])) {
          $classes = array_merge($classes, $breadcrumb['class']);
        }
        if (isset($breadcrumb['data'])) {
          $breadcrumb = $breadcrumb['data'];
        }
      }
      $crumbs .= '<li class="' . implode(' ', $classes) . '"><i></i>'  . $breadcrumb . '</li>';
    }
    $crumbs .= '</ul>';
    return $crumbs;
  }
}

/**
 * Overrides theme_menu_link().
 *
 * Overrides Bootstrap version. Enables to show active trails childrens.
 */
function svendborg_theme_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';
  if ($element['#below']) {
    // Prevent dropdown functions from being added to management menu so it
    // does not affect the navbar module.
    if (($element['#original_link']['menu_name'] == 'management') && (module_exists('navbar'))) {
      $sub_menu = drupal_render($element['#below']);
    }
    elseif ($element['#original_link']['in_active_trail']) {
      $sub_menu = drupal_render($element['#below']);
    }
    else {
      $element['#attributes']['class'][] = 'has-children';
    }
  }
  // On primary navigation menu, class 'active' is not set on active menu item.
  // @see https://drupal.org/node/1896674
  if (($element['#href'] == $_GET['q'] || ($element['#href'] == '<front>' && drupal_is_front_page())) && (empty($element['#localized_options']['language']))) {
    $element['#attributes']['class'][] = 'active';
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

/**
 * Theme function to output tablinks for classic Quicktabs style tabs.
 *
 * @ingroup themeable
 */
function svendborg_theme_qt_quicktabs_tabset($vars) {
  $variables = array(
    'attributes' => array(
      'class' => 'quicktabs-tabs quicktabs-style-' . $vars['tabset']['#options']['style'],
    ),
    'items' => array(),
  );
  foreach (element_children($vars['tabset']['tablinks']) as $key) {
    $item = array();
    if (is_array($vars['tabset']['tablinks'][$key])) {
      $tab = $vars['tabset']['tablinks'][$key];

      $class = "";
      if ($key == (count($vars['tabset']['tablinks']) - 1)) {
        $class = "last";
      }
      if ($key == $vars['tabset']['#options']['active']) {
        $item['class'] = array('active','tab-' . $key, $class);
      }
      else {
        $item['class'] = array('tab-' . $key, $class);
      }
      $item['data'] = "<div><span>" . drupal_render($tab) . "</span></div>";
      $variables['items'][] = $item;
    }
  }
  return theme('item_list', $variables);
}

/**
 * Implements theme_form_element().
 */
function svendborg_theme_form_element(&$variables) {
  // Because the feeds module, puts the upload filechooser in the form
  // element[#description] it is not shown. As bootstrap tries to put all
  // '#description's in tooltips.
  // This workaround puts the the description from file fields in the field
  // suffix.
  // This should probarbly be fixed in the feeds module, but, until then..
  // @see https://www.drupal.org/node/2308343
  if ($variables['element']['#type'] == 'file' && isset($variables['element']['#description'])) {
    $variables['element']['#field_suffix'] = $variables['element']['#description'];
  }
  return bootstrap_form_element($variables);
}

/**
 * Helper function to get a rendeable array of spotboxes.
 *
 * @param array $spotboxes
 *   Array of spotboxe nodes with nids.
 *
 * @return array
 *   The renderable array.
 */
function _svendborg_theme_get_spotboxes($spotboxes, $classes = 'col-xs-6 col-sm-6 col-md-4 col-lg-4') {
  $spotbox_nids = array();
  foreach ($spotboxes as $spotbox) {
    $spotbox_nids[$spotbox['nid']] = $spotbox['nid'];
  }
  $spotbox_array = os2web_spotbox_render_spotboxes($spotbox_nids, NULL, NULL, NULL, 'svendborg_spotbox');

  foreach ($spotbox_array['node'] as &$spotbox) {
    if (is_array($spotbox)) {
      $spotbox['#prefix'] = '<div class="' . $classes . '">';
      $spotbox['#suffix'] = '</div>';
    }
  }
  return $spotbox_array;
}

/**
 * Helper function to return wether a term is a top term.
 *
 * @param int $term_tid
 *   The term tid.
 *
 * @return bool
 *   If this term is top.
 */
function _svendborg_theme_term_is_top($term_tid) {
  $parent = &drupal_static(__FUNCTION__ . $term_tid);
  if (empty($parent)) {
    $parent = db_query("SELECT parent FROM {taxonomy_term_hierarchy} WHERE tid = :tid", array(':tid' => $term_tid))->fetchField();
  }

  return $parent == 0;
}

/**
 * Overrides file_link, add target= '_blank', file open in a new window.
 */
function svendborg_theme_file_link($variables) {
  $file = $variables['file'];
  $icon_directory = $variables['icon_directory'];
  $url = file_create_url($file->uri);
  $icon = theme('file_icon', array('file' => $file, 'icon_directory' => $icon_directory));
  // Set options as per anchor format described at
  // http://microformats.org/wiki/file-format-examples
  $options = array(
    'attributes' => array(
      'type' => $file->filemime . '; length=' . $file->filesize,
    ),
  );
  // Use the description as the link text if available.
  if (empty($file->description)) {
    $link_text = $file->filename;
  }
  else {
    $link_text = $file->description;
    $options['attributes']['title'] = check_plain($file->filename);
  }
  // Open files of particular mime types in new window.
  $new_window_mimetypes = array('application/pdf','text/plain');
  if (in_array($file->filemime, $new_window_mimetypes)) {
    $options['attributes']['target'] = '_blank';
  }
  return '<span class="file">' . $icon . ' ' . l($link_text, $url, $options) . '</span>';
}

/**
 * Implements theme_file_formatter_table().
 */
function svendborg_theme_file_formatter_table($variables) {
  $header = array(t('Attachment'));
  $rows = array();
  foreach ($variables['items'] as $delta => $item) {
    $rows[] = array(
      theme('file_link', array('file' => (object) $item)),
    );
  }
  return empty($rows) ? '' : theme('table', array('header' => $header, 'rows' => $rows));
}

/**
 * Retrieve large carousel.
 */
function _svendborg_theme_get_large_carousel() {
  $large_carousel = '';
  // Branding news view.
  $view = views_get_view('svendborg_news_view');
  $view->set_arguments(array('branding'));
  if (!drupal_is_front_page()) {
    $filter = $view->get_item('front', 'filter', 'promote');
    $filter['value'] = 1;
    $view->set_item('front', 'filter', 'promote', $filter);
  }
  else {
    $view->set_display('front');
  }
  $view->set_items_per_page(3);
  $view->pre_execute();
  $view->execute();

  $results = $view->result;

  $large_carousel .= '<ol class="carousel-indicators col-md-12 col-sm-12 col-xs-12">';
  foreach ($results as $key => $item) {
    $large_carousel .= '<li data-target="';
    if (drupal_is_front_page()) {
      $large_carousel .= '#front-news-branding" data-slide-to="' . $key . '"';
    }
    else {
      $large_carousel .= '#nyheder-carousel-large" data-slide-to="' . $key . '"';
    }
    if ($key == 0) {
      $large_carousel .= ' class="active"></li>';
    }
    else {
      $large_carousel .= '></li>';
    }
  }
  $large_carousel .= '</ol>';
  $large_carousel .= '<div class="carousel-inner" id="front-carousel-large" >';

  foreach ($results as $key => $item) {
    if ($key == 0) {
      $large_carousel .= '<div class="item active">';
    }
    else {
      $large_carousel .= '<div class="item">';
    }
    $node = node_load($item->nid);
    $img = field_get_items('node', $node, 'field_os2web_base_field_lead_img');
    $image = $img[0];
    image_get_info($image["filename"]);

    $style = 'svendborg_content_image';
    $public_filename = image_style_url($style, $image["uri"]);
    $path = drupal_get_path_alias('node/' . $node->nid);
    $large_carousel .= '<a href="' . $path . '" title="' . $node->title . '">';
    if (drupal_is_front_page()) {
      $classes = 'col-md-7 col-sm-8 col-xs-12';
    }
    else {
      $classes = 'col-md-8 col-sm-12 col-xs-12';
    }
    $large_carousel .= '<div class="row-no-padding ' . $classes;
    if (drupal_is_front_page()) {
      $large_carousel .= ' front-branding-img';
    }
    $large_carousel .= '">';
    $large_carousel .= '<img alt="' . $image["title"] . '" title = "' . $image["title"] . '" src="' . $public_filename . '"/>';
    $large_carousel .= '</div>';
    if (drupal_is_front_page()) {
      $classes = 'col-md-5 col-sm-4 col-xs-12';
    }
    else {
      $classes = 'col-md-4 col-sm-12 col-xs-12';
    }
    $large_carousel .= '<div class="carousel-title ' . $classes . '">';

    $large_carousel .= '<div class="title col-md-12">';
    $large_carousel .= $node->title;
    $large_carousel .= '</div>';

    $large_carousel .= '<div class="col-md-12">';
    $large_carousel .= '<a href="' . $path . '" title="' . $node->title . '" class="btn btn-primary">L&aelig;s mere</a>';
    $large_carousel .= '</div></div>';
    $large_carousel .= '</a>';
    $large_carousel .= '</div>';
  }
  $large_carousel .= '</div>';
  return $large_carousel;
}
/**
 * Retrieve small carousel.
 */
function _svendborg_theme_get_front_small_carousel() {
  $front_small_carousel = '';
  $view = views_get_view('svendborg_news_view');
  $view->set_arguments(array('all'));
  $view->set_display('block_3');
  $view->set_items_per_page(9);
  $view->pre_execute();
  $view->execute();

  $results = $view->result;

  $front_small_carousel .= '<div id="front-carousel-small" class="carousel slide" data-ride="carousel">
                           <ol class="carousel-indicators col-md-12 col-sm-12 col-xs-12">';
  if (count($results) > 0) {
    $front_small_carousel .= '<li data-target="#front-carousel-small" data-slide-to="0" class="active"></li>';
  }
  if (count($results) > 3) {
    $front_small_carousel .= '<li data-target="#front-carousel-small" data-slide-to="1"></li>';
  }
  if (count($results) > 6) {
    $front_small_carousel .= '<li data-target="#front-carousel-small" data-slide-to="2"></li>';
  }

  $front_small_carousel .= '</ol>';

  $front_small_carousel .= '<div class="carousel-inner">';

  $small_news_carousel = array();
  foreach ($results as $key => $item) {
    if ($key < 3) {
      $small_news_carousel[0][] = $item;
    }
    elseif ($key >= 3 && $key <= 5) {
      $small_news_carousel[1][] = $item;
    }
    elseif ($key >= 6) {
      $small_news_carousel[2][] = $item;
    }
  }
  foreach ($small_news_carousel as $key => $items) {
    if ($key == 0) {
      $front_small_carousel .= '<div class="item active">';
    }
    else {
      $front_small_carousel .= '<div class="item">';
    }
    foreach ($items as $i => $item) {
      $node = node_load($item->nid);
      $img = field_get_items('node', $node, 'field_os2web_base_field_lead_img');
      $image = $img[0];
      image_get_info($image["filename"]);

      $style = 'svendborg_content_image';
      $public_filename = image_style_url($style, $image["uri"]);

      $path = drupal_get_path_alias('node/' . $node->nid);
      $front_small_carousel .= '<a href="' . $path . '">';
      $front_small_carousel .= '<div class="col-md-4 col-sm-4 col-xs-12">';
      $front_small_carousel .= '<div class="front-s-news-item front-s-news-item-' . $i . '">';

      $front_small_carousel .= '<div class="front-s-news-item-img">';
      $front_small_carousel .= '<img title = "' . $image["title"] . '" src="' . $public_filename . '"/>';
      $front_small_carousel .= '</div>';

      $front_small_carousel .= '<div class="front-s-news-item-text">';
      $front_small_carousel .= '<div class="bubble"><span>' . $node->title . '</span></div>';
      $front_small_carousel .= '</div>';

      $front_small_carousel .= '</div>';
      $front_small_carousel .= '</div>';
      $front_small_carousel .= '</a>';
    }
    $front_small_carousel .= '</div>';
  }

  $front_small_carousel .= '</div></div>';

  $front_small_carousel .= '<div class="front-seperator"></div>';
  return $front_small_carousel;
}
/**
 * Retrieve the news term filter and quicktabs.
 */
function _svendborg_theme_get_term_news_filer_and_quicktabs() {
  $news_term_right_sidebar = '';
  // Filter.
  $block = block_load('views', 'news_filter-block');
  $output = _block_get_renderable_array(_block_render_blocks(array($block)));
  $news_term_right_sidebar .= drupal_render($output);

  // Menu block.
  $block = block_load('menu_block', '4');
  $output = _block_get_renderable_array(_block_render_blocks(array($block)));
  $news_term_right_sidebar .= drupal_render($output);

  $news_term_right_sidebar .= '<div class="nyheder-seperator"></div>';

  // Quick tabs.
  $news_term_right_sidebar .= ' <div id="svendborg_tabs">';
  $block_tab = block_load('quicktabs', 'nyhed_quicktabs');
  $output = _block_get_renderable_array(_block_render_blocks(array($block_tab)));
  $news_term_right_sidebar .= drupal_render($output);
  $news_term_right_sidebar .= '</div>';

  $news_term_right_sidebar .= '<div class="nyheder-seperator"></div>';

  return $news_term_right_sidebar;

}
/**
 * Retrieve news term content view.
 */
function _svendborg_theme_get_term_news_content() {
  $content = '';
  $view = views_get_view('svendborg_news_view');
  $view->set_display('block');
  $view->set_arguments(array('nyhed', 'all'));
  $view->pre_execute();
  $view->execute();
  $content .= $view->render('block');
  return $content;
}
/**
 * Retrieve author view.
 */
function _svendborg_theme_get_author_view($nid) {
  $content = '';
  $view = views_get_view('redaktoerinfo');
  $view->set_display('block');
  $view->set_arguments(array($nid));
  $view->pre_execute();
  $view->execute();
  $content .= $view->render('block');
  return $content;
}

/**
 * Helper: retrieve os2web_borger_dk_article content.
 */
function _svendborg_theme_get_borger_dk_content($node) {
  $content_field = array();
  if ($node->type == 'os2web_borger_dk_article') {
    $fields = $node->os2web_borger_dk_article['field_settings'];
    // First get admin display settings.
    $admin_display_fields = variable_get('os2web_borger_dk_display');
    $locked_os2web_types = array('field_os2web_borger_dk_borgerurl' => 1);
    // We get admin microarticle display settings.
    $microarticle = variable_get('os2web_borger_dk_microarticle_active', FALSE);
    if ($microarticle) {
      $field_microarticle_settings = $node->os2web_borger_dk_microarticle['field_microarticle_settings'];
    }

    foreach ($admin_display_fields as $type => $value) {
      if ($type == 'title' || $type == 'field_os2web_base_field_selfserv') {
        continue;
      }
      $item = field_get_items('node', $node, $type);
      // If ADMIN set this field to display.

      if ($admin_display_fields[$type]) {
        $arr = $item[0];

        if ($item && $type != 'title' && $type != 'field_os2web_borger_dk_image') {
          $content_field[$type] = $item['0']['value'];
        }
        elseif ($item && $type == 'field_os2web_borger_dk_image') {
          $filepath = $item['0']['uri'];
          $alt = $item['0']['alt'];
          $content_field[$type] = theme('image', array(
                                                       'path' => $filepath,
                                                       'alt' => $alt,
                                                       'title' => $alt));
        }
        else {
          $content_field[$type] = '';
        }
        // Microarticles : if microarticle is set up to show by admin.
        if ($microarticle && $type == 'body') {
          // Check if content field is body and field_microarticle_settings
          // is NOT empty.
          // The field_microarticle_setting will be empty when a new
          // article is imported and shown in a form, then node_view
          // will display full body text.
          if (!empty($field_microarticle_settings)) {
            $body_text = $node->body['und']['0']['value'];

            $article_text = '';

            $doc = new DOMDocument();
            $doc->loadHTML('<?xml encoding="utf-8" ?>' . $body_text);
            $xpath = new DOMXPath($doc);

            $results = $xpath->query("//*[@class='microArticle']");

            $microno = 0;
            foreach ($results as $item) {
              foreach ($item->getElementsByTagName('h2') as $articletitle) {
                $title = trim($articletitle->nodeValue);
              }

              $text = '';
              foreach ($item->getElementsByTagName('div')->item(0)->childNodes as $articletext) {
                $text .= $doc->saveHTML($articletext);
              }
              $microno++;

              if ($field_microarticle_settings[$microno] != 0) {
                // Body text (Article text).
                $article_text .= "<div class=\"microArticle\" id=\"microArticle" . $microno . "\">" . "\r\n";

                $micro_h2 = "<h2 class=\"mArticle\" id=\"mArticle" . $microno . "\">";
                $micro_h2 .= $title . "</h2>";

                $micro_content = "<div class=\"mArticle" . $microno . " mArticle\">";
                $micro_content .= $text . "\r\n    </div>";

                $article_text .= $micro_h2 . "\r\n";
                $article_text .= $micro_content;
                $article_text .= "\r\n</div>\r\n\r\n";
              }
            }
            $article_text = str_replace("</h2>", "</h2><a href='#' class='gplus'>+</a>", $article_text);
            // Content body shows only visible microarticles/ part of body_text.
            $content_field['body'] = $article_text;
          }
          else {
            $show_div = $item['0']['value'];
            $show_div = str_replace("</h2>", "</h2><a href='#' class='gplus'>+</a>", $show_div);
            $content_field['body'] = $show_div;
          }
        }
        elseif (!$microarticle && $type == 'body') {
          $show_div = $item['0']['value'];
          $show_div = str_replace("</h2>", "</h2><a href='#' class='gplus'>+</a>", $show_div);
          $content_field['body'] = $show_div;
        }

        // End of microarticles.
        // If EDITOR set this field to be hidden.
        if ($fields[$type] == '0') {
          $content_field[$type] = '';
        }
      }

      // If ADMIN set this field to be hidden.
      else {
        $content_field[$type] = '';
      }
    }
  }
  return $content_field;
}

/**
 * Helper. Returns almost the same as render(node_view()) for a webform.
 *
 * Instead of a fully loaded render array, though, it returns markup, without
 * too many wrappers and such.
 */
function _svendborg_theme_get_webform($nid) {
  $webform_node = node_load($nid);

  $submission = (object) array();
  $enabled = TRUE;
  $preview = FALSE;
  $webform_id = 'webform_client_form_' . $nid;

  $form = drupal_get_form($webform_id, $webform_node, $submission, $enabled, $preview);

  $text = '<h3>' . $webform_node->title . '</h3>';

  if ($body = field_get_items('node', $webform_node, 'body')) {
    $text .= $body[0]['safe_value'];
  }

  return $text . drupal_render($form);
}
