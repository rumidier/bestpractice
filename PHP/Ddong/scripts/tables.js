// Example: Row Grouping Tags
// $(document).ready(function() {
//   $('table.sortable tbody tr:odd').addClass('odd');
//   $('table.sortable tbody tr:even').addClass('even');
// });

// Example: Basic Alphabetical Sorting
// Step 1
// $(document).ready(function() {
//   $('table.sortable').each(function() {
//     var $table = $(this);
//     $('th', $table).each(function(column) {
//       var $header = $(this);
//       if ($header.is('.sort-alpha')) {
//         $header.addClass('clickable').hover(function() {
//           $header.addClass('hover');
//         }, function() {
//           $header.removeClass('hover');
//         }).click(function() {
//           var rows = $table.find('tbody > tr').get();
//           rows.sort(function(a, b) {
//             var keyA = $(a).children('td').eq(column).text()
//               .toUpperCase();
//             var keyB = $(b).children('td').eq(column).text()
//               .toUpperCase();
//             if (keyA < keyB) return -1;
//             if (keyA > keyB) return 1;
//             return 0;
//           });
//           $.each(rows, function(index, row) {
//             $table.children('tbody').append(row);
//           });
//         });
//       }
//     });
//   });
// });

// Step 2
// $(document).ready(function() {
//   var alternateRowColors = function($table) {
//     $('tbody tr:odd', $table)
//       .removeClass('even').addClass('odd');
//     $('tbody tr:even', $table)
//       .removeClass('odd').addClass('even');
//   };
//   
//   $('table.sortable').each(function() {
//     var $table = $(this);
//     alternateRowColors($table);
//     $('th', $table).each(function(column) {
//       var $header = $(this);
//       if ($header.is('.sort-alpha')) {
//         $header.addClass('clickable').hover(function() {
//           $header.addClass('hover');
//         }, function() {
//           $header.removeClass('hover');
//         }).click(function() {
//           var rows = $table.find('tbody > tr').get();
//           rows.sort(function(a, b) {
//             var keyA = $(a).children('td').eq(column).text()
//               .toUpperCase();
//             var keyB = $(b).children('td').eq(column).text()
//               .toUpperCase();
//             if (keyA < keyB) return -1;
//             if (keyA > keyB) return 1;
//             return 0;
//           });
//           $.each(rows, function(index, row) {
//             $table.children('tbody').append(row);
//           });
//           alternateRowColors($table);
//         });
//       }
//     });
//   });
// });

// Example: Refactoring the row striping code as a plug-in method
// jQuery.fn.alternateRowColors = function() {
//   $('tbody tr:odd', this)
//     .removeClass('even').addClass('odd');
//   $('tbody tr:even', this)
//     .removeClass('odd').addClass('even');
//   return this;
// };
// 
// $(document).ready(function() {
//   $('table.sortable').each(function() {
//     var $table = $(this);
//     $table.alternateRowColors();
//     $('th', $table).each(function(column) {
//       var $header = $(this);
//       if ($header.is('.sort-alpha')) {
//         $header.addClass('clickable').hover(function() {
//           $header.addClass('hover');
//         }, function() {
//           $header.removeClass('hover');
//         }).click(function() {
//           var rows = $table.find('tbody > tr').get();
//           rows.sort(function(a, b) {
//             var keyA = $(a).children('td').eq(column).text()
//               .toUpperCase();
//             var keyB = $(b).children('td').eq(column).text()
//               .toUpperCase();
//             if (keyA < keyB) return -1;
//             if (keyA > keyB) return 1;
//             return 0;
//           });
//           $.each(rows, function(index, row) {
//             $table.children('tbody').append(row);
//           });
//           $table.alternateRowColors();
//         });
//       }
//     });
//   });
// });

// Example: Improving sort performance using expando properties
// jQuery.fn.alternateRowColors = function() {
//   $('tbody tr:odd', this)
//     .removeClass('even').addClass('odd');
//   $('tbody tr:even', this)
//     .removeClass('odd').addClass('even');
//   return this;
// };
// 
// $(document).ready(function() {
//   $('table.sortable').each(function() {
//     var $table = $(this);
//     $table.alternateRowColors();
//     $('th', $table).each(function(column) {
//       var $header = $(this);
//       if ($header.is('.sort-alpha')) {
//         $header.addClass('clickable').hover(function() {
//           $header.addClass('hover');
//         }, function() {
//           $header.removeClass('hover');
//         }).click(function() {
//           var rows = $table.find('tbody > tr').get();
//           $.each(rows, function(index, row) {
//             row.sortKey = $(row).children('td').eq(column)
//               .text().toUpperCase();
//           });
//           rows.sort(function(a, b) {
//             if (a.sortKey < b.sortKey) return -1;
//             if (a.sortKey > b.sortKey) return 1;
//             return 0;
//           });
//           $.each(rows, function(index, row) {
//             $table.children('tbody').append(row);
//             row.sortKey = null;
//           });
//           $table.alternateRowColors();
//         });
//       }
//     });
//   });
// });

