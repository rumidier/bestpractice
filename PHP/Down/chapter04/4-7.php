<?
	// microtime(TRUE)�� ������ �ϴ� �Լ�
	function microtime_float()
	{
		list($usec, $sec) = explode(" ", microtime());
		return ((float)$usec + (float)$sec);
	}

	$start_time = microtime_float();

	$sum = 0;
	for ($i=1; $i <= 1000; $i++) {
		$sum += $i;
	}

	$end_time = microtime_float();

	echo "�� : $sum <BR>";
	echo "�� �ҿ�ð� : " . ($end_time - $start_time);
?>