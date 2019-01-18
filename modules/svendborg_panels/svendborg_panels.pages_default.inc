<?php
/**
 * @file
 * svendborg_panels.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function svendborg_panels_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'dagsorden_og_referat';
  $page->task = 'page';
  $page->admin_title = 'Dagsorden og referat';
  $page->admin_description = '';
  $page->path = 'dagsorden-og-referat';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => '',
    'name' => 'menu-indholdsmenu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_dagsorden_og_referat__panel';
  $handler->task = 'page';
  $handler->subtask = 'dagsorden_og_referat';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
          1 => 'h__jre',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Centreret',
        'width' => '74.94288147949534',
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      'h__jre' => array(
        'type' => 'region',
        'title' => 'Højre',
        'width' => '25.05711852050466',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'right col-md-3',
        'hide_empty' => 0,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'h__jre' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Møde dagsordener og referater';
  $display->uuid = '712f7edf-4318-4038-b562-392b799dccdf';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_dagsorden_og_referat__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-ac3040e5-0406-4982-9e0c-8f8e86bfbbb3';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'os2web_meetings-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'items_per_page' => '',
    'override_title' => 1,
    'override_title_text' => ' &nbsp;',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'panel',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'ac3040e5-0406-4982-9e0c-8f8e86bfbbb3';
  $display->content['new-ac3040e5-0406-4982-9e0c-8f8e86bfbbb3'] = $pane;
  $display->panels['center'][0] = 'new-ac3040e5-0406-4982-9e0c-8f8e86bfbbb3';
  $pane = new stdClass();
  $pane->pid = 'new-1fce76b6-03cc-4163-b455-f97eb096ae37';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'os2web_meetings-panel_pane_3';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'use_pager' => 1,
    'pager_id' => '0',
    'items_per_page' => '',
    'offset' => '0',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'panel panel-default',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '1fce76b6-03cc-4163-b455-f97eb096ae37';
  $display->content['new-1fce76b6-03cc-4163-b455-f97eb096ae37'] = $pane;
  $display->panels['center'][1] = 'new-1fce76b6-03cc-4163-b455-f97eb096ae37';
  $pane = new stdClass();
  $pane->pid = 'new-40ccf817-b70c-4b02-9e51-29e894b3b20f';
  $pane->panel = 'h__jre';
  $pane->type = 'views_panes';
  $pane->subtype = 'os2web_meetings-panel_pane_2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'items_per_page' => '5',
    'override_title' => 1,
    'override_title_text' => 'Seneste referater',
    'override_title_heading' => 'h3',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'panel panel-primary with-arrow',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '40ccf817-b70c-4b02-9e51-29e894b3b20f';
  $display->content['new-40ccf817-b70c-4b02-9e51-29e894b3b20f'] = $pane;
  $display->panels['h__jre'][0] = 'new-40ccf817-b70c-4b02-9e51-29e894b3b20f';
  $pane = new stdClass();
  $pane->pid = 'new-b73d0dc0-5e2c-4481-af88-85016c3be307';
  $pane->panel = 'h__jre';
  $pane->type = 'block';
  $pane->subtype = 'os2web_subscription-os2web_subscription_form';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'b73d0dc0-5e2c-4481-af88-85016c3be307';
  $display->content['new-b73d0dc0-5e2c-4481-af88-85016c3be307'] = $pane;
  $display->panels['h__jre'][1] = 'new-b73d0dc0-5e2c-4481-af88-85016c3be307';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['dagsorden_og_referat'] = $page;

  return $pages;

}
