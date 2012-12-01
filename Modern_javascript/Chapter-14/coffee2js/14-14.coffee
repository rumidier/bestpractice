xml = ''
xml += '<friends>'
xml += '    <friend>'
xml += '        <name>연하진</name>'
xml += '        <language>Ruby</language>'
xml += '    </friend>'
xml += '    <friend>'
xml += '        <name>윤명월</name>'
xml += '        <language>Basic</language>'
xml += '    </friend>'
xml += '    <friend>'
xml += '        <name>윤하린</name>'
xml += '        <language>C#</language>'
xml += '    </friend>'
xml += '</friends>'

$ ->
  xmlDoc = $.parseXML xml
  $(xmlDoc).find('friend').each (index) ->
    output = ''
    output += '<div>'
    output += '    <h1>' + $(this).find('name').text() + '</h1>'
    output += '    <p>' + $(this).find('language').text() + '</p>'
    output += '</div>'

    document.body.innerHTML += output
