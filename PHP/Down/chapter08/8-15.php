<?
	if ($_POST['userid']=="brown" && $_POST['userpw']=="brown1234")
	{
		echo "�ȳ��ϼ���. {$_POST['userid']} ��.<BR>";
	}
	else
	{
		echo "�� �������� ����� ������ �ʿ��մϴ�.";
		exit;
	}
?>