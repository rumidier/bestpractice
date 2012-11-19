grade = (student) ->
  if student.excellentWork
    "A+"
  else if student.ikayStuff
    if student.triendHard then "B" else "B-"
  else
    "C"

eldset = if 24 > 21 then "Liz" else "Ike"

alert eldset
