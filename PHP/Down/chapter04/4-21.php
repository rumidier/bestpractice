<?
	$handle = fopen("/home/httpd/file.txt", "r");

	if ($handle) {
		echo "������ �������ϴ�.";
	} else {
		echo "������ ���µ� �����Ͽ����ϴ�.";
	}

	fclose($handle);
?>