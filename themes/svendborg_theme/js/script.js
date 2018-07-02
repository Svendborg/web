(function ($) {
    $(document).ready(function () {
        var button = 'filter-all';
        var button_class = "btn-primary";
        var button_normal = "btn-blacknblue";
        var $container = $("#nyheder-content-isotoper .view-content");
        check_button(button);

        function check_button(button) {
            $('.filter-link').removeClass(button_class);
            $('.filter-link').addClass(button_normal);
            $('#' + button).addClass(button_class);
            $('#' + button).removeClass(button_normal);
        }

        // filter buttons.
        $('.filter-link').click(function (event) {
            $(this).addClass(button_class);
            button = $(this).attr('id');
            check_button(button);
            var filterValue = $(this).attr('data-filter');
            jQuery.get("/aktulet_news/ajax/view/" + filterValue + '/' + 20, function (data) {
                $('#nyheder-content-isotoper').html(data);
                load_content();
            });
        });

        $container = $("#nyheder-content-isotoper .view-content");

        // Initial masonry
        if ($container.length) {
            load_content();
        }

        function load_content() {
            $container = $("#nyheder-content-isotoper .view-content");

            $container.imagesLoaded(function () {

                $container.masonry({
                    columnWidth: '.switch-elements',
                });

                $container.infinitescroll({
                        state: {
                            currPage: 0
                        },
                        // selector for the paged navigation
                        navSelector: '.pagination',
                        // selector for the NEXT link (to page 2)
                        nextSelector: '.pagination li.next a',
                        // selector for all items you'll retrieve
                        itemSelector: '.switch-elements',
                        loading: {
                            //finishedMsg: 'Der er ikke flere.',
                            //img: 'http://i.imgur.com/qkKy8.gif'
                        },
                        debug: false,
                    },
                    function (newElements) {
                        var $newElems = $(newElements).hide();
                        $newElems.imagesLoaded(function () {
                            $newElems.fadeIn(); // fade in when ready
                            $container.masonry('appended', $newElems);
                            Drupal.attachBehaviors();
                        });
                        /*setTimeout(function() {
                          $container.masonry( 'insert', $newElems);
                        }, 500);*/
                    }
                );
            });
        }


        // Navbar scroll
        $(window).bind('scroll', function () {
            var navHeight = $(window).height();
            if ($(window).scrollTop() > 41 && $(window).width() > 768) {
                $('.header_svendborg header').addClass('navbar-fixed-top');
                $('.header_fixed_inner').addClass('container');
                $('.header_svendborg header').removeClass('container');
                $('.main-container').css('padding-top', '114px');
                $('#fixed-navbar').addClass('row');
                $('img#front-logo').attr('src', Drupal.settings.basePath + Drupal.settings.pathToTheme + '/images/svendborg_logo.png');
            }
            else {
                $('.header_svendborg header').removeClass('navbar-fixed-top');
                $('.header_fixed_inner').removeClass('container');
                $('.header_svendborg header').addClass('container');
                $('.main-container').css('padding-top', '0');
                $('#fixed-navbar').removeClass('row');
                $('img#front-logo').attr('src', Drupal.settings.basePath + Drupal.settings.pathToTheme + '/images/footer_logo.png');
            }
        });

        // front nav header search_form button
        $(".front .region-navigation.container #search-block-form button").click(function () {
            $(".main-container .front-search-box input").focus();

            return false;
        });
        $(".front .region-navigation.container #views-exposed-form-svendborg-elastic-search-panel-pane-menu button").click(function () {
            $(".main-container .front-search-box input").focus();

            return false;
        });

        $('#feedback-submit').addClass('btn-primary');

        var links = $('.region-content a');
        $(links).each(function () {
            if (!$(this).attr('href') && $(this).attr('id') && $(this).attr('id') !== 'main-content') {
                $(this).addClass('link_here');
            }
        });
    });

    // Collapsible panel behaviour
    Drupal.behaviors.collapsible_panel = {
        attach: function (context) {
            $(".collapsible-panel .collapsible-panel-title").click(function () {
                var content = $(this).siblings('.collapsible-panel-content');
                var style = $(content).css('display');
                if (style == 'none') {
                    content.show("500");
                    var alink = $(this).parent().find("a.gplus");
                    alink.addClass('gminus');
                    alink.removeClass('gplus');
                }
                else {
                    content.hide("500");
                    var alink = $(this).parent().find("a.gminus");
                    alink.addClass('gplus');
                    alink.removeClass('gminus');
                }
            });

            // borger.dk articles
            $(".collapsible-panel a.gplus").click(function () {
                var panel_title = $(this).parent().find('.collapsible-panel-title');
                var content = $(panel_title).siblings('.collapsible-panel-content');
                var style = $(content).css('display');

                var button = this;

                if (style == 'none') {
                    content.show("500", function () {
                        $(button).addClass('gminus');
                        $(button).removeClass('gplus test');
                    });
                }
                else {
                    content.hide("500", function () {
                        $(button).addClass('gplus');
                        $(button).removeClass('gminus');
                    });
                }
                return false;
            });

            $(".gplus_all").click(function () {
                $("div.collapsible-panel-content").show();
                $(".collapsible-panel a.gplus").addClass('gminus');
                $(".collapsible-panel a.gplus").removeClass('gplus');

                return false;
            });
            $(".gminus_all").click(function () {
                $("div.collapsible-panel-content").hide();
                $(".collapsible-panel a.gminus").addClass('gplus');
                $(".collapsible-panel a.gminus").removeClass('gminus');

                return false;
            });
        }
    }

    Drupal.behaviors.feedbackForm = {
        attach: function (context) {
            $('#block-feedback-form').addClass('hidden-xs');
            $('#block-feedback-form', context).once('feedback', function () {
                var $block = $(this);
                $block.find('span.feedback-link')
                    .prepend('<span id="feedback-form-toggle">[ + ]</span> ')
                    .css('cursor', 'pointer')
                    .toggle(function () {
                            Drupal.feedbackFormToggle($block, true);
                        },
                        function () {
                            Drupal.feedbackFormToggle($block, false);
                        }
                    );
                $block.find('form').hide();
                $block.show();
            });
        }
    };

    /**
     * Re-collapse the feedback form after every successful form submission.
     */
    Drupal.behaviors.feedbackFormSubmit = {
        attach: function (context) {
            var $context = $(context);
//            if (!$context.is('#feedback-status-message')) {
//                return;
//            }
            // Collapse the form.
           // $('#block-feedback-form .feedback-link').click();
            // Blend out and remove status message.
           // window.setTimeout(function () {
           //     $context.fadeOut('slow', function () {
            //        $context.remove();
            //    });
            //}, 3000);
        }
    };

    /**
     * Collapse or uncollapse the feedback form block.
     */
    Drupal.feedbackFormToggle = function ($block, enable) {
        if (enable) {
            $block.animate({width: "329px"});
            $block.css('z-index', '960');
            $block.find('form').css('display', 'block');
            $('#feedback-form-toggle', $block).html('[ + ]');
            var cittaslow = $('#block-cittaslow-block');
            if (cittaslow.width() > 51) {
                Drupal.cittaslowToggle(cittaslow, false);
            }
        }
        else {
            $block.animate({width: "29px"});
            $block.css('z-index', '900');
            $('#feedback-form-toggle', $block).html('[ &minus; ]');
        }
    };

    Drupal.behaviors.cittaslow = {
        attach: function (context) {
            $('#block-cittaslow-block', context).once(function () {
                var $block = $(this);
                $block.find('span.cittaslow-link').toggle(function () {
                        if ($block.width() < 300) {
                            Drupal.cittaslowToggle($block, true);
                        }
                        else {
                            Drupal.cittaslowToggle($block, false);
                        }

                    },
                    function () {
                        if ($block.width() < 300) {
                            Drupal.cittaslowToggle($block, true);
                        }
                        else {
                            Drupal.cittaslowToggle($block, false);
                        }
                    }
                );
                $block.show();
            });
        }
    };

    Drupal.cittaslowToggle = function ($block, enable) {

        if (enable) {
            $block.animate({width: "351px"});

        }
        else {
            $block.animate({width: "51px"});
        }
    };
})(jQuery);

(function ($) {
    'use strict';

    // A hash is set in the URL
    if (location.hash) {

        setTimeout(function () {
            var hash = location.hash,
                $target = $(hash);

            // The hash refers to a panel
            if ($target.length && $target.hasClass('panel')) {

                // Let's open the target automatically
                $target.find('.collapse')
                    .first()
                    .collapse();
            }
        }, 500);
    }

    setTimeout(function() {
        var $panels = $('fieldset.panel.collapsible');

        // Run through all panels
        $panels.each(function (index, element) {
            var $element = $(this),
                current_url = location.href.replace(window.location.hash, ''),
                link = current_url + '#' + $element.attr('id'),
                $target_link = $('<a />')
                    .addClass('panel-direct-link')
                    .attr('href', link)
                    .html($('<span />').addClass('icon fa fa-link'));

            // Add the link inside the panels body
            $element.find('.panel-body').prepend($target_link);
        });
    }, 500);

    // Add a .form-control class to the search input
    setTimeout(function() {
        var $searchInput = $('input[name=search_api_views_fulltext]');

        if (! $searchInput.hasClass('form-control')) {
            $searchInput.addClass('form-control');
        }
    }, 500);
})(jQuery);
