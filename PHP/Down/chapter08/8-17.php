<?
	$user = array(
		"brown"=>"brown1234",
		"admin"=>"admin1234",
		"guest"=>"guest1234"
	);

	if (array_key_exists($_POST['userid'], $user) &&
	$_POST['userpw']==$user[$_POST['userid']])
	{
		echo "�ȳ��ϼ���. {$_POST['userid']} ��.<BR>";
	}
	else
	{
		echo "�� �������� ����� ������ �ʿ��մϴ�.";
		exit;
	}
?>