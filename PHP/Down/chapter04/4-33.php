<?
	$original_string = "happybrown";
	$salt = "$1$brownsalt";
	$user_input = "happyblack";

	if (CRYPT_MD5 == 1)
	{
		$crypt_string = crypt($original_string, $salt);

		if ($crypt_string == crypt($user_input, $salt))
		{
			echo "��й�ȣ�� ��ġ�մϴ�.";
		}
		else
		{
			echo "��й�ȣ�� ��ġ���� �ʽ��ϴ�.";
		}
	}
	else
	{
		echo "MD5 ��ȣȭ �˰����� �������� �ʽ��ϴ�.";
	}
?>
