<?
	if (empty($_FILES['upfile']['name']))
	{
		echo "���ε�� ������ �����ϴ�.";
		exit;
	}
	move_uploaded_file($_FILES['upfile']['tmp_name'], './uploads_dir/' . $_FILES['upfile']['name']);
	echo "������ ���ε� �Ǿ����ϴ�.";
?>