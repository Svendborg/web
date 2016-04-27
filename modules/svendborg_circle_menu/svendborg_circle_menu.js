(function($) {
  $(document).ready(function() {
    $("body").append("<div id='ToolTipDiv'></div>");
    $(".front-indholsdmenu a").each(function() {
      var offset = $(this).offset();
      $(this).hover(function(e) {
        $(this).mousemove(function(e) {

          $("#ToolTipDiv").css({'top': offset.top + 30, 'left': offset.left + 30});
        });
        $("#ToolTipDiv").stop(true, true);
        $("#ToolTipDiv")
          .html($(this).attr('title'))
          .fadeIn("fast");
        $(this).removeAttr('title');
      }, function() {
        $("#ToolTipDiv").stop(true, true);
        $("#ToolTipDiv").fadeOut(Drupal.settings.text_duration_time * 1000);
        $(this).attr('title', $("#ToolTipDiv").html());
      });
    });
  });
})( jQuery );
