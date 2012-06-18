<?
	function swap($a, $b)
	{
		$c = $a;
		$a = $b;
		$b = $c;
	}

	$num1 = 5;
	$num2 = 6;

	swap($num1, $num2);
	echo "$num1, $num2";
?>