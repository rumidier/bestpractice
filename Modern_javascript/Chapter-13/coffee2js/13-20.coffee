$ ->
  setTimeout ->
    value = $('select > option:selected').val()
    alert value
  1000
