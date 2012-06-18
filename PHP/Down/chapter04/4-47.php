<?
	$christmas = "2007-12-25";

	$date = sscanf($christmas, "%d-%d-%d", &$year, &$month, &$day);
	echo "{$year}년 {$month}월 {$day}일은 크리스마스입니다.";
?>