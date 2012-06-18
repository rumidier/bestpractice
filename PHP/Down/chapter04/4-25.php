<?
	$filename = "something.txt";

	if (is_dir($filename)) {
		echo "$filename은 디렉토리 입니다.";
	} else {
		echo "$filename은 파일이거나 존재하지 않습니다.";
	}
?>