// Example: Explicitly marking sort keys
// jQuery.fn.alternateRowColors = function() {
//   $('tbody tr:odd', this)
//     .removeClass('even').addClass('odd');
//   $('tbody tr:even', this)
//     .removeClass('odd').addClass('even');
//   return this;
// };
// 
// $(document).ready(function() {
//   $('table.sortable').each(function() {
//     var $table = $(this);
//     $table.alternateRowColors();
//     $('th', $table).each(function(column) {
//       var $header = $(this);
//       if ($header.is('.sort-alpha')) {
//         $header.addClass('clickable').hover(function() {
//           $header.addClass('hover');
//         }, function() {
//           $header.removeClass('hover');
//         }).click(function() {
//           var rows = $table.find('tbody > tr').get();
//           $.each(rows, function(index, row) {
//             var $cell = $(row).children('td').eq(column);
//             row.sortKey = $cell.find('.sort-key').text()
//               .toUpperCase() + ' '
//               + $cell.text().toUpperCase();
//           });
//           rows.sort(function(a, b) {
//             if (a.sortKey < b.sortKey) return -1;
//             if (a.sortKey > b.sortKey) return 1;
//             return 0;
//           });
//           $.each(rows, function(index, row) {
//             $table.children('tbody').append(row);
//             row.sortKey = null;
//           });
//           $table.alternateRowColors();
//         });
//       }
//     });
//   });
// });

// Example: Sorting by other types of data
// jQuery.fn.alternateRowColors = function() {
//   $('tbody tr:odd', this)
//     .removeClass('even').addClass('odd');
//   $('tbody tr:even', this)
//     .removeClass('odd').addClass('even');
//   return this;
// };
// 
// $(document).ready(function() {
//   $('table.sortable').each(function() {
//     var $table = $(this);
//     $table.alternateRowColors();
//     $('th', $table).each(function(column) {
//       var $header = $(this);
//       var findSortKey;
//       if ($header.is('.sort-alpha')) {
//         findSortKey = function($cell) {
//           return $cell.find('.sort-key').text().toUpperCase()
//             + ' ' + $cell.text().toUpperCase();
//         };
//       }
//       else if ($header.is('.sort-numeric')) {
//         findSortKey = function($cell) {
//           var key = $cell.text().replace(/^[^\d.]*/, '');
//           key = parseFloat(key);
//           return isNaN(key) ? 0 : key;
//         };
//       }
//       else if ($header.is('.sort-date')) {
//         findSortKey = function($cell) {
//           return Date.parse('1 ' + $cell.text());
//         };
//       }
//           
//       if (findSortKey) {
//         $header.addClass('clickable').hover(function() {
//           $header.addClass('hover');
//         }, function() {
//           $header.removeClass('hover');
//         }).click(function() {
//           var rows = $table.find('tbody > tr').get();
//           $.each(rows, function(index, row) {
//             var $cell = $(row).children('td').eq(column);
//             row.sortKey = findSortKey($cell);
//           });
//           rows.sort(function(a, b) {
//             if (a.sortKey < b.sortKey) return -1;
//             if (a.sortKey > b.sortKey) return 1;
//             return 0;
//           });
//           $.each(rows, function(index, row) {
//             $table.children('tbody').append(row);
//             row.sortKey = null;
//           });
//           $table.alternateRowColors();
//         });
//       }
//     });
//   });
// });

