<html>
<head>
<title>초 허접 게시판</title>
<style>
<!--
td {font-size : 9pt;}
A:link {font : 9pt;color : black;text-decoration : none;
font-family: 굴림;font-size : 9pt;}
A:visited {text-decoration : none; color : black; font-size : 9pt;}
A:hover {text-decoration : underline; color : black; 
font-size : 9pt;}
-->
</style>
</head>
<body topmargin=0 leftmargin=0 text=#464646>
<center>
<BR>
<!-- 입력된 값을 다음 페이지로 넘기기 위해 FORM을 만든다. -->
<form action=del.php?id=<?=$id?> method=post>
<table width=300 border=0 cellpadding=2 cellspacing=1
bgcolor=#777777>
<tr>
	<td height=20 align=center bgcolor=#999999>
		<font color=white><B>비 밀 번 호 확 인</B></font>
	</td>
</tr>
<tr>
	<td align=center >
		<font color=white><B>비밀번호 : </b>
		<INPUT type=password name=pass size=8>
		<INPUT type=submit value="확 인">
		<INPUT type=button value="취 소" onclick="history.back(-1)">
	</td>
</tr>
</table>