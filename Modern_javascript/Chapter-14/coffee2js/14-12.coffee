$ ->
  $('h1').each ->
    $(@).css 'background', 'Orange' if $(@).is('.select')
