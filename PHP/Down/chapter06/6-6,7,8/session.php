<?
	session_start();
	echo SID . '<P>';
?>
<a href="nexpage.php?<?=strip_tags(SID)?>">다음 페이지</a>