// Example: Column highlighting
// jQuery.fn.alternateRowColors = function() {
//   $('tbody tr:odd', this)
//     .removeClass('even').addClass('odd');
//   $('tbody tr:even', this)
//     .removeClass('odd').addClass('even');
//   return this;
// };
// 
// $(document).ready(function() {
//   $('table.sortable').each(function() {
//     var $table = $(this);
//     $table.alternateRowColors();
//     $('th', $table).each(function(column) {
//       var $header = $(this);
//       var findSortKey;
//       if ($header.is('.sort-alpha')) {
//         findSortKey = function($cell) {
//           return $cell.find('.sort-key').text().toUpperCase()
//             + ' ' + $cell.text().toUpperCase();
//         };
//       }
//       else if ($header.is('.sort-numeric')) {
//         findSortKey = function($cell) {
//           var key = $cell.text().replace(/^[^\d.]*/, '');
//           key = parseFloat(key);
//           return isNaN(key) ? 0 : key;
//         };
//       }
//       else if ($header.is('.sort-date')) {
//         findSortKey = function($cell) {
//           return Date.parse('1 ' + $cell.text());
//         };
//       }
//           
//       if (findSortKey) {
//         $header.addClass('clickable').hover(function() {
//           $header.addClass('hover');
//         }, function() {
//           $header.removeClass('hover');
//         }).click(function() {
//           var rows = $table.find('tbody > tr').get();
//           $.each(rows, function(index, row) {
//             var $cell = $(row).children('td').eq(column);
//             row.sortKey = findSortKey($cell);
//           });
//           rows.sort(function(a, b) {
//             if (a.sortKey < b.sortKey) return -1;
//             if (a.sortKey > b.sortKey) return 1;
//             return 0;
//           });
//           $.each(rows, function(index, row) {
//             $table.children('tbody').append(row);
//             row.sortKey = null;
//           });
//           $table.find('td').removeClass('sorted')
//             .filter(':nth-child(' + (column + 1) + ')')
//             .addClass('sorted');
//           $table.alternateRowColors();
//         });
//       }
//     });
//   });
// });

// Example: Alternating sort directions
// jQuery.fn.alternateRowColors = function() {
//   $('tbody tr:odd', this)
//     .removeClass('even').addClass('odd');
//   $('tbody tr:even', this)
//     .removeClass('odd').addClass('even');
//   return this;
// };
// 
// $(document).ready(function() {
//   $('table.sortable').each(function() {
//     var $table = $(this);
//     $table.alternateRowColors();
//     $('th', $table).each(function(column) {
//       var $header = $(this);
//       var findSortKey;
//       if ($header.is('.sort-alpha')) {
//         findSortKey = function($cell) {
//           return $cell.find('.sort-key').text().toUpperCase()
//             + ' ' + $cell.text().toUpperCase();
//         };
//       }
//       else if ($header.is('.sort-numeric')) {
//         findSortKey = function($cell) {
//           var key = $cell.text().replace(/^[^\d.]*/, '');
//           key = parseFloat(key);
//           return isNaN(key) ? 0 : key;
//         };
//       }
//       else if ($header.is('.sort-date')) {
//         findSortKey = function($cell) {
//           return Date.parse('1 ' + $cell.text());
//         };
//       }
//           
//       if (findSortKey) {
//         $header.addClass('clickable').hover(function() {
//           $header.addClass('hover');
//         }, function() {
//           $header.removeClass('hover');
//         }).click(function() {
//           var sortDirection = 1;
//           if ($header.is('.sorted-asc')) {
//             sortDirection = -1;
//           }
//           var rows = $table.find('tbody > tr').get();
//           $.each(rows, function(index, row) {
//             var $cell = $(row).children('td').eq(column);
//             row.sortKey = findSortKey($cell);
//           });
//           rows.sort(function(a, b) {
//             if (a.sortKey < b.sortKey) return -sortDirection;
//             if (a.sortKey > b.sortKey) return sortDirection;
//             return 0;
//           });
//           $.each(rows, function(index, row) {
//             $table.children('tbody').append(row);
//             row.sortKey = null;
//           });
//           $table.find('th').removeClass('sorted-asc')
//             .removeClass('sorted-desc');
//           if (sortDirection == 1) {
//             $header.addClass('sorted-asc');
//           }
//           else {
//             $header.addClass('sorted-desc');
//           }
//           $table.find('td').removeClass('sorted')
//             .filter(':nth-child(' + (column + 1) + ')')
//             .addClass('sorted');
//           $table.alternateRowColors();
//         });
//       }
//     });
//   });
// });


// Example: JavaScript pagination
// Step 1
// $(document).ready(function() {
//   $('table.paginated').each(function() {
//     var currentPage = 0;
//     var numPerPage = 10;
//     var $table = $(this);
//     
//     $table.find('tbody tr').hide()
//       .slice(currentPage * numPerPage,
//         (currentPage + 1) * numPerPage)
//       .show();
//   });
// });

