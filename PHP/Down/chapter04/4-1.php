<?
	$result = checkdate(2, 29, 2006);
	if ($result) {
		echo "2006년 2월 29일은 유효한 날짜입니다.";
	} else {
		echo "2006년 2월 29일은 유효하지 않은 날짜입니다.";
	}
?>