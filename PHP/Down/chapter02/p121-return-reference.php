<?
	function &func()
	{
		static $static = 0;
		$static++;
		return $static;
	}

	$var =& func();
	echo $var;
	func();
	func();
	echo $var;
	$var = 0;
	func();
	echo $var;
?>