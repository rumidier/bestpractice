<?
	session_start();
	if (empty($_SESSION[userid])) die("이 페이지는 사용자 인증이 필요합니다.");
?>