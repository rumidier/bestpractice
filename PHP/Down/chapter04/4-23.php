<?
	$handle = fopen("/home/httpd/file.txt", "w");

	$string = "���� �ڱ��ϴ� PHP ���α׷���";
	fwrite($handle, $string);

	fclose($handle);
?>