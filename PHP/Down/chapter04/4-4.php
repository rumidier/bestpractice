<?
	$today = getdate();
	
	foreach ($today as $key => $value) {
		echo $key . " : " . $value . "<BR>";
	}

	echo "������ " . $today[year] . "�� " . $today[mon] . "�� "
	. $today[mday] . "�� �Դϴ�.";
?>