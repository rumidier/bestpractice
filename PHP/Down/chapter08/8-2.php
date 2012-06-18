<?
	$user = "brown";
	$pass = "1234";

	if ( $_SERVER['PHP_AUTH_USER']==$user &&
	$_SERVER['PHP_AUTH_PW']==$pass )
	{
		echo "로그인되었습니다.";
	}
	else {
		header('WWW-Authenticate: Basic realm="사용자 인증 시스템"');
		header('HTTP/1.0 401 Unauthorized');
		echo '사용자 인증에 실패하였습니다.';
		exit;
	}
?>