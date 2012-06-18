<?
	// 7 일; 24 시간; 60 분; 60 초
	$next_week = time() + (7 * 24 * 60 * 60);

	echo '오늘 : ' . date('Y-m-d') . "<BR>";
	echo '다음 주 : ' . date('Y-m-d', $next_week);
?>