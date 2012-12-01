$ ->
  callback = ->
    val = $('select > option:selected').val()
    alert(value)
  setTimeout callback
  1000
