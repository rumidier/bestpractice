<?
	session_start();

	session_name('sess_name');
	$_SESSION['name']='brown';
	//세션 변수를 모두 제거한다.
	session_unset();
	//세션을 종료한다.
	session_destroy();
	//세션 변수 출력
	print_r($_SESSION);
?>