<?
	$filename = "/var/www/temp/readfile.txt";

	//헤더 정보를 변경한다.
	header("Pragma: public");
	header("Expires: 0");
	header("Cache-Control: must-revalidate, post-check=0, pre-check=0");
	header('Content-Description: File Transfer');

	//파일의 형식을 변경
	header('Content-Type: application/octet-stream');

	//파일의 크기
	header('Content-Length: ' . filesize($filename));

	//파일 이름
	header('Content-Disposition: attachment; filename=' 
	. basename($filename));
	//파일을 출력
	@readfile($filename);
?>