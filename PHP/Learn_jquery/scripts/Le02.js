$(document).ready(function() {
    $('th').parent().addClass('table-heading');
    $('tr:not(:has(th)):even').addClass('even');
    $('tr:not(:has(th)):odd').addClass('odd');
    $('td:contains("Henry")').next().addClass('highlight');
    //$('td:contains("Henry")').siblings().addClass('highlight');
});
