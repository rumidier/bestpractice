<?
	$user = array(
		"brown"=>"brown1234",
		"admin"=>"admin1234",
		"guest"=>"guest1234"
	);

	if ($_POST['userid'] && $_POST['userpw']==$user[$_POST['userid']])
	{
		echo "안녕하세요. {$_POST['userid']} 님.<BR>";
	}
	else
	{
		echo "이 페이지는 사용자 인증이 필요합니다.";
		exit;
	}
?>