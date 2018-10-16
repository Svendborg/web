<?php
/**
 * @file
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct URL of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *   template_preprocess_node().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type; for example, "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type; for example, story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode; for example, "full", "teaser".
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined; for example, $node->body becomes $body. When needing to
 * access a field's raw values, developers/themers are strongly encouraged to
 * use these variables. Otherwise they will have to explicitly specify the
 * desired field language; for example, $node->body['en'], thus overriding any
 * language negotiation rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php if ((!$page && !empty($title)) || !empty($title_prefix) || !empty($title_suffix) || $display_submitted): ?>
    <header>
      <?php print render($title_prefix); ?>
      <?php if (!$page && !empty($title)): ?>
        <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php if ($display_submitted): ?>
        <span class="submitted">
      <?php print $user_picture; ?>
      <?php print $submitted; ?>
    </span>
      <?php endif; ?>
    </header>
  <?php endif; ?>
  <?php if($page) : ?>
    <header>
      <?php if ($type == 'os2web_base_news' || $type == 'os2web_base_contentpage') : ?>
        <?php if(isset($content['field_os2web_base_field_video'])) : ?>
          <?php hide($content['field_os2web_base_field_lead_img']); ?>
          <?php print render($content['field_os2web_base_field_video']); ?>
        <?php else: ?>
          <?php if ($type == 'os2web_base_news') : ?>
            <?php print render($content['field_os2web_base_field_lead_img']); ?>
          <?php else: ?>
            <?php print render($content['field_os2web_base_field_image']); ?>
          <?php endif; ?>
        <?php endif; ?>
      <?php else : ?>
        <?php print render($content['field_os2web_base_field_image']); ?>
      <?php endif; ?>
      <?php if ($node->type != 'os2web_base_contentpage' &&  $node->type != 'os2web_borger_dk_article' && $node->type != 'borger_dk_article'): ?>
        <time pubdate="pubdate">
          <i></i><?php print format_date($created, 'custom', 'j. F Y'); ?>
        </time>
      <?php endif; ?>
      <?php print render($title_prefix); ?>
      <?php if (!empty($title)): ?>
        <h1<?php print $title_attributes; ?>><?php print $title; ?></h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
    </header>
  <?php endif; ?>

  <div class="wrap">
    <?php
    // Hide comments, tags, and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    hide($content['field_tags']);
    hide($content['field_os2web_base_field_image']);
    hide($content['field_os2web_base_field_lead_img']);
    hide($content['field_svendborg_hide_sidebar']);
    hide($content['field_svendborg_hide_contact']);
    hide($content['field_os2web_base_field_hidlinks']);

    print render($content['field_os2web_base_field_summary']);

    print render($content['body']);

    if(isset($content['field_os2web_base_field_sympage'])) {
      print render($content['field_os2web_base_field_sympage']);
    }

  $content['field_os2web_meetings_full_doc']['#title']= t('Full doc');
  $content['field_os2web_meetings_committee']['#title'] = t('Committee');
  $content['field_os2web_meetings_date']['#title'] = t('Date');
  $content['field_os2web_meetings_location']['#title'] = t('Lokation');
  $content['field_os2web_meetings_type']['#title'] = t('Status');
  hide($content['field_os2web_meetings_bullets']);
  print render($content);
?>
    <div class="borger_dk_body_intro_text">
      <div class='intro_text_buttons'>
        <span>Åben/luk alle</span><a href='#' class='gplus_all gplus_gminus'><span class='gplus_button'>+</span></a>
        <a href='#' class='gminus_all gplus_gminus'><span class='gminus_button'>-</span></a>
     </div>
    </div>  
<?php
  print render($content['field_os2web_meetings_bullets']);

    print $author_node_info;

    ?>

  </div>
  <?php if (!empty($content['field_tags']) || !empty($content['links'])): ?>
    <footer>
      <?php print render($content['field_tags']); ?>
      <?php print render($content['links']); ?>
    </footer>
  <?php endif; ?>
  <?php print render($content['comments']); ?>
</article>