// Step 2
// $(document).ready(function() {
//   $('table.paginated').each(function() {
//     var currentPage = 0;
//     var numPerPage = 10;
//     var $table = $(this);
//     
//     var numRows = $table.find('tbody tr').length;
//     var numPages = Math.ceil(numRows / numPerPage);
// 
//     var $pager = $('<div class="pager"></div>');
//     for (var page = 0; page < numPages; page++) {
//       $('<span class="page-number">' + (page + 1) + '</span>')
//         .appendTo($pager).addClass('clickable');
//     }
//     $pager.insertBefore($table);
//     
//     $table.find('tbody tr').hide()
//       .slice(currentPage * numPerPage,
//         (currentPage + 1) * numPerPage)
//       .show();
//   });
// });

// Step 3
// $(document).ready(function() {
//   $('table.paginated').each(function() {
//     var currentPage = 0;
//     var numPerPage = 10;
//     var $table = $(this);
//     var repaginate = function() {
//       $table.find('tbody tr').hide()
//         .slice(currentPage * numPerPage,
//           (currentPage + 1) * numPerPage)
//         .show();
//     };
//     var numRows = $table.find('tbody tr').length;
//     var numPages = Math.ceil(numRows / numPerPage);
//     var $pager = $('<div class="pager"></div>');
//     for (var page = 0; page < numPages; page++) {
//       $('<span class="page-number"></span>').text(page + 1)
//         .click(function() {
//           currentPage = page;
//           repaginate();
//         }).appendTo($pager).addClass('clickable');
//     }
//     $pager.insertBefore($table);
//   });
// });

// Step 4
// $(document).ready(function() {
//   $('table.paginated').each(function() {
//     var currentPage = 0;
//     var numPerPage = 10;
//     var $table = $(this);
//     var repaginate = function() {
//       $table.find('tbody tr').hide()
//         .slice(currentPage * numPerPage,
//           (currentPage + 1) * numPerPage)
//         .show();
//     };
//     var numRows = $table.find('tbody tr').length;
//     var numPages = Math.ceil(numRows / numPerPage);
//     var $pager = $('<div class="pager"></div>');
//     for (var page = 0; page < numPages; page++) {
//       $('<span class="page-number"></span>').text(page + 1)
//         .bind('click', {newPage: page}, function(event) {
//           currentPage = event.data['newPage'];
//           repaginate();
//         }).appendTo($pager).addClass('clickable');
//     }
//     $pager.insertBefore($table);
//   });
// });

// Step 5
// $(document).ready(function() {
//   $('table.paginated').each(function() {
//     var currentPage = 0;
//     var numPerPage = 10;
//     var $table = $(this);
//     var repaginate = function() {
//       $table.find('tbody tr').hide()
//         .slice(currentPage * numPerPage,
//           (currentPage + 1) * numPerPage)
//         .show();
//     };
//     var numRows = $table.find('tbody tr').length;
//     var numPages = Math.ceil(numRows / numPerPage);
//     var $pager = $('<div class="pager"></div>');
//     for (var page = 0; page < numPages; page++) {
//       $('<span class="page-number"></span>').text(page + 1)
//         .bind('click', {newPage: page}, function(event) {
//           currentPage = event.data['newPage'];
//           repaginate();
//           $(this).addClass('active')
//             .siblings().removeClass('active');
//         }).appendTo($pager).addClass('clickable');
//     }
//     $pager.insertBefore($table)
//       .find('span.page-number:first').addClass('active');
//   });
// });


// Finished code: Sorting and Paging

jQuery.fn.alternateRowColors = function() {
  $('tbody tr:odd', this)
    .removeClass('even').addClass('odd');
  $('tbody tr:even', this)
    .removeClass('odd').addClass('even');
  return this;
};

