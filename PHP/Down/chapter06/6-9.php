<?
	session_start();

	//���ǿ� ������ ����Ѵ�.
	$_SESSION['name'] = '������';
	$_SESSION['age'] = 29;

	//�������� ����ϱ� ���ؼ� <PRE> �±׸� ����Ѵ�.
	echo '<PRE>';
	//���� ���ǿ� ����� ������ ����Ѵ�.
	print_r($_SESSION);
	//���� ������ �����Ѵ�.
	unset($_SESSION['age']);
	//���� ���ǿ� ����� ������ ����Ѵ�.
	print_r($_SESSION);
	echo '</PRE>';
?>