/* Svendborg theme script
*/
( function ($) {
  $(document).ready(function(){

    var button = 'filter-all';
    var button_class = "btn-primary";
    var button_normal = "btn-blacknblue";
    var $container = $("#nyheder-content-isotoper .view-content");
    check_button(button);

    function check_button(button){
      $('.filter-link').removeClass(button_class);
      $('.filter-link').addClass(button_normal);
      $('#'+button).addClass(button_class);
      $('#'+button).removeClass(button_normal);
    }

    // filter buttons.
    $('.filter-link').click(function(event){
      $(this).addClass(button_class);
      button = $(this).attr('id');
      check_button(button);
      var filterValue = $( this ).attr('data-filter');
      jQuery.get("/aktulet_news/ajax/view/"+filterValue+'/'+20, function(data){
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

      $container.imagesLoaded(function(){

        $container.masonry({
          columnWidth: '.switch-elements',
        });

        $container.infinitescroll({
          state : {
            currPage: 0
          },
          // selector for the paged navigation
          navSelector  : '.pagination',
          // selector for the NEXT link (to page 2)
          nextSelector : '.pagination li.next a',
          // selector for all items you'll retrieve
          itemSelector : '.switch-elements',
          loading: {
            //finishedMsg: 'Der er ikke flere.',
            //img: 'http://i.imgur.com/qkKy8.gif'
          },
          debug: false,
        },
        function(newElements) {
          var $newElems = $(newElements).hide();
          $newElems.imagesLoaded(function(){
            $newElems.fadeIn(); // fade in when ready
            $container.masonry( 'appended', $newElems);
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
    $(window).bind('scroll', function() {
        var navHeight = $( window ).height();
        if ($(window).scrollTop() > 41 && $(window).width() > 768 ) {
          $('.header_svendborg header').addClass('navbar-fixed-top');
          $('.header_fixed_inner').addClass('container');
          $('.header_svendborg header').removeClass('container');
          $('.main-container').css('padding-top','114px');
          $('#fixed-navbar').addClass('row');
          $('img#front-logo').attr('src', Drupal.settings.basePath + Drupal.settings.pathToTheme + '/images/svendborg_logo.png');
       }
        else {
          $('.header_svendborg header').removeClass('navbar-fixed-top');
          $('.header_fixed_inner').removeClass('container');
          $('.header_svendborg header').addClass('container');
          $('.main-container').css('padding-top','0');
          $('#fixed-navbar').removeClass('row');
          $('img#front-logo').attr('src', Drupal.settings.basePath + Drupal.settings.pathToTheme + '/images/footer_logo.png');
        }
    });

    // borger.dk articles
      $("div.mArticle").hide();
      $(".microArticle a.gplus").click(function() {
        var article = $(this).parent().find('h3');
        var myid = article.attr('id');
        var style = $('div.' + myid).css('display');
        if (style == 'none') {
          $("div." + myid).show("500");
          $(this).addClass('gminus');
          $(this).removeClass('gplus');
        }
        else {
          $("div." + myid).hide("500");
          $(this).addClass('gplus');
          $(this).removeClass('gminus');
        }
        return false;
      });

      $(".gplus_all").click(function() {
        console.log('plus');
        $("div.mArticle").show();
        $(".microArticle a.gplus").addClass('gminus');
        $(".microArticle a.gplus").removeClass('gplus');

        return false;
      });
      $(".gminus_all").click(function() {
        $("div.mArticle").hide();
        $(".microArticle a.gminus").addClass('gplus');
        $(".microArticle a.gminus").removeClass('gminus');

        return false;
      });
      // front nav header search_form button
      $(".front .region-navigation.container #search-block-form button").click(function(){
        $( ".main-container .front-search-box input" ).focus();

        return false;
      });

    $('#feedback-submit').addClass('btn-primary');

    var links = $('.region-content a');
    $(links).each(function() {
      if (!$(this).attr('href') && $(this).attr('id') && $(this).attr('id') !== 'main-content') {
        $(this).addClass('link_here');
      }
    });

  });

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
          function() {
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
    if (!$context.is('#feedback-status-message')) {
      return;
    }
    // Collapse the form.
    $('#block-feedback-form .feedback-link').click();
    // Blend out and remove status message.
    window.setTimeout(function () {
      $context.fadeOut('slow', function () {
        $context.remove();
      });
    }, 3000);
  }
};

/**
 * Collapse or uncollapse the feedback form block.
 */
Drupal.feedbackFormToggle = function ($block, enable) {
  if (enable) {
    $block.animate({width:"329px"});
    $block.css('z-index','960');
    $block.find('form').css('display','block');
    $('#feedback-form-toggle', $block).html('[ + ]');
    var cittaslow = $('#block-cittaslow-block');
    if (cittaslow.width() > 51) {
      Drupal.cittaslowToggle(cittaslow, false);
    }
  }
  else {
    $block.animate({width:"29px"});
    $block.css('z-index','900');
    $('#feedback-form-toggle', $block).html('[ &minus; ]');
  }
};

Drupal.behaviors.cittaslow= {
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
          function() {
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
    $block.animate({width:"351px"});

  }
  else {
    $block.animate({width:"51px"});
  }
};

})( jQuery );


/**
 * Re-collapse the feedback form after every successful form submission.
 */
Drupal.behaviors.feedbackFormSubmit = {
  attach: function (context) {}
};
