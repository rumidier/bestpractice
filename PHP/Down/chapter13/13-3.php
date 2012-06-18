<?
	if (empty($_FILES['upfile']['name']))
	{
		echo "업로드된 파일이 없습니다.";
		exit;
	}
	move_uploaded_file($_FILES['upfile']['tmp_name'], './uploads_dir/' . $_FILES['upfile']['name']);
	echo "파일이 업로드 되었습니다.";
?>