$(document).ready(function() {
  $('table.sortable').each(function() {
    var $table = $(this);
    $table.alternateRowColors();
    $('th', $table).each(function(column) {
      var $header = $(this);
      var findSortKey;
      if ($header.is('.sort-alpha')) {
        findSortKey = function($cell) {
          return $cell.find('.sort-key').text().toUpperCase()
            + ' ' + $cell.text().toUpperCase();
        };
      }
      else if ($header.is('.sort-numeric')) {
        findSortKey = function($cell) {
          var key = $cell.text().replace(/^[^\d.]*/, '');
          key = parseFloat(key);
          return isNaN(key) ? 0 : key;
        };
      }
      else if ($header.is('.sort-date')) {
        findSortKey = function($cell) {
          return Date.parse('1 ' + $cell.text());
        };
      }
          
      if (findSortKey) {
        $header.addClass('clickable').hover(function() {
          $header.addClass('hover');
        }, function() {
          $header.removeClass('hover');
        }).click(function() {
          var sortDirection = 1;
          if ($header.is('.sorted-asc')) {
            sortDirection = -1;
          }
          var rows = $table.find('tbody > tr').get();
          $.each(rows, function(index, row) {
            var $cell = $(row).children('td').eq(column);
            row.sortKey = findSortKey($cell);
          });
          rows.sort(function(a, b) {
            if (a.sortKey < b.sortKey) return -sortDirection;
            if (a.sortKey > b.sortKey) return sortDirection;
            return 0;
          });
          $.each(rows, function(index, row) {
            $table.children('tbody').append(row);
            row.sortKey = null;
          });
          $table.find('th').removeClass('sorted-asc')
            .removeClass('sorted-desc');
          if (sortDirection == 1) {
            $header.addClass('sorted-asc');
          }
          else {
            $header.addClass('sorted-desc');
          }
          $table.find('td').removeClass('sorted')
            .filter(':nth-child(' + (column + 1) + ')')
            .addClass('sorted');
          $table.alternateRowColors();
          $table.trigger('repaginate');
        });
      }
    });
  });
});

$(document).ready(function() {
  $('table.paginated').each(function() {
    var currentPage = 0;
    var numPerPage = 10;
    var $table = $(this);
    $table.bind('repaginate', function() {
      $table.find('tbody tr').hide()
        .slice(currentPage * numPerPage,
          (currentPage + 1) * numPerPage)
        .show();
    });
    var numRows = $table.find('tbody tr').length;
    var numPages = Math.ceil(numRows / numPerPage);
    var $pager = $('<div class="pager"></div>');
    for (var page = 0; page < numPages; page++) {
      $('<span class="page-number"></span>').text(page + 1)
        .bind('click', {newPage: page}, function(event) {
          currentPage = event.data['newPage'];
          $table.trigger('repaginate');
          $(this).addClass('active')
            .siblings().removeClass('active');
        }).appendTo($pager).addClass('clickable');
    }
    $pager.insertBefore($table)
      .find('span.page-number:first').addClass('active');
  });
});


// Example: Row striping
// Step 1
// $(document).ready(function() {
//   $('table.striped tr:odd').addClass('odd');
//   $('table.striped tr:even').addClass('even');
// });

// Step 2
// $(document).ready(function() {
//   $('table.striped tr:nth-child(odd)').addClass('odd');
//   $('table.striped tr:nth-child(even)').addClass('even');
// });

// Step 3
// $(document).ready(function() {
//   $('table.striped tr:not(:has(th)):odd').addClass('odd');
//   $('table.striped tr:not(:has(th)):even').addClass('even');
// });

// Step 4
// $(document).ready(function() {
//   $('table.striped tbody').each(function() {
//     $(this).find('tr:not(:has(th)):odd').addClass('odd');
//     $(this).find('tr:not(:has(th)):even').addClass('even');
//   });
// });

// Example: Advanced row striping
// Step 1
// $(document).ready(function() {
//   $('table.striped tbody').each(function() {
//     $(this).find('tr:not(:has(th))').filter(function(index) {
//       return (index % 6) < 3;
//     }).addClass('odd');
//   });
// });

// Step 2
// $(document).ready(function() {
//   $('table.striped tbody').each(function() {
//     $(this).find('tr:not(:has(th))').addClass('even')
//     .filter(function(index) {
//       return (index % 6) < 3;
//     }).removeClass('even').addClass('odd');
//   });
// });

// Example: Interactive row highlighting
// Step 1
// $(document).ready(function() {
//   var $authorCells = $('table.striped td:nth-child(3)');
//   $authorCells.click(function() {
//     // Perform our highlighting here.
//   });
// });

// Step 2
// $(document).ready(function() {
//   var $authorCells = $('table.striped td:nth-child(3)');
//   $authorCells.click(function() {
//     var authorName = $(this).text();
//     $authorCells.each(function(index) {
//       if (authorName == $(this).text()) {
//         $(this).parent().toggleClass('highlight');
//       };
//     });
//   });
// });

