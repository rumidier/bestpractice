<?
	$_FILES['userfile']['tmp_name']= "somefile.txt";

	if (is_uploaded_file($_FILES['userfile']['tmp_name'])) {
		echo $_FILES['userfile']['tmp_name']." 파일이 업로드 되었습니다.";
	} else {
		echo $_FILES['userfile']['tmp_name']." 파일은 업로드된 파일이 아닙니다.";
	}
?>