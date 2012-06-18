<?
if (!isset($_SERVER['PHP_AUTH_USER']) || $_COOKIE['login'] != "1") {

	//웹 브라우저의 헤더로 전송
	$realm = "로그인 하고자 하는 아이디와 비밀번호를 입력하거나 로그아웃을
	하려면 값을 입력 하지 말고 확인을 클릭하세요.";
	header("WWW-Authenticate: Basic realm=\"$realm\"");
	header('HTTP/1.0 401 Unauthorized');
	setcookie ("login", "1");
	
	//취소 버튼을 눌렀을 경우
	echo "<meta http-equiv=\"refresh\" content=\"0\">";
	exit;
}
else {
	//로그아웃
	if($_GET['logout'] == "1") {
		setcookie("login", "", 0);
		header("location: {$_SERVER['PHP_SELF']}");
		exit;
	}

	//사용자 인증 처리
	if($_SERVER['PHP_AUTH_USER'] != "brown" ||
	$_SERVER['PHP_AUTH_PW'] != "1234") {
		//사용자 인증 실패 후
		setcookie ("login", "0");
		echo "이 페이지는 사용자 인증이 필요합니다.<BR>";
		echo "<a href='{$PHP_SELF}'>로그인</a>하십시오.";
		exit;
	}
}
?>