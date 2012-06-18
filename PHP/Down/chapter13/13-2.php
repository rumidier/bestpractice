<?
	echo "파일명 : " . $_FILES['upfile']['name'] . "<BR>";
	echo "MIME : " . $_FILES['upfile']['type'] . "<BR>";
	echo "파일 크기 : " . $_FILES['upfile']['size'] . "<BR>";
	echo "임시 파일 : " . $_FILES['upfile']['tmp_name'] . "<BR>";
	echo "에러코드 : " . $_FILES['upfile']['error'] . "<BR>";
?>