<?
if (!isset($_SERVER['PHP_AUTH_USER']) || $_COOKIE['login'] != "1") {

	//�� �������� ����� ����
	$realm = "�α��� �ϰ��� �ϴ� ���̵�� ��й�ȣ�� �Է��ϰų� �α׾ƿ���
	�Ϸ��� ���� �Է� ���� ���� Ȯ���� Ŭ���ϼ���.";
	header("WWW-Authenticate: Basic realm=\"$realm\"");
	header('HTTP/1.0 401 Unauthorized');
	setcookie ("login", "1");
	
	//��� ��ư�� ������ ���
	echo "<meta http-equiv=\"refresh\" content=\"0\">";
	exit;
}
else {
	//�α׾ƿ�
	if($_GET['logout'] == "1") {
		setcookie("login", "", 0);
		header("location: {$_SERVER['PHP_SELF']}");
		exit;
	}

	//����� ���� ó��
	if($_SERVER['PHP_AUTH_USER'] != "brown" ||
	$_SERVER['PHP_AUTH_PW'] != "1234") {
		//����� ���� ���� ��
		setcookie ("login", "0");
		echo "�� �������� ����� ������ �ʿ��մϴ�.<BR>";
		echo "<a href='{$PHP_SELF}'>�α���</a>�Ͻʽÿ�.";
		exit;
	}
}
?>