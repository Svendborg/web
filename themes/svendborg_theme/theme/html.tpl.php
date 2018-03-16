<?php
/**
 * @file
 * Default theme implementation to display the basic html structure of a single
 * Drupal page.
 *
 * Variables:
 * - $css: An array of CSS files for the current page.
 * - $language: (object) The language the site is being displayed in.
 *   $language->language contains its textual representation.
 *   $language->dir contains the language direction. It will either be 'ltr' or
 *   'rtl'.
 * - $rdf_namespaces: All the RDF namespace prefixes used in the HTML document.
 * - $grddl_profile: A GRDDL profile allowing agents to extract the RDF data.
 * - $head_title: A modified version of the page title, for use in the TITLE
 *   tag.
 * - $head_title_array: (array) An associative array containing the string parts
 *   that were used to generate the $head_title variable, already prepared to be
 *   output as TITLE tag. The key/value pairs may contain one or more of the
 *   following, depending on conditions:
 *   - title: The title of the current page, if any.
 *   - name: The name of the site.
 *   - slogan: The slogan of the site, if any, and if there is no title.
 * - $head: Markup for the HEAD section (including meta tags, keyword tags, and
 *   so on).
 * - $styles: Style tags necessary to import all CSS files for the page.
 * - $scripts: Script tags necessary to load the JavaScript files and settings
 *   for the page.
 * - $page_top: Initial markup from any modules that have altered the
 *   page. This variable should always be output first, before all other dynamic
 *   content.
 * - $page: The rendered page content.
 * - $page_bottom: Final closing markup from any modules that have altered the
 *   page. This variable should always be output last, after all other dynamic
 *   content.
 * - $classes String of classes that can be used to style contextually through
 *   CSS.
 *
 * @see bootstrap_preprocess_html()
 * @see template_preprocess()
 * @see template_preprocess_html()
 * @see template_process()
 *
 * @ingroup themeable
 */
?><!DOCTYPE html>
<!DOCTYPE html>
<!--[if lt IE 7]>
<html class="lt-ie10 lt-ie9 lt-ie8 lt-ie7 no-js" lang="<?php print $language->language; ?>"
      dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces; ?>><![endif]-->
<!--[if IE 7]>
<html class="lt-ie10 lt-ie9 lt-ie8 ie7 no-js" lang="<?php print $language->language; ?>"
      dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces; ?>><![endif]-->
<!--[if IE 8]>
<html class="lt-ie10 lt-ie9 ie8 no-js" lang="<?php print $language->language; ?>"
      dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces; ?>><![endif]-->
<!--[if IE 9]>
<html class="lt-ie10 ie9 no-js" lang="<?php print $language->language; ?>"
      dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces; ?>><![endif]-->
<!--[if (gt IE 9)|!(IE)]>
<html class="not-ie no-js" lang="<?php print $language->language; ?>"
      dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces; ?> xmlns="http://www.w3.org/1999/html"><!--<![endif]-->
<head>

    <title><?php print $head_title; ?></title>
    <meta http-equiv="content-language" content="da,en">
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
    <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1">

    <?php print $head; ?>
    <title><?php print $head_title; ?></title>
    <?php print $styles; ?>
    <!-- HTML5 element support for IE6-8 -->
    <!--[if lt IE 9]>
    <script src="//html5shiv.googlecode.com/svn/trunk/html5.js"></script>
    <![endif]-->
    <?php print $scripts; ?>
</head>
<body class="<?php print $classes; ?>" <?php print $attributes; ?>>
<div id="skip-link">
    <a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
</div>
<?php print $page_top; ?>
<?php print $page; ?>
<?php print $page_bottom; ?>

<script type="text/javascript">
    /*<![CDATA[*/
    (function () {
        var sz = document.createElement('script');
        sz.type = 'text/javascript';
        sz.async = true;
        sz.src = '//ssl.siteimprove.com/js/siteanalyze_273752.js';
        var s = document.getElementsByTagName('script')[0];
        s.parentNode.insertBefore(sz, s);
    })();
    /*]]>*/
</script>

<script>
    (function ($)
    {
        'use strict';

        // A hash is set in the URL
        if (window.location.hash) {
            setTimeout(function () {
                var hash = window.location.hash,
                    $target = $(hash);

                // The hash refers to a panel
                if ($target.length && $target.hasClass('panel', 'collapsible')) {

                    // Let's open the target automatically
                    $target.find('.collapse')
                        .first()
                        .collapse();
                }
            }, 500);
        }

        // setTimeout(function() {
        //     var $panels = $('.panel.collapsible');
        //
        //     // Run through all panels
        //     $panels.each(function (index, element) {
        //         var $element = $(this),
        //             current_url = location.href.replace(window.location.hash, ''),
        //             link = current_url + '#' + $element.attr('id'),
        //             $target_link = $('<a />')
        //                 .addClass('panel-direct-link')
        //                 .attr('href', link)
        //                 .html($('<span />').addClass('icon fa fa-link'));
        //
        //         console.log('Element: ', $element);
        //         console.log('Current URL: ', current_url);
        //         console.log('Link: ', link);
        //         console.log('Target link: ', $target_link);
        //
        //         // Add the link inside the panels body
        //         // $element.find('.panel-body').prepend($target_link);
        //     });
        // }, 1000);
    })(jQuery);
</script>
</body>
</html>
