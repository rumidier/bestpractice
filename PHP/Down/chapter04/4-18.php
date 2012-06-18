<?
	$array = file('http://www.naver.com/');

	foreach ($array as $line_num => $line) {
		echo htmlspecialchars($line) . " <br>\n";
	}
?>