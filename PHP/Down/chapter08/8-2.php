<?
	$user = "brown";
	$pass = "1234";

	if ( $_SERVER['PHP_AUTH_USER']==$user &&
	$_SERVER['PHP_AUTH_PW']==$pass )
	{
		echo "�α��εǾ����ϴ�.";
	}
	else {
		header('WWW-Authenticate: Basic realm="����� ���� �ý���"');
		header('HTTP/1.0 401 Unauthorized');
		echo '����� ������ �����Ͽ����ϴ�.';
		exit;
	}
?>