<?
function ErrorMessage($message, $type = "on")
{
	echo "<script> alert('$message'); ";
	if ($type == "on") echo " history.back(); ";
	echo "</script>";
	exit;
}

function remove_html($string) 
{
	$string = str_replace("<", "&lt;", $string);
	$string = str_replace(">", "&gt;", $string);
	return $string;
}
?>