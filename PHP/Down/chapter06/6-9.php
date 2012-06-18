<?
	session_start();

	//세션에 변수를 등록한다.
	$_SESSION['name'] = '조명진';
	$_SESSION['age'] = 29;

	//보기좋게 출력하기 위해서 <PRE> 태그를 사용한다.
	echo '<PRE>';
	//현재 세션에 저장된 변수를 출력한다.
	print_r($_SESSION);
	//세션 변수를 제거한다.
	unset($_SESSION['age']);
	//현재 세션에 저장된 변수를 출력한다.
	print_r($_SESSION);
	echo '</PRE>';
?>