<?
include_once "db_info.php";
include_once "library.php";

$id = $_GET[id];
$sql_cmt = "SELECT * FROM comment WHERE bid = '$id' ORDER BY id";
$result_cmt = mysql_query($sql_cmt, $conn);

while($row_cmt=mysql_fetch_array($result_cmt)) {
	$comment = nl2br(str_replace(" ","&nbsp;" , 
	remove_html($row_cmt[comment])));
?>
<table width=98% border=0 align=center cellpadding=5 cellspacing=0>
<tr bgcolor=#CCCCCC><td colspan=2></td></tr>
<tr bgcolor=#F0F0F0>
	<td width=50%><?=$row_cmt[name]?></td>
	<td align=right style="font-size:8pt">
	<a href="comment_edit.php?id=<?=$row_cmt[id]?>&bid=<?=$id?>"
	style="font-size:8pt;color:#999999">[수정]</a>
	<a href="comment_predel.php?id=<?=$row_cmt[id]?>&bid=<?=$id?>"
	style="font-size:8pt;color:#999999">[삭제]</a>
	<?=$row_cmt[wdate]?>
	</td>
</tr>
<tr>
	<td valign=top colspan=2><?=$comment?><BR><BR></td>
</tr>
</table>
<? } ?>
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
<input type=hidden name=bid value='<?=$id?>'>
<tr bgcolor=#CCCCCC><td colspan=4></td></tr>
<tr bgcolor=#F0F0F0>
	<td width=50 align=center>이름</td><td width=100>
	<input type=text name=name size=15></td>
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