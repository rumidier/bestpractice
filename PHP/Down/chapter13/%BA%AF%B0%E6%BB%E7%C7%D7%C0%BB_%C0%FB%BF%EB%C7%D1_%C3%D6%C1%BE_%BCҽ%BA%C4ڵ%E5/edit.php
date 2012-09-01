<?
//데이터 베이스 연결하기
include "db_info.php";

// 먼저 쓴 글의 정보를 가져온다.
$id = (int)$_GET[id];

$result=mysql_query("select * from $board where id='$id'", $conn);
$row=mysql_fetch_array($result);
?>
<html>
<head>
<title>계층형 게시판</title>
<style>
<!--
td { font-size : 9pt; }
A:link { font : 9pt; color : black; text-decoration : none; font-family : 굴림; font-size : 9pt; }
A:visited { text-decoration : none; color : black; font-size : 9pt; }
A:hover { text-decoration : underline; color : black; font-size : 9pt; }

--> 
</style>
<script>

	function FormCheck() {
		if (!fm.name.value)
		{
			alert("이름을 입력하세요.");
			fm.name.focus();
			return false;
		}
		if (!fm.pass.value)
		{
			alert("암호를 입력하세요.");
			fm.pass.focus();
			return false;
		}
		if (!fm.title.value)
		{
			alert("제목을 입력하세요.");
			fm.title.focus();
			return false;
		}
		if (!fm.content.value)
		{
			alert("내용을 입력하세요.");
			fm.content.focus();
			return false;
		}
	}

</script>
</head>

<body topmargin=0 leftmargin=0 >

<center>
<BR>

<!-- 입력된 값을 다음 페이지로 넘기기 위해 FORM을 만든다. -->
<form action=update.php?id=<?=$id?> method=post name=fm onsubmit="return FormCheck()" enctype="multipart/form-data">

<table width=580 border=0 cellpadding=2 cellspacing=1 bgcolor=#777777>
<tr>
	<td height=20 align=center bgcolor=#999999>
		<font color=white><B>글 수 정 하 기</B></font>
	</td>
</tr>
<!-- 입력 부분 -->
<tr>
	<td bgcolor=white>&nbsp;
		<table>
		<tr>
			<td width=60 align=left >이름</td>
			<td align=left >
			<INPUT type=text name=name size=20 maxlength=10 value="<?=$row[name]?>">
			</td>
		</tr>
		<tr>
			<td width=60 align=left >이메일</td>
			<td align=left >
			<INPUT type=text name=email size=20 maxlength=25 value="<?=$row[email]?>">
			</td>
		</tr>
		<tr>
			<td width=60 align=left >비밀번호</td>
			<td align=left >
			<INPUT type=password name=pass size=8 maxlength=8 AUTOCOMPLETE="OFF"> (비밀번호가 맞아야 수정가능)
			</td>
		</tr>
		<tr>
			<td width=60 align=left >제 목</td>
			<td align=left >
			<INPUT type=text name=title size=60 maxlength=35 value="<?=$row[title]?>">
			</td>
		</tr>
		<tr>
			<td width=60 align=left >내용</td>
			<td align=left >
			<TEXTAREA name=content cols=65 rows=15><?=$row[content]?></TEXTAREA>
			</td>
		</tr>
		<tr>
			<td width=60 align=left >파일</td>
			<td align=left >
			<INPUT type=file name=upfile size=40>
			</td>
		</tr>
		<tr>
		<td colspan=10 align=center>
		<INPUT type=submit value="글 저장하기">
		&nbsp;&nbsp;
		<INPUT type=reset value="다시 쓰기">
		&nbsp;&nbsp;
		<INPUT type=button value="되돌아가기" onclick="history.back(-1)">
		</td>
		</tr>
		</TABLE>
	</td> 
</tr>
<!-- 입력 부분 끝 -->
</table>
</form>
</center>
</body>
</html> 