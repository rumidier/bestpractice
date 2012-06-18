<script>
	function CommentFormCheck() {
		if (!comment_insert.name.value) {
			alert("이름을 입력하세요.");
			comment_insert.name.focus();
			return false;
		}
		if (!comment_insert.pass.value) {
			alert("비밀번호를 입력하세요.");
			comment_insert.pass.focus();
			return false;
		}
		if (!comment_insert.comment.value) {
			alert("내용을 입력하세요.");
			comment_insert.comment.focus();
			return false;
		}
	}
</script>

<table width=98% align=center border=0 cellpadding=5 cellspacing=0>
<form name=comment_insert method=post action='comment_insert.php'
onsubmit="return CommentFormCheck()">
<input type=hidden name=bid value='<?=$_GET[id]?>'>
<tr bgcolor=#CCCCCC><td colspan=4></td></tr>
<tr bgcolor=#F0F0F0>
	<td width=50 align=center>이름</td>
	<td width=100><input type=text name=name size=15></td>
	<td width=50 align=center>비밀번호</td>
	<td><input type=password name=pass size=15></td>
</tr>
<tr>
	<td valign=absmiddle colspan=4><textarea name=comment rows=5
	cols=70></textarea>
	<input type=submit value=' 등 록 ' style="height:80;width:57">
	</td>
</tr>
</form>
</table>