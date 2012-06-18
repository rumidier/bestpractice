/***************************************
   Contact form
-------------------------------------- */

$(document).ready(function() {

  // Enhance style of form elements.

  $('legend').each(function(index) {
    $(this).replaceWith('<h3>' + $(this).text() + '</h3>');
  });
  // $('legend').wrapInner('<span></span>');

  var requiredFlag = ' * ';
  var conditionalFlag = ' ** ';
  var requiredKey = $('input.required:first').next('span').text();
  var conditionalKey = $('input.conditional:first').next('span').text();
  
  requiredKey = requiredFlag + requiredKey.replace(/^\((.+)\)$/,'$1');
  conditionalKey = conditionalFlag + conditionalKey.replace(/\((.+)\)/,'$1');

  $('<p></p>')
    .addClass('field-keys')
    .append(requiredKey + '<br />')
    .append(conditionalKey)
    .insertBefore('#contact');

  $('form :input')
    .filter('.required')
      .next('span').text(requiredFlag).end()
      .prev('label').addClass('req-label').end()
    .end()
    .filter('.conditional')
      .next('span').text(conditionalFlag);

  // Checkbox toggle: conditional text inputs.
  
  $('input.conditional').next('span').andSelf().hide()
  .end().end()
  .each(function() {
    var $thisInput = $(this);
    var $thisFlag = $thisInput.next('span');
    $thisInput.prev('label').find(':checkbox')
    .attr('checked', false)
    .click(function() {
      if (this.checked) {
        $thisInput.show().addClass('required');
        $thisFlag.show();
        $(this).parent('label').addClass('req-label');
      } else {
        $thisInput.hide().removeClass('required').blur();
        $thisFlag.hide();
        $(this).parent('label').removeClass('req-label');
      }
    });
  });

  // Validate fields on blur.
  
  $('form :input').blur(function() {
    $(this).parents('li:first').removeClass('warning')
    .find('span.error-message').remove();
    
    if ($(this).hasClass('required')) {
      var $listItem = $(this).parents('li:first');
      if (this.value == '') {
        var errorMessage = 'This is a required field';
        if ($(this).is('.conditional')) {
          errorMessage += ', when its related ' + 
                                  'checkbox is checked';
        }
        $('<span></span>')
          .addClass('error-message')
          .text(errorMessage)
          .appendTo($listItem);
        $listItem.addClass('warning');
      }
    }

    if (this.id == 'email') {
      var $listItem = $(this).parents('li:first');
      if ($(this).is(':hidden')) {
        this.value = '';
      }
      if (this.value != '' && 
      !/.+@.+\.[a-zA-Z]{2,4}$/.test(this.value)) {
        var errorMessage = 'Please use proper e-mail format'
                                  + ' (e.g. joe@example.com)';
        $('<span></span>')
          .addClass('error-message')
          .text(errorMessage)
          .appendTo($listItem);
        $listItem.addClass('warning');
      }
    }
  });

  // Validate form on submit.
  
  $('form').submit(function() {
    $('#submit-message').remove();
    $(':input.required').trigger('blur');
    var numWarnings = $('.warning', this).length;
      if (numWarnings) {
        var fieldList = [];
        $('.warning label').each(function() {
          fieldList.push($(this).text());
        });
        $('<div></div>')
        .attr({
          'id': 'submit-message', 
          'class': 'warning'
        })
        .append('Please correct errors with the following ' + 
                                      numWarnings + ' fields:<br />')
        .append('&bull; ' + fieldList.join('<br />&bull; '))
        .insertBefore('#send');
      return false;
    };
  });

  // Checkboxes
  $('form :checkbox').removeAttr('checked');

  // Checkboxes with (un)check all.
  $('<li></li>')
  .html('<label><input type="checkbox" id="discover-all" />' + 
                                ' <em>check all</em></label>')
  .prependTo('li.discover > ul');
  $('#discover-all').click(function() {
    var $checkboxes = $(this) .parents('ul:first')
                                    .find(':checkbox');
    if (this.checked) {
      $(this).next().text(' un-check all');
      $checkboxes.attr('checked', true);
    } else {
      $(this).next().text(' check all');
      $checkboxes.attr('checked', '');
    };
  })
  .parent('label').addClass('checkall');
});



/***************************************
   Insert placeholder text
-------------------------------------- */

$(document).ready(function() {
  var $search = $('#search').addClass('overlabel');
  var $searchInput = $search.find('input');
  var $searchLabel = $search.find('label');
  
  if ($searchInput.val()) {
    $searchLabel.hide();
  }

  $searchInput
  .focus(function() {
    $searchLabel.hide();
  })
  .blur(function() {
    if (this.value == '') {
      $searchLabel.show();
    }
  });
  
  $searchLabel.click(function() {
    $searchInput.trigger('focus');
  });
});


/***************************************
   Autocomplete search field
-------------------------------------- */

