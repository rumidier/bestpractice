<?
	$filename = 'somefile.txt';

	if (file_exists($filename)) {
		echo "$filename 파일이 존재합니다.";
	} else {
		echo "$filename 파일이 존재하지 않습니다.";
	}
?>