// Step 3
// $(document).ready(function() {
//   var $authorCells = $('table.striped td:nth-child(3)');
//   $authorCells.click(function() {
//     var authorName = $(this).text();
//     $authorCells.each(function(index) {
//       if (authorName == $(this).text()) {
//         $(this).parent().toggleClass('highlight');
//       }
//       else {
//         $(this).parent().removeClass('highlight');
//       }
//     });
//   });
// });

// Example: Tooltips
// Step 1, highlight author rows
// $(document).ready(function() {
//   var $authorCells = $('table.striped td:nth-child(3)');
//   $authorCells
//     .addClass('clickable')
//     .click(function() {
//       var authorName = $(this).text();
//       $authorCells.each(function(index) {
//         if (authorName == $(this).text()) {
//           $(this).parent().toggleClass('highlight');
//         }
//         else {
//           $(this).parent().removeClass('highlight');
//         }
//       });
//     });
// });

// Step 2
// $(document).ready(function() {
//   var $authorCells = $('table.striped td:nth-child(3)');
//   var $tooltip = $('<div id="tooltip"></div>').appendTo('body');
//   
//   var positionTooltip = function(event) {
//     var tPosX = event.pageX;
//     var tPosY = event.pageY + 20;
//     $tooltip.css({top: tPosY, left: tPosX});
//   };
//   var showTooltip = function(event) {
//     var authorName = $(this).text();
//     $tooltip
//       .text('Highlight all articles by ' + authorName)
//       .show();
//     positionTooltip(event);
//   };
//   var hideTooltip = function() {
//     $tooltip.hide();
//   };
// 
//   $authorCells
//     .addClass('clickable')
//     .hover(showTooltip, hideTooltip)
//     .mousemove(positionTooltip)
//     .click(function(event) {
//       var authorName = $(this).text();
//       $authorCells.each(function(index) {
//         if (authorName == $(this).text()) {
//           $(this).parent().toggleClass('highlight');
//         }
//         else {
//           $(this).parent().removeClass('highlight');
//         }
//       });
//     });
// });

// Step 3
// $(document).ready(function() {
//   var $authorCells = $('table.striped td:nth-child(3)');
//   var $tooltip = $('<div id="tooltip"></div>').appendTo('body');
//   
//   var positionTooltip = function(event) {
//     var tPosX = event.pageX;
//     var tPosY = event.pageY + 20;
//     $tooltip.css({top: tPosY, left: tPosX});
//   };
//   var showTooltip = function(event) {
//     var authorName = $(this).text();
//     var action = 'Highlight';
//     if ($(this).parent().is('.highlight')) {
//       action = 'Unhighlight';
//     }
//     $tooltip
//       .text(action + ' all articles by ' + authorName)
//       .show();
//     positionTooltip(event);
//   };
//   var hideTooltip = function() {
//     $tooltip.hide();
//   };
// 
//   $authorCells
//     .addClass('clickable')
//     .hover(showTooltip, hideTooltip)
//     .mousemove(positionTooltip)
//     .click(function(event) {
//       var authorName = $(this).text();
//       $authorCells.each(function(index) {
//         if (authorName == $(this).text()) {
//           $(this).parent().toggleClass('highlight');
//         }
//         else {
//           $(this).parent().removeClass('highlight');
//         }
//       });
//       showTooltip.call(this, event);
//     });
// });

// Example: Collapsing and Expanding
// $(document).ready(function() {
//   var collapseIcon = '../images/bullet_toggle_minus.png';
//   var collapseText = 'Collapse this section';
//   var expandIcon = '../images/bullet_toggle_plus.png';
//   var expandText = 'Expand this section';
//   $('table.collapsible tbody').each(function() {
//     var $section = $(this);
//     $('<img />').attr('src', collapseIcon)
//       .attr('alt', collapseText)
//       .prependTo($section.find('th'))
//       .addClass('clickable')
//       .click(function() {
//         if ($section.is('.collapsed')) {
//           $section.removeClass('collapsed')
//             .find('tr:not(:has(th))').fadeIn('slow');
//           $(this).attr('src', collapseIcon)
//             .attr('alt', collapseText);
//         }
//         else {
//           $section.addClass('collapsed')
//             .find('tr:not(:has(th))').fadeOut('fast');
//           $(this).attr('src', expandIcon)
//             .attr('alt', expandText);
//         }
//       });
//   });
// });

