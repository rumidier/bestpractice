<?php

// 검색 문자열을 넘겨받지 못하면, 
if(empty($_GET['state'])) {
    echo "No State Sent";
} else {
    // 검색의 처음과 끝에서 공백 문자를 제거한다.
    $search = trim($_GET['state']);
    switch($search) {
      case "MO" :
        $result = "<option value='St. Louis'>St. Louis</option>" .
                  "<option value='Kansas City'>Kansas City</option>";
        break;
     case "WA" :
       $result = "<option value='Seattle'>Seattle</option>" .
                 "<option value='Spokane'>Spokane</option>" .
                 "<option value='Olympia'>Olympia</option>";
       break;
     case "CA" :
       $result = "<option value='San Francisco'>San Francisco</option>" .
                 "<option value='Los Angeles'>Los Angeles</option>" .
                 "<option value='Web 2.0 City'>Web 2.0 City</option>" .
                 "<option value='barcamp'>BarCamp</option>";
       break;
     case "ID" :
       $result = "<option value='Boise'>Boise</option>";
       break;
     default :
       $result = "No Cities Found";
       break;
     }
   echo $result;
}
?>
