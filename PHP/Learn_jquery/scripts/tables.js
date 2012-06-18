//$(document).ready(function() {
//  var alternateRowColors = function($table) {
//    $('tbody tr:odd', $table).removeClass('even').addClass('odd');
//    $('tbody tr:even', $table).removeClass('odd').addClass('even');
//  };
////  jQuery.fn.alternateRowColors = function() {
////    $('tbody tr:odd', this).removeClass('even').addClass('odd');
////    $('tbody tr:even', this).removeClass('odd').addClass('even');
////    return this;
////  };
//
//  $('table.sortable').each(function() {
//    var $table = $(this);
//    alternateRowColors($table);
//    $('th', $table).each(function(column) {
//      if ($(this).is('.sort-alpha')) {
//        $(this).addClass('clickable').hover(function() {
//	  $(this).addClass('hover');
//	}, function() {
//	    $(this).removeClass('hover');
//	  }).click(function() {
//	      var rows = $table.find('tbody > tr').get();
//	      rows.sort(function(a, b) {
//		var keyA = $(a).children('td').eq(column).text().toUpperCase();
//		var keyB = $(b).children('td').eq(column).text().toUpperCase();
//
//		if (keyA < keyB) return -1;
//		if (keyA > keyB) return 1;
//		return 0;
//	      });
//	      $.each(rows, function(index, row) {
//		$table.children('tbody').append(row);
//	      });
//	      alternateRowColors($table);
//	    });
//      }
//    });
//  });
//});
//
//$.each(rows, function(index, row) {
//  var $cell = $(row).children('td').eq(column);
//  row.sortKey = $cell.find('.sort-key').text().toUpperCase() + ' ' + $cell.text().toUpperCase();
//});
$.fn.alternateRowColors = function() {
  $('tbody tr:odd', this).removeClass('even').addClass('odd');
  $('tbody tr:even', this).removeClass('odd').addClass('even');
  return this;
};

$(document).ready(function() {
  var alternateRowColors = function($table) {
    $('tbody tr:odd', this).removeClass('even').addClass('odd');
    $('tbody tr:even', this).removeClass('odd').addClass('even');
  };

  $('table.sortable').each(function() {
    var $table = $(this);
    $table.alternateRowColors($table);

    $table.find('th').each(function(column) {
      var findSortKey;

      if ($(this).is('.sort-alpha')) {
        findSortKey = function($cell) {
	  return $cell.find('.sort-key').text().toUpperCase() + ' ' + $cell.text().toUpperCase();
	};
      }
      else if ($(this).is('.sort-numeric')) {
        findSortKey = function($cell) {
	  var key = parseFloat($cell.text().replace(/^[^\d.]*/,''));
	  return isNaN(key) ? 0 : key;
	};
      }
      else if ($(this).is('.sort-date')) {
        findSortKey = function($cell) {
	  return Date.parse('1 ' + $cell.text());
	};
      }

      if (findSortKey) {
	$(this).addClass('clickable').hover(function() {
	  $(this).addClass('hover');
	}, function() {
	  $(this).removeClass('hover');
	}).click(function() {
	    var newDirection = 1;
	    if ($(this).is('.sorted-asc')) {
	      newDirection = -1;
	    }

	    var rows = $table.find('tbody > tr').get();
	    $.each(rows, function(index, row) {
	      row.sortKey = findSortKey($(row).children('td').eq(column));
	    });
	    rows.sort(function(a, b) {
	      if (a.sortKey < b.sortKey) return -newDirection;
	      if (a.sortKey > b.sortKey) return newDirection;
	      return 0;
	    });
	    $.each(rows, function(index, row) {
	      $table.children('tbody').append(row);
	      row.sortKey = null;
	    });

	    $table.find('th').removeClass('sorted-asc').removeClass('sorted-desc');

	    var $sortHead = $table.find('th').filter(':nth-child(' + (column + 1) + ')');
	    if (newDirection == 1) {
	      $sortHead.addClass('sorted-asc');
	    } else {
	      $sortHead.addClass('sorted-desc');
	    }
	    $table.find('td').removeClass('sorted').filter(':nth-child(' + (column + 1) + ')').addClass('sorted');
	    $table.alternateRowColors($table);
	  });
      }
    });
  });
});

$(document).ready(function() {
  $('table.paginated').each(function() {
    var currentPage = 0;
    var numPerPage  = 10;
    var $table = $(this);
    $table.bind('repaginate', function() {
      $table.find('tbody tr').show()
      .slice(0, currentPage * numPerPage).hide().end()
      .slice((currentPage + 1) * numPerPage - 1 + 1).hide()
      .end();
    });
    var numRows  = $table.find('tbody tr').length;
    var numPages = Math.ceil(numRows / numPerPage);

    var $pager   = $('<div class="pager"></div>');
    for (var page = 0; page < numPages; page++) {
      $('<span class="page-number">' + (page + 1) + '</span>')
//	.click(function() {
//	  currentPage = page;
//	  repaginate();
        .bind('click', {'newPage': page}, function(event) {
	  currentPage = event.data['newPage'];
	  $table.trigger('repaginate');
	  $(this).addClass('active').siblings().removeClass('active');
      })
      .appendTo($pager).addClass('clickable');
    }
    $pager.find('span.page-number:first').addClass('active');
    $pager.insertBefore($table);
    $table.trigger('repaginate');
  });
});
