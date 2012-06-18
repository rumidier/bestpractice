<?
#  if ($_POST['userid']=="brown" && $_POST['userpw'] == "brown1234")
#  {
#    echo "안녕하세요. {$_POST['userid']}님.<br />";
#  }
#  else
#  {
#    echo "이 페이지는 사용자 인증이 필요합니다.";
#    exit;
#  }
  $user = array(
            "brown"=>"brown1234",
            "admin"=>"admin1234",
            "guest"=>"guest1234"
	  );

  if (array_key_exists($_POST['userid'], $user) && $_POST['userpw'] == $user[$_POST['userid']])
  {
    echo "안녕하세요. {$_POST['userid']} 님.<br />";
  }
  else
  {
    echo "이 페이지는 사용자 인증이 필요합니다.";
    exit;
  }
?>
