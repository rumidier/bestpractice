$(document).ready(function() {
  $('div.chapter a[href*=wikipedia]').each(function(index) {
    var $thisLink = $(this);
    $(this).attr({
      'rel': 'external',
      'id': 'wikilink-' + index,
      'title': $thisLink.text() + '에 대한 자세한 정보는 위키 피디아에 있습니다.'
    });
  });

  $('<a href="#top">맨 앞으로 돌아가기</a>').insertAfter('div.chapter p:gt(4)');
  $('<a id="top" name="top"></a>').prependTo('body');

  $('<ol id="notes"></ol>').insertAfter('div.chapter');
  $('span.footnote').each(function(index) {
    $(this).before('<a href="#foot-note-' + (index+1) +
      '" id="context-' + (index+1) + '" class="context"><sup>'
      + (index+1) + '</sup></a>')
    .appendTo('#notes')
    .append( '&nbsp;(<a href="#context-' + (index+1) + '">context </a>)' )
    .wrap('<li id="foot-note-' + (index+1) + '"></li>');
  });
});

//$(document).ready(function() {
//  $('div.chapter p:eq(0)').clone().insertBefore('div.chapter');
//});

$(document).ready(function() {
  $('span.pull-quote').each(function(index) {
    var $parentParagraph = $(this).parent('p');
    $parentParagraph.css('position', 'relative');
    var $clonedCopy = $(this).clone();
    $clonedCopy
    .addClass('pulled')
    .find('span.drop')
      .html('&hellip;')
    .end()
    .prependTo($parentParagraph)
    .wrap('<div class="pulled-wrapper"></div>');
    var clonedText = $clonedCopy.text();
    $clonedCopy.html(clonedText);
  });
});
