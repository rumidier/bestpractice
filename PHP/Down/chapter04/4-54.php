<?
	echo substr ("abcdef", 1); // bcdef
	echo substr ("abcdef", 1, 3); // bcd

	echo substr ("abcdef", -1); // f
	echo substr ("abcdef", -2); // ef
	echo substr ("abcdef", -3, 1); // d

	echo substr("abcdef", 1, -1); // bcde
?>