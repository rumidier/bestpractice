<?
	if (isset($_COOKIE['php'])) die("쿠키가 있습니다."); //쿠키가 이미 존재하는 경우
	setcookie("php");
	echo "쿠키 예제";
?>