// Example: Filtering
// Step 1
// $(document).ready(function() {
//   $('table.filterable').each(function() {
//     var $table = $(this);
// 
//     $table.find('th').each(function(column) {
//       if ($(this).is('.filter-column')) {
//         var $filters = $('<div class="filters"></div>');
//         $('<h3></h3>')
//           .text('Filter by ' + $(this).text() + ':')
//           .appendTo($filters);
//         $filters.insertBefore($table);
//       }
//     });
//   });
// });

// Step 2
// $(document).ready(function() {
//   $('table.filterable').each(function() {
//     var $table = $(this);
// 
//     $table.find('th').each(function(column) {
//       if ($(this).is('.filter-column')) {
//         var $filters = $('<div class="filters"></div>');
//         $('<h3></h3>')
//           .text('Filter by ' + $(this).text() + ':')
//           .appendTo($filters);
//           
//         var keywords = ['conference', 'release'];
//         $.each(keywords, function(index, keyword) {
//           $('<div class="filter"></div>').text(keyword)
//             .bind('click', {key: keyword}, function(event) {
//               $('tr:not(:has(th))', $table).each(function() {
//                 var value = $('td', this).eq(column).text();
//                 if (value == event.data['key']) {
//                   $(this).show();
//                 }
//                 else {
//                   $(this).hide();
//                 }
//               });
//               $(this).addClass('active')
//                 .siblings().removeClass('active');
//             }).addClass('clickable').appendTo($filters);
//         });
//       
//         $filters.insertBefore($table);
//       }
//     });
//   });
// });

// Step 3
// $(document).ready(function() {
//   $('table.filterable').each(function() {
//     var $table = $(this);
// 
//     $table.find('th').each(function(column) {
//       if ($(this).is('.filter-column')) {
//         var $filters = $('<div class="filters"></div>');
//         $('<h3></h3>')
//           .text('Filter by ' + $(this).text() + ':')
//           .appendTo($filters);
//         
//         $('<div class="filter">all</div>').click(function() {
//           $table.find('tbody tr').show();
//           $(this).addClass('active')
//             .siblings().removeClass('active');
//         }).addClass('clickable active').appendTo($filters);
// 
//         var keywords = {};
//         $table.find('td:nth-child(' + (column + 1) + ')')
//           .each(function() {
//             keywords[$(this).text()] = $(this).text();
//           });        
// 
//         $.each(keywords, function(index, keyword) {
//           $('<div class="filter"></div>').text(keyword)
//             .bind('click', {key: keyword}, function(event) {
//               $('tr:not(:has(th))', $table).each(function() {
//                 var value = $('td', this).eq(column).text();
//                 if (value == event.data['key']) {
//                   $(this).show();
//                 }
//                 else {
//                   $(this).hide();
//                 }
//               });
//               $(this).addClass('active')
//                 .siblings().removeClass('active');
//             }).addClass('clickable').appendTo($filters);
//         });
//       
//         $filters.insertBefore($table);
//       }
//     });
//   });
// });

// Step 4
// $(document).ready(function() {
//   $('table.striped').bind('stripe', function() {
//     $('tbody', this).each(function() {
//       $(this).find('tr:visible:not(:has(th))')
//         .removeClass('odd').addClass('even')
//         .filter(function(index) {
//           return (index % 6) < 3;
//         }).removeClass('even').addClass('odd');
//     });
//   }).trigger('stripe');
// });

// $(document).ready(function() {
//   $('table.filterable').each(function() {
//     var $table = $(this);
// 
//     $table.find('th').each(function(column) {
//       if ($(this).is('.filter-column')) {
//         var $filters = $('<div class="filters"></div>');
//         $('<h3></h3>')
//           .text('Filter by ' + $(this).text() + ':')
//           .appendTo($filters);
//         
//         $('<div class="filter">all</div>').click(function() {
//           $table.find('tbody tr').show();
//           $(this).addClass('active')
//             .siblings().removeClass('active');
//           $table.trigger('stripe');
//         }).addClass('clickable active').appendTo($filters);
// 
//         var keywords = {};
//         $table.find('td:nth-child(' + (column + 1) + ')')
//           .each(function() {
//             keywords[$(this).text()] = $(this).text();
//           });        
// 
//         $.each(keywords, function(index, keyword) {
//           $('<div class="filter"></div>').text(keyword)
//             .bind('click', {key: keyword}, function(event) {
//               $('tr:not(:has(th))', $table).each(function() {
//                 var value = $('td', this).eq(column).text();
//                 if (value == event.data['key']) {
//                   $(this).show();
//                 }
//                 else {
//                   $(this).hide();
//                 }
//               });
//               $(this).addClass('active')
//                 .siblings().removeClass('active');
//               $table.trigger('stripe');
//             }).addClass('clickable').appendTo($filters);
//         });
//       
//         $filters.insertBefore($table);
//       }
//     });
//   });
// });


