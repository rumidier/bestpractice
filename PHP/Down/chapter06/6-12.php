<?
	session_start();

	session_name('sess_name');
	$_SESSION['name']='brown';
	//���� ������ ��� �����Ѵ�.
	session_unset();
	//������ �����Ѵ�.
	session_destroy();
	//���� ���� ���
	print_r($_SESSION);
?>