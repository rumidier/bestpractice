<?
	// 7 ��; 24 �ð�; 60 ��; 60 ��
	$next_week = time() + (7 * 24 * 60 * 60);

	echo '���� : ' . date('Y-m-d') . "<BR>";
	echo '���� �� : ' . date('Y-m-d', $next_week);
?>