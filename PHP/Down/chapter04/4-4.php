<?
	$today = getdate();
	
	foreach ($today as $key => $value) {
		echo $key . " : " . $value . "<BR>";
	}

	echo "오늘은 " . $today[year] . "년 " . $today[mon] . "월 "
	. $today[mday] . "일 입니다.";
?>