<?
	$file = "test.php";

	if (copy($file, $file.'.bak')) {
		echo "$file�� �����Ͽ����ϴ�...<br>\n";
	} else {
		echo "$file�� �����ϴµ� �����߽��ϴ�...<br>\n";
	}
?>