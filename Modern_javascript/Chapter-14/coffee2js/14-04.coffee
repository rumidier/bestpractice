$ ->
  $('h3').filter (index) ->
    index % 3 is 0
  .css {
    backgroundColor: 'Black',
    color: 'White'
  }
