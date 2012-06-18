<?
	if ($_POST['userid']=="brown" && $_POST['userpw']=="brown1234")
	{
		echo "안녕하세요. {$_POST['userid']} 님.<BR>";
	}
	else
	{
		echo "이 페이지는 사용자 인증이 필요합니다.";
		exit;
	}
?>