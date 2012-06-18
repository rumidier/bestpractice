<?
	$file = "test.php";

	if (copy($file, $file.'.bak')) {
		echo "$file을 복사하였습니다...<br>\n";
	} else {
		echo "$file을 복사하는데 실패했습니다...<br>\n";
	}
?>