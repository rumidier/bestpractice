<?
	//인증이 되어 있지 않은 경우
	if (!$_SERVER['PHP_AUTH_USER'])
	{
		//인증이 되어있지 않으므로 인증을 시도한다.
		header('WWW-Authenticate: Basic realm="사용자 인증 시스템"');
		header('HTTP/1.0 401 Unauthorized');

		//인증에 실패하였을 경우 에러 메시지를 출력한다.
		echo '사용자 인증에 실패하였습니다.';
		exit;
	}
	else
	{
		echo "<p>사용자 이름 : {$_SERVER['PHP_AUTH_USER']}</p>";
		echo "<p>비밀번호 : {$_SERVER['PHP_AUTH_PW']}</p>";
	}
?>