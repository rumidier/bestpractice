<?
	include "db_info.php";

	//����ڰ� �Է��� ���̵��� ��й�ȣ�� �˻��Ѵ�.
	$query = "SELECT userpw FROM users WHERE userid = '{$_POST[userid]}'";
	$result = mysql_query($query, $conn);
	$row = mysql_fetch_array($result);

	//����ڰ� �Է��� ��й�ȣ�� ���Ѵ�.
	if (!empty($row) && ($row[userpw] == $_POST[userpw]))
	{
		echo "�ȳ��ϼ���. {$_POST['userid']} ��.<BR>";
	}
	else
	{
		echo "�� �������� ����� ������ �ʿ��մϴ�.";
		exit;
	}
?>