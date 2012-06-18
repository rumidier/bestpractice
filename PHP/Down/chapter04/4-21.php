<?
	$handle = fopen("/home/httpd/file.txt", "r");

	if ($handle) {
		echo "파일을 열었습니다.";
	} else {
		echo "파일을 여는데 실패하였습니다.";
	}

	fclose($handle);
?>