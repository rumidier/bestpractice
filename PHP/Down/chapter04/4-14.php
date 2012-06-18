<?
	$fd = fopen ("somefile.txt", "r");

	while (!feof($fd)) {
		$buffer = fgetc($fd);
		echo $buffer;
	}

	fclose ($fd);
?>