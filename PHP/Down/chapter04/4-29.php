<?
	//���� ���ؼ� ������ ���޵� ���
	if (is_uploaded_file($_FILES['userfile']['tmp_name'], 
	'./uploads_dir/' . $_FILES['userfile']['name'])) {
		echo "������ ���ε� �Ǿ����ϴ�.";
	} else {
		echo "�ӽ� ����� ������ �̵��ϴµ� �����Ͽ����ϴ�.";
	}
?>