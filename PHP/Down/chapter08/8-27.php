<?
	session_start();
	if (empty($_SESSION[userid]))
	{
		die("�� �������� ����� ������ �ʿ��մϴ�.");
	}
?>
���������� �α��� �Ͽ����ϴ�.<BR>
���ӵ� ���̵�� <?=$_SESSION[userid]?>�Դϴ�.