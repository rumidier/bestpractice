<?
	$user = array(
		"brown"=>"brown1234",
		"admin"=>"admin1234",
		"guest"=>"guest1234"
	);

	if ($_POST['userid'] && $_POST['userpw']==$user[$_POST['userid']])
	{
		echo "�ȳ��ϼ���. {$_POST['userid']} ��.<BR>";
	}
	else
	{
		echo "�� �������� ����� ������ �ʿ��մϴ�.";
		exit;
	}
?>