$(document).ready(function() {
  var $autocomplete = $('<ul class="autocomplete"></ul>')
  .hide()
  .insertAfter('#search-text');
  var selectedItem = null;

  var setSelectedItem = function(item) {
    selectedItem = item;

    if (selectedItem === null) {
      $autocomplete.hide();
      return;
    }

    if (selectedItem < 0) {
      selectedItem = 0;
    }
    if (selectedItem >= $autocomplete.find('li').length) {
      selectedItem = $autocomplete.find('li').length - 1;
    }
    $autocomplete.find('li').removeClass('selected')
      .eq(selectedItem).addClass('selected');
    $autocomplete.show();
  };

  var populateSearchField = function() {
    $('#search-text').val($autocomplete
    .find('li').eq(selectedItem).text());
    setSelectedItem(null);
  };

  $('#search-text')
  .attr('autocomplete', 'off')
  .keyup(function(event) {
    if (event.keyCode > 40 || event.keyCode == 8) {
      // Keys with codes 40 and below are special (enter, arrow keys, escape, etc.).
      // Key code 8 is backspace.
      $.ajax({
        'url': '../search/autocomplete.php',
        'data': {'search-text': $('#search-text').val()},
        'dataType': 'json',
        'type': 'GET',
        'success': function(data) {
          if (data.length) {
            $autocomplete.empty();
            $.each(data, function(index, term) {
              $('<li></li>').text(term).appendTo($autocomplete).mouseover(function() {
                setSelectedItem(index);
              }).click(populateSearchField);
            });

            setSelectedItem(0);
          }
          else {
            setSelectedItem(null);
          }
        }
      });
    }
    else if (event.keyCode == 38 && 
                                 selectedItem !== null) {
      // User pressed up arrow.
      setSelectedItem(selectedItem - 1);
      event.preventDefault();
    }
    else if (event.keyCode == 40 && 
                                 selectedItem !== null) {
      // User pressed down arrow.
      setSelectedItem(selectedItem + 1);
      event.preventDefault();
    }
    
    else if (event.keyCode == 27 && selectedItem !== null) {
      // User pressed escape key.
      setSelectedItem(null);
    }
  }).keypress(function(event) {
    if (event.keyCode == 13 && selectedItem !== null) {
      // User pressed enter key.
      populateSearchField();
      event.preventDefault();
    }
  }).blur(function(event) {
    setTimeout(function() {
      setSelectedItem(null);
    }, 250);
  });
});


/***************************************
   Shopping cart
-------------------------------------- */
var json = {
    '0885370259223': 11,
    '0885370312546': 22,
    '0885370312553': 33,
    '0885370312560': 44,
    '4515479512832': 55,
    '4515479512849': 66,
    '4515479512856': 77,
    '0405972972018': 15,
    '0405972973015': 30,
    '9999910001591': 90,
    '0735858217729': 2500, 
    '1217010000657': 8,
    '1217010000817': 4,
    '0735858222631': 120,
    '0735858222662': 240,
    '1160010000205': 500,
    '1160010000304': 2000,
    '4540395600141': 128,
    '1190010000271': 100,
    '4534782920509': 200,
    '1111111111111': 101,
    '2222222222222': 202,
    '3333333333333': 303,
    '4444444444444': 404,
    '3860000000000': 386,
    '4860000000000': 486,
    '5860000000000': 586,
    '6860000000000': 686
  };
$(document).ready(function() {
    var totalCost = 112;
    $('.normalfont1').change(function(event) {
      totalCost = 0;
      $('input:radio:checked').each(function() {
	var $radio_val = $(this).val();
	$.each(json, function(index, entry) {
	  if (index == $radio_val) {
	    totalCost += entry;
	  }
	});
      });

      if ($(':selected').val()) {
	$.each(json, function(index, entry) {
	  if (index == $(':selected').val() ) {
	    totalCost += entry;
	  }
	});
      }

      $('input:checkbox:checked').each(function() {
	var $checkbox_val = $(this).val();
	$.each(json, function(index, entry) {
	  if (index == $checkbox_val) {
	    totalCost += entry;
	  }
	});
      });
      $('.subtotal .cost').text('$' + totalCost.toFixed(2));

      var taxRate = parseFloat($('.tax .price').text()) / 100;
      var tax = Math.ceil(totalCost * taxRate * 100) / 100;
      $('.tax .cost').text('$' + tax.toFixed(2));
      totalCost += tax;
      $('.shipping .quantity').text(String(totalQuantity));

      var shippingRate = parseFloat($('.shipping .price').text().replace(/^[^\d.]*/, ''));
      var shipping = totalQuantity * shippingRate;
      $('.shipping .cost').text('$' + shipping.toFixed(2));
      totalCost += shipping;
      $('.total .cost').text('$' + totalCost.toFixed(2));
    });
});
