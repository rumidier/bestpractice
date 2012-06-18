<?
	$filename = "somefile.txt";

	if (is_file($filename)) {
		echo "$filename 은 파일 입니다.";
	} else {
		echo "$filename 은 파일이 아니거나 존재하지 않습니다.";
	}
?>