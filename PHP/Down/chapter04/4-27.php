<?
	$_FILES['userfile']['tmp_name']= "somefile.txt";

	if (is_uploaded_file($_FILES['userfile']['tmp_name'])) {
		echo $_FILES['userfile']['tmp_name']." ������ ���ε� �Ǿ����ϴ�.";
	} else {
		echo $_FILES['userfile']['tmp_name']." ������ ���ε�� ������ �ƴմϴ�.";
	}
?>