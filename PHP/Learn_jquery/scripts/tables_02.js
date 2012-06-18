//$(document).ready(function() {
//  var rowClass = 'even';
//  var rowIndex = 0;
//  $('table.striped tbody tr').each(function(index) {
//    if (rowIndex % 3 == 0) {
//      rowClass = (rowClass == 'even' ? 'odd' : 'even');
//    };
//    $(this).addClass(rowClass);
//    rowIndex++;
//  });
//});
//$(document).ready(function() {
//  var rowClass = 'even';
//  var rowIndex = 0;
//  $('table.striped tbody tr').each(function(index) {
//    if ($('th', this).length) {
//      rowClass = 'subhead';
//      rowIndex = -1;
//    } else if (rowIndex % 3 == 0) {
//      rowClass = (rowClass == 'even' ? 'odd' : 'even');
//    };
//    $(this).addClass(rowClass);
//    rowIndex++;
//  });
//});
$(document).ready(function() {
  $('table.striped').each(function() {
    $(this).bind('stripe', function() {
      var rowIndex = 0;
      $('tbody tr:not(.filtered)', this).each(function(index) {
	if ($('th',this).length) {
	  $(this).addClass('subhead');
	  rowIndex = -1;
	} else {
	  if (rowIndex % 6 < 3) {
	    $(this).removeClass('odd').addClass('even');
	  }
	  else {
	    $(this).removeClass('even').addClass('odd');
	  }
	};
	rowIndex++;
      });
    });
    $(this).trigger('stripe');
  });
});

//$(document).ready(function() {
//  var column = 3;
//  $('table.striped td:nth-child(' + column + ')')
//    .click(function() {
//      // Do something
//    });
//});
$(document).ready(function() {
  var highlighted = "";
  var column = 3;

  var positionTooltip = function(event) {
    var tPosX = event.pageX - 5;
    var tPosY = event.pageY + 20;
    $('div.tooltip').css({top: tPosY, left: tPosX});
  };

  var showTooltip = function(event) {
    $('div.tooltip').remove();
    var $thisAuthor = $(this).text();
    if ($(this).parent().is('.highlight')) {
      highlighted = 'un-';
    } else {
      highlighted = '';
    };
    $('<div class="tooltip">Click to ' + highlighted + 'highlight all articles written by '
      + $thisAuthor + '</div>')
    .appendTo('body');
    positionTooltip(event);
  };

  var hideTooltip = function() {
    $('div.tooltip').remove();
  };
  $('table.striped td:nth-child(' + column + ')' )
    .addClass('clickable')
    .click(function(event) {
      var thisClicked = $(this).text();
      $('table.striped td:nth-child(' + column + ')' ).each(function(index) {
	  if (thisClicked == $(this).text()) {
	    $(this).parent().toggleClass('highlight');
	  } else {
	    $(this).parent().removeClass('highlight');
	  };
	});
	showTooltip.call(this, event);
    })
      .hover(showTooltip, hideTooltip)
      .mousemove(positionTooltip);
});

$(document).ready(function() {
  var toggleMinus = '../icons/bullet_toggle_minus.png';
  var togglePlus  = '../icons/bullet_toggle_plus.png';
  var $subHead    = $('tbody th:first-child');

  $subHead.prepend('<img src="' + toggleMinus + '" alt="collapse this section" />');
  $('img', $subHead).addClass('clickable')
  .click(function() {
    var toggleSrc = $(this).attr('src');
    if ( toggleSrc == toggleMinus ) {
      $(this).attr('src', togglePlus)
      .parents('tr').siblings().addClass('collapsed').fadeOut('fast');
    } else {
      $(this).attr('src', toggleMinus)
      .parents('tr').siblings().removeClass('collapsed').not('.filtered').fadeIn('fast');
    };
  });
});

$(document).ready(function() {
  $('table.filterable').each(function() {
    var $table = $(this);
    $table.find('th').each(function (column) {
      if ($(this).is('.filter-column')) {
        var $filters = $('<div class="filters"><h3>Filter by ' + $(this).text() + ':</h3></div>');
	$filters.insertBefore($table);

	var keywords = {};
	$table.find('tbody tr td')
	  .filter(':nth-child(' + (column + 1) + ')')
          .each(function() {
	    keywords[$(this).text()] = $(this).text();
	  });

	$('<div class="filter">all</div>').click(function() {
	  $table.find('tbody tr').show().removeClass('filtered');
	  $(this).addClass('active').siblings().removeClass('active');
	  $table.trigger('stripe');
	}).addClass('clickable active').appendTo($filters);

	$.each(keywords, function(index, keyword) {
	  $('<div class="filter"></div>').text(keyword).bind('click', {'keyword': keyword}, function(event) {
	      $table.find('tbody tr').each(function() {
		if ($('td', this).filter(':nth-child(' + (column + 1) +')').text() == event.data['keyword']) {
		  $(this).show().removeClass('filtered').not('.collapsed').show();
		}
		else if ($('th', this).length == 0) {
		  $(this).addClass('filtered').hide();
		}
	      });

	      $(this).addClass('active').siblings().removeClass('active');
	      $table.trigger('stripe');
	    }).addClass('clickable').appendTo($filters);
	});
	$filters.insertBefore($table);
      }
    });
  });
});
