<?
	//������ ���̽� �����ϱ�
	include "db_info.php";

	$query = "INSERT INTO board 
	(id, name, email, pass, title, content,	wdate, ip, view)
	VALUES ('', '$name', '$email', '$pass', '$title', 
	'$comment',	now(), '$REMOTE_ADDR', 0)";
	$result=mysql_query($query, $conn);

	//�����ͺ��̽����� ���� ����
	mysql_close($conn);

	// �� �� ������ ��� ����Ʈ��..
	echo ("<meta http-equiv='Refresh' content='1; URL=list.php'>");
?>
<center>
<font size=2>���������� ����Ǿ����ϴ�.</font>