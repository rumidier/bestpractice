<?
	$result = setcookie('php' , 'Cool~' , time()+1000);
	if ($result)
		echo '��Ű ���� �Ϸ�';
	else
		echo '��Ű ���� ����';
?>