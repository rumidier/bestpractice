$(document).ready(function() {
  $('fieldset').each(function() {
    var heading = $('legend', this).remove().text();
    $('<h3></h3>')
    .text(heading)
    .prependTo( this );
  });

  var requiredFlag = '*';
  var requiredKey = $('input.required:first').next('span').text();
  requiredKey = requiredFlag + requiredKey
                .replace(/^\((.+)\)$/,"$1");
  var conditionalFlag = '**';
  var conditionalKey = $('input.conditional:first').next('span').text();
  conditionalKey = conditionalFlag + conditionalKey
                .replace(/^\((.+)\)$/,"$1");

  $('form :input').filter('.required')
  .next('span').text(requiredFlag).end()
  .prev('label').addClass('req-label');

  $('form :input').filter('.conditional')
  .next('span').text(conditionalFlag).end()

  $('<p></p>')
  .addClass('field-keys')
  .append(requiredKey + '<br />')
  .append(conditionalKey)
  .insertBefore('#contact');

  $('input.conditional').hide().next('span').hide();
  $('input.conditional').each(function() {
    var $thisInput = $(this);
    var $thisFlag  = $thisInput.next('span').hide();
    $thisInput.prev('label').find(':checkbox').click(function() {
      if (this.checked) {
        $thisInput.show().addClass('required');
	$thisFlag.show();
	$(this).parent('label').addClass('req-label');
      } else {
        $thisInput.hide().removeClass('required').blur();
	$thisFlag.hide();
	$(this).parent('label').removeClass('req-label');
      };
    });
  });

  $('form :input').blur(function() {
    $(this).parents('li:first').removeClass('warnig')
    .find('span.error-message').remove();

    if ($(this).is('.required')) {
      var $listItem = $(this).parents('li:first');
      if (this.value == '') {
        var errorMessage = 'This is a required field';
	if ($(this).is('.conditional')) {
	  errorMessage += ', when its related checkbox is checked';
	};
	$('<span></span>')
	.addClass('error-message')
	.text(errorMessage)
	.appendTo($listItem);
	$listItem.addClass('warning');
      };
    };

  if ($(this).is('#email')) {
    var $listItem = $(this).parents('li:first');
    if (this.value != '' && !/.+@.+\.[a-zA-Z]{2,4}$/
	.test(this.value)) {
        var errorMessage = 'Please use proper e-mail format' + '(eg.joe@example.com)';
	$('<span></span>')
	  .addClass('error-message')
	  .text(errorMessage)
	  .appendTo($listItem);
	$listItem.addClass('warning');
      };
    };
  });

  $('form').submit(function() {
    $('#submit-message').remove();
    $(':input.required').trigger('blur');
    var numWarnings = $('.warning', this).length;
    if (numWarnings) {
    alert('asdf');
      var fieldList = [];
      $('.warning label').each(function() {
	fieldList.push($(this).text());
      });

      $('<div></div>').attr({'id': 'submit-message','class':'warning'})
      .append('Please correct errors with the following ' + numWarnings + ' fields:<br />')
      .append('&bull; ' + fieldList.join('<br />&bull; '))
      .insertBefore('#send');
      return false;
    };
  });

  $('form :checkbox').removeAttr('checked');

  $('<li></li>')
  .html('<label><input type="checkbox" id="discover-all" />' + '<em>check all</em></label>')
  .prependTo('li.discover > ul');
  $('#discover-all').click(function() {
    var $checkboxes = $(this).parents('ul:first').find(':checkbox');
    if (this.checked) {
      $(this).next().text(' un-check all');
      $checkboxes.attr('checked', 'true');
    } else {
      $(this).next().text(' check all');
      $checkboxes.attr('checked', '');
    };
  })
  .parent('label')
  .css({
    borderBottom: '1px solid #ccc',
    color: '#777',
    lineHeight: 2
  });
});

$(document).ready(function() {
  var searchLabel = $('#search label').remove().text();
  $('#search-text').addClass('placeholder').val(searchLabel)
  .focus(function() {
    if (this.value == searchLabel) {
      $(this).removeClass('placeholder').val('');
    };
  }).blur(function() {
    if (this.value == '') {
      $(this).addClass('placeholder').val(searchLabel);
    };
  });

  $('#search').submit(function() {
    if ($('#search-text').val() == searchLabel) {
      $('#search-text').val('');
    }
  });

  var $autocomplete = $('<ul class="autocomplete"></ul>').hide()
		      .insertAfter('#search-text');
  var selectedItem = null;

  var setSelectedItem = function(item) {
    selectedItem = item;
    if (selectedItem == null) {
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
    $('#search-text').val($autocomplete.find('li').eq(selectedItem).text());
    setSelectedItem(null);
  };
  $('#search-text').attr('autocomplete', 'off').keyup(function(event) {
    if (event.keyCode > 40 || event.keyCode == 8) {
      $.ajax({
	'url': '/Learn_jquery/search/autocomplete.php',
	'data': {'search-text': $('#search-test').val()},
	'dataType': 'json',
	'type': 'POST',
	'success': function(data) {
	  if (data.length) {
	    $autocomplete.empty();
	    $.each(data, function(index, term) {
	      $('<li></li>').text(term)
	      .appendTo($autocomplete).mouseover(function() {
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
    else if (event.keyCode == 38 && selectedItem !== null) {
      setSelectedItem(selectedItem - 1);
      event.preventDefault();
    }
    else if (event.keyCode == 40 && selectedItem !== null) {
      setSelectedItem(selectedItem + 1);
      event.preventDefault();
    }
    else if (event.keyCode == 27 && selectedItem !== null) {
      setSelectedItem(null);
    }
  }).keypress(function(event) {
    if (event.keyCode == 13 && selectedItem !== null) {
    populaateSearchField();
    event.preventDefault();
    }
  }).blur(function(event) {
    setTimeout(function() {
      setSelectedItem(null);
    }, 250);
  });
}); 
