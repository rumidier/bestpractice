<?
	//������ �Ǿ� ���� ���� ���
	if (!$_SERVER['PHP_AUTH_USER'])
	{
		//������ �Ǿ����� �����Ƿ� ������ �õ��Ѵ�.
		header('WWW-Authenticate: Basic realm="����� ���� �ý���"');
		header('HTTP/1.0 401 Unauthorized');

		//������ �����Ͽ��� ��� ���� �޽����� ����Ѵ�.
		echo '����� ������ �����Ͽ����ϴ�.';
		exit;
	}
	else
	{
		echo "<p>����� �̸� : {$_SERVER['PHP_AUTH_USER']}</p>";
		echo "<p>��й�ȣ : {$_SERVER['PHP_AUTH_PW']}</p>";
	}
?>