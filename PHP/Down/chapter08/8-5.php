<?
if (!isset($_SERVER['PHP_AUTH_USER'])) {
	//웹 브라우저의 헤더로 전송
	header('WWW-Authenticate: Basic realm="login"');
	header('HTTP/1.0 401 Unauthorized');

	//취소 버튼을 눌렀을 경우
	echo "이 페이지는 사용자 인증이 필요합니다.<BR>";
	echo "<a href='{$PHP_SELF}'>로그인</a>하십시오.";
	exit;
}
else {
	//로그아웃
	if($_GET['logout'] == "1") {
		echo "<script>\n";
		echo " document.execCommand('ClearAuthenticationCache') \n";
		echo "</script>\n";
		echo "로그아웃 되었습니다.<BR>";
		echo "<a href='{$PHP_SELF}'>로그인</a>하십시오.";
		exit;
	}

	//사용자 인증 처리
	if($_SERVER['PHP_AUTH_USER'] == "brown" && $_SERVER['PHP_AUTH_
	PW']== "1234") {
		//로그인이 된 후 메시지 출력
		echo "안녕하세요. {$_SERVER['PHP_AUTH_USER']}님<BR>";
		echo "<a href='".$_SEVER['PHP_SELF']."?logout=1'>로그아웃</a>";
	}
	else {
		//사용자 인증 실패 후
		echo "이 페이지는 사용자 인증이 필요합니다.<BR>";
		echo "<a href='{$PHP_SELF}'>로그인</a>하십시오.";
		exit;
	}
}
?>