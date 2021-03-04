<!DOCTYPE html>
<!--[if lt IE 7 ]><html class="lt-ie10 lt-ie9 lt-ie8 lt-ie7 no-js" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces; ?>><![endif]-->
<!--[if IE 7 ]><html class="lt-ie10 lt-ie9 lt-ie8 ie7 no-js" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces; ?>><![endif]-->
<!--[if IE 8 ]><html class="lt-ie10 lt-ie9 ie8 no-js" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces; ?>><![endif]-->
<!--[if IE 9 ]><html class="lt-ie10 ie9 no-js" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces; ?>><![endif]-->
<!--[if (gt IE 9)|!(IE)]><!-->
<html class="not-ie no-js" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces; ?>>
<!--<![endif]-->
<head>
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

<script>
    (function() {
        function getCookie(name) {
            var v = document.cookie.match('(^|;) ?' + name + '=([^;]*)(;|$)');

            return v ? v[2] : null;
        }

        function hasAgreed() {
            var cookie = getCookie('cookie-agreed');

            // Cookie doesnt exist.
            if (cookie === null) {
                return false;
            }

            // Cookie exists, but the user didnt agree.
            if (cookie === 0 || cookie === '0' || cookie === '') {
                return false;
            }

            return true;
        }

        function deleteAllCookies() {
            var cookies = document.cookie.split(";");

            for (var i = 0; i < cookies.length; i++) {
                var cookie = cookies[i];
                var eqPos = cookie.indexOf("=");
                var name = eqPos > -1 ? cookie.substr(0, eqPos) : cookie;

                document.cookie = name + "=;expires=Thu, 01 Jan 1970 00:00:00 GMT";
            }
        }

        if (!hasAgreed()) {
            window.setInterval(deleteAllCookies, 1500);
        }
    })();
</script>
</body>
</html>
