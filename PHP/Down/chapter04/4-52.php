<?
	$haystack = "abcdef";
	$needle = "abc";

	$pos = strpos($haystack, $needle);

	if ($pos === false)
	{
		echo "���ڿ��� ã�� ���߽��ϴ�.";
	}
	else
	{
		echo "{$pos} ��ġ���� ���ڿ��� ã�ҽ��ϴ�.";
	}
?>