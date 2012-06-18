<?
	$haystack = "abcdef";
	$needle = "abc";

	$pos = strpos($haystack, $needle);

	if ($pos === false)
	{
		echo "문자열을 찾지 못했습니다.";
	}
	else
	{
		echo "{$pos} 위치에서 문자열을 찾았습니다.";
	}
?>