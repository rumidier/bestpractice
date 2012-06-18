<?
	//폼을 통해서 파일이 전달된 경우
	if (is_uploaded_file($_FILES['userfile']['tmp_name'], 
	'./uploads_dir/' . $_FILES['userfile']['name'])) {
		echo "파일이 업로드 되었습니다.";
	} else {
		echo "임시 저장된 파일을 이동하는데 실패하였습니다.";
	}
?>