<?
if (!isset($_SERVER['PHP_AUTH_USER'])) {
	//�� �������� ����� ����
	header('WWW-Authenticate: Basic realm="login"');
	header('HTTP/1.0 401 Unauthorized');

	//��� ��ư�� ������ ���
	echo "�� �������� ����� ������ �ʿ��մϴ�.<BR>";
	echo "<a href='{$PHP_SELF}'>�α���</a>�Ͻʽÿ�.";
	exit;
}
else {
	//�α׾ƿ�
	if($_GET['logout'] == "1") {
		echo "<script>\n";
		echo " document.execCommand('ClearAuthenticationCache') \n";
		echo "</script>\n";
		echo "�α׾ƿ� �Ǿ����ϴ�.<BR>";
		echo "<a href='{$PHP_SELF}'>�α���</a>�Ͻʽÿ�.";
		exit;
	}

	//����� ���� ó��
	if($_SERVER['PHP_AUTH_USER'] == "brown" && $_SERVER['PHP_AUTH_
	PW']== "1234") {
		//�α����� �� �� �޽��� ���
		echo "�ȳ��ϼ���. {$_SERVER['PHP_AUTH_USER']}��<BR>";
		echo "<a href='".$_SEVER['PHP_SELF']."?logout=1'>�α׾ƿ�</a>";
	}
	else {
		//����� ���� ���� ��
		echo "�� �������� ����� ������ �ʿ��մϴ�.<BR>";
		echo "<a href='{$PHP_SELF}'>�α���</a>�Ͻʽÿ�.";
		exit;
	}
}
?>