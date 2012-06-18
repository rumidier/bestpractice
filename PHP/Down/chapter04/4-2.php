<?
	//날짜를 지정하지 않는 경우
	echo date("오늘은 Y년 m월 d일 입니다.") . "<BR>";
	echo date("지금 시각은 H시 i분 s초 입니다.") . "<BR>";
	echo date("오늘은 올해의 z번째 날입니다.") . "<BR>";
	echo date("오늘은 올해의 W번째 주입니다.") . "<BR>";
	echo date("이번 달의 마지막 날은 t일 입니다.") . "<BR>";

	/*
	날짜를 지정하는 경우
	mktime() 함수를 이용하여 timestamp를 만들 수 있습니다.
	아래는 2009년 6월 8일 6시 28분 31초 입니다.
	*/
	$date = mktime(6, 28, 31, 6, 8, 2009);
	echo date("주어진 날짜는 Y년 m월 d일 입니다.", $date) . "<BR>";
	echo date("주어진 시간은 H시 i분 s초 입니다.", $date) . "<BR>";
?>