// Finished code: Highlighting, Tooltips, Collapsing, and Filtering

$(document).ready(function() {
  $('table.striped').bind('stripe', function() {
    $('tbody', this).each(function() {
      $(this).find('tr:visible:not(:has(th))')
        .removeClass('odd').addClass('even')
        .filter(function(index) {
          return (index % 6) < 3;
        }).removeClass('even').addClass('odd');
    });
  }).trigger('stripe');
});

$(document).ready(function() {
  var $authorCells = $('table.striped td:nth-child(3)');
  var $tooltip = $('<div id="tooltip"></div>').appendTo('body');
  
  var positionTooltip = function(event) {
    var tPosX = event.pageX;
    var tPosY = event.pageY + 20;
    $tooltip.css({top: tPosY, left: tPosX});
  };
  var showTooltip = function(event) {
    var authorName = $(this).text();
    var action = 'Highlight';
    if ($(this).parent().is('.highlight')) {
      action = 'Unhighlight';
    }
    $tooltip
      .text(action + ' all articles by ' + authorName)
      .show();
    positionTooltip(event);
  };
  var hideTooltip = function() {
    $tooltip.hide();
  };

  $authorCells
    .addClass('clickable')
    .hover(showTooltip, hideTooltip)
    .mousemove(positionTooltip)
    .click(function(event) {
      var authorName = $(this).text();
      $authorCells.each(function(index) {
        if (authorName == $(this).text()) {
          $(this).parent().toggleClass('highlight');
        }
        else {
          $(this).parent().removeClass('highlight');
        }
      });
      showTooltip.call(this, event);
    });
});

$(document).ready(function() {
  var collapseIcon = '../images/bullet_toggle_minus.png';
  var collapseText = 'Collapse this section';
  var expandIcon = '../images/bullet_toggle_plus.png';
  var expandText = 'Expand this section';
  $('table.collapsible tbody').each(function() {
    var $section = $(this);
    $('<img />').attr('src', collapseIcon)
      .attr('alt', collapseText)
      .prependTo($section.find('th'))
      .addClass('clickable')
      .click(function() {
        if ($section.is('.collapsed')) {
          $section.removeClass('collapsed')
            .find('tr:not(:has(th)):not(.filtered)')
            .fadeIn('fast');
          $(this).attr('src', collapseIcon)
            .attr('alt', collapseText);
        }
        else {
          $section.addClass('collapsed')
            .find('tr:not(:has(th))')
            .fadeOut('fast', function() {
              $(this).css('display', 'none');
            });
          $(this).attr('src', expandIcon)
            .attr('alt', expandText);
        }
        $section.parent().trigger('stripe');
      });
  });
});

$(document).ready(function() {
  $('table.filterable').each(function() {
    var $table = $(this);

    $table.find('th').each(function(column) {
      if ($(this).is('.filter-column')) {
        var $filters = $('<div class="filters"></div>');
        $('<h3></h3>')
          .text('Filter by ' + $(this).text() + ':')
          .appendTo($filters);
        
        $('<div class="filter">all</div>').click(function() {
          $table.find('tbody tr').removeClass('filtered');
          $(this).addClass('active')
            .siblings().removeClass('active');
          $table.trigger('stripe');
        }).addClass('clickable active').appendTo($filters);

        var keywords = {};
        $table.find('td:nth-child(' + (column + 1) + ')')
          .each(function() {
            keywords[$(this).text()] = $(this).text();
          });        

        $.each(keywords, function(index, keyword) {
          $('<div class="filter"></div>').text(keyword)
            .bind('click', {key: keyword}, function(event) {
              $('tr:not(:has(th))', $table).each(function() {
                var value = $('td', this).eq(column).text();
                if (value == event.data['key']) {
                  $(this).removeClass('filtered');
                }
                else {
                  $(this).addClass('filtered');
                }
              });
              $(this).addClass('active')
                .siblings().removeClass('active');
              $table.trigger('stripe');
            }).addClass('clickable').appendTo($filters);
        });
      
        $filters.insertBefore($table);
      }
    });
  });
});
