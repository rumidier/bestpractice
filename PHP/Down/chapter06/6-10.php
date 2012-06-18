<?
	session_start();
	//세션에 저장된 변수를 모두 제거한다.
	session_unset();
	//세션을 종료한다.
	session_destroy();
?>