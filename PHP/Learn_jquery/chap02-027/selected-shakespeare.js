// Add a class to top-level list items.
$(document).ready(function() {
  $('#selected-plays > li').addClass('horizontal');
  $('#selected-plays li:not(.horizontal)').addClass('sub-level');
});

// Add a class to all mailto and pdf links on the page.
$(document).ready(function() {
  $('a[href^="mailto:"]').addClass('mailto');
  $('a[href$=".pdf"]').addClass('pdflink');
  $('a[href*="mysite.com"]').addClass('mysite');
});

// Give classes to even and odd table rows for zebra striping.
$(document).ready(function() {
  $('tr:not(:has(th)):even').addClass('even');
  $('tr:not(:has(th)):odd').addClass('odd');
  $('td:contains("Henry")').siblings().addClass('highlight');
});


