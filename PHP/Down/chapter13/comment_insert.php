<?
	include_once "library.php";

	$_POST[name] = trim(strip_tags($_POST[name]));
	//�Է°� ����

	if (!$_POST[name]) ErrorMessage('�̸��� �Է��ϼ���.');
	if (!$_POST[pass]) ErrorMessage('��й�ȣ�� �Է��ϼ���.');
	if (!$_POST[comment]) ErrorMessage('������ �Է��ϼ���.');

	include_once "db_info.php";

	$query = " INSERT INTO comment (bid, name, pass, comment, ip) ";
	$query .= " VALUES ('{$_POST[bid]}','{$_POST[name]}',
	'{$_POST[pass]}','{$_POST[comment]}','$REMOTE_ADDR')";
	$result = mysql_query($query, $conn) 
	or ErrorMessage('������ �����ϴµ� �����Ͽ����ϴ�.');
?>
<meta http-equiv='Refresh' content='1; URL=read.php?id=<?=$_GET[id]?>'>
<center>������ ��ϵǾ����ϴ�.</center>
