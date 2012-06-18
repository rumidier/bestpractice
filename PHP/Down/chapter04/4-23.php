<?
	$handle = fopen("/home/httpd/file.txt", "w");

	$string = "뇌를 자극하는 PHP 프로그래밍";
	fwrite($handle, $string);

	fclose($handle);
?>