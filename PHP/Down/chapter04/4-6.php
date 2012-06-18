<?
	$start_time = microtime(TRUE);
	$sum = 0;
	
	for ($i=1; $i <= 1000; $i++) {
		$sum += $i;
	}

	$end_time = microtime(TRUE);

	echo "합 : $sum <BR>";
	echo "총 소요시간 : " . ($end_time - $start_time);
?>