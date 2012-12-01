$ ->
  object = { name: 'RintIanTta' }
  $.extend object, {
    gender: 'Male'
    part: 'Second Guitar'
  }

  output = ''
  $.each object, (key, item) ->
    output += "#{key}: #{item}\n"
  alert output
