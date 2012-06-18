$(document).ready(function() {
  $('div.button').click(function() {
    var $speech     = $('div.speech');
    var currentSize = $speech.css('fontSize');
    var num         = parseFloat(currentSize, 10);
    var unit        = currentSize.slice(-2);

    if (this.id == 'switcher-large') {
      num *= 1.4;
    } else if (this.id == 'switcher-small') {
      num /= 1.4;
    }
    $speech.css('fontSize', num + unit);
  });

  $('div.label').click(function() {
    $('div.button')
    .fadeTo('slow', 0.5)
    .animate({left: 650}, 'slow')
    .fadeTo('slow', 1.0, function() {
      $(this).css('backgroundColor', '#f00');
    }).slideUp('slow');
  });

  $('div.label').click(function() {
    var paraWidth        = $('div.speech p').width();
    var $button          = $('div.button');
    var buttonWidth      = $button.width();
    var paddingRight     = $button.css('paddingRight');
    var paddingLeft      = $button.css('paddingLeft');
    var borderRightWidth = $button.css('borderRightWidth');
    var borderLeftWidth  = $button.css('borderLeftWidth');

    var totalButtonWidth = parseInt(buttonWidth, 10)
    + parseInt(paddingRight, 10)
    + parseInt(paddingLeft, 10) 
    + parseInt(borderRightWidth, 10)
    + parseInt(borderLeftWidth, 10);
    var rightSide = paraWidth - totalButtonWidth;
    $button
    .animate( {left: rightSide}, 'slow')
    .animate( {height: 38}, 'slow');
  });

  $('div.speech p:eq(1)').hide();
  $('span.more').click(function() {
    $('div.speech p:eq(1)').show('slow');
    $(this).hide();
  });

  $('div.speech p:eq(3)').css('backgroundColor', '#fcf').hide();
  $('div.speech p:eq(2)').css('backgroundColor', '#cff').click(function() {
    var $thisPar = $(this)
    $(this).next().slideDown('slow', function() {
      $thisPar.slideUp('slow');
    });
  });
});
