<? require_once("http_auth.php"); ?>
<HTML>
<BODY>
<font size=2>
	당신은 지금 <?=$_SERVER['PHP_AUTH_USER']?>(으)로 로그인 하였습니다.<P>
	이전 페이지에 이어 지속적으로 인증상태가 유지되고 있습니다.<P>
	로그아웃을 원하면 <a href="http7.php?logout=1">로그아웃</a>을 클릭하십시오.
</font>
</BODY>
</HTML>