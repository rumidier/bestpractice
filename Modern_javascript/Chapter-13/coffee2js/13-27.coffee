$ ->
  array = [
    {
      name: 'Hanbit Media'
      link: 'http://hanb.co.kr'
    }
    {
      name: 'Naver'
      link: 'http://naver.com'
    }
    {
      name: 'Daum'
      link: 'http://daum.net'
    }
    {
      name: 'Paran'
      link: 'http://paran.com'
    }
  ]

  $.each array, (index, item) ->
    document.body.innerHTML += "<a href=#{item.link}><h1>#{item.name}</h1></a>"
