<?
	include "db_info.php";

	//����ڰ� �Է��� ���̵�� ��й�ȣ�� ���� ���ڵ��� ���� �˻��Ѵ�.
	$query = "SELECT count(*) FROM users WHERE userid = '{$_POST[userid]}'
	and userpw = '{$_POST[userpw]}'";
	$result = mysql_query($query, $conn);
	$row = mysql_fetch_row($result);

	//�˻� ����� 1�̸� ���������� �α����� �ȴ�.
	if ($row[0] == 1)
	{
		//�α��� ���¸� �����ϱ� ���� ��Ű�� �߱��Ѵ�.
		setcookie("userid",$_POST['userid'],0,"/");
		echo "�ȳ��ϼ���. {$_POST['userid']} ��.<BR>";
	}
	else
	{
		echo "�� �������� ����� ������ �ʿ��մϴ�.";
		exit;
	}
?>