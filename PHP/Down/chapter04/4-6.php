<?
	$start_time = microtime(TRUE);
	$sum = 0;
	
	for ($i=1; $i <= 1000; $i++) {
		$sum += $i;
	}

	$end_time = microtime(TRUE);

	echo "�� : $sum <BR>";
	echo "�� �ҿ�ð� : " . ($end_time - $start_time);
?>