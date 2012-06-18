<?
	$array = file('somefile.txt');

	foreach ($array as $line_num => $line) {
		echo "#{$line_num} : $line <br>\n";
	}
?>