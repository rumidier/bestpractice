<?
include_once "db_info.php";
include_once "library.php";

$id = $_GET[id];
$sql_cmt = "SELECT * FROM comment WHERE bid = '$id' ORDER BY id";
$result_cmt = mysql_query($sql_cmt, $conn);

while($row_cmt=mysql_fetch_array($result_cmt)) {
	$comment = nl2br(str_replace(" ","&nbsp;" , remove_html($row_cmt[comment])));
?>

<table width=98% border=0 align=center cellpadding=5 cellspacing=0>
<tr bgcolor=#CCCCCC><td colspan=2></td></tr>
<tr bgcolor=#F0F0F0>
	<td width=50% id="name_<?=$row_cmt[id]?>"><?=$row_cmt[name]?></td>
	<td align=right style="font-size:8pt">
		<a href="javascript:change_form(<?=$row_cmt[id]?>);" style="font-size:8pt;color:#999999">[����]</a>
		<a href="comment_predel.php?id=<?=$row_cmt[id]?>&bid=<?=$id?>" style="font-size:8pt;color:#999999">[����]</a>
		<?=$row_cmt[wdate]?>
	</td>
</tr>
<tr>
<td valign=top colspan=2 id="comment_<?=$row_cmt[id]?>"> <?=$comment?><BR><BR></td>
</tr>
</table>
<? } ?>

<script>
function change_form(id) {
	name = eval("name_" + id).innerText;
	comment = eval("comment_" + id).innerText;

	comment_insert.name.value = name;
	comment_insert.comment.value = comment;
	comment_insert.id.value = id;
	comment_insert.action = "comment_update.php";
	comment_insert.comment.cols=61;
	comment_insert.register.value="�� ��";

	str = "<input type=button value=' �� �� '";
	str += "style='height:80;width:57' onclick='restore_form()'>";

	cancel.innerHTML = str;
	comment_insert.comment.focus();
}
function restore_form() {
	cancel.innerHTML = "";
	comment_insert.action = "comment_insert.php";
	comment_insert.id.value = "";
	comment_insert.reset();
	comment_insert.register.value="�� ��";
	comment_insert.comment.cols=70;
}
function CommentFormCheck() {
	if (!comment_insert.name.value) {
		alert("�̸��� �Է��ϼ���.");
		comment_insert.name.focus();
		return false;
	}
	if (!comment_insert.pass.value) {
		alert("��й�ȣ�� �Է��ϼ���.");
		comment_insert.pass.focus();
		return false;
	}
	if (!comment_insert.comment.value) {
		alert("������ �Է��ϼ���.");
		comment_insert.comment.focus();
		return false;
	}
}
</script>
<table width=98% align=center border=0 cellpadding=5 cellspacing=0>
<form name=comment_insert method=post action='comment_insert.php'
onsubmit="return CommentFormCheck()">
<input type=hidden name=id value=''>
<input type=hidden name=bid value='<?=$id?>'>
<tr bgcolor=#CCCCCC><td colspan=4></td></tr>
<tr bgcolor=#F0F0F0>
	<td width=50 align=center>�̸�</td><td width=100>
	<input type=text name=name size=15></td>
	<td width=50 align=center>��й�ȣ</td>
	<td><input type=password name=pass size=15></td>
</tr>
<tr>
	<td valign=absmiddle colspan=4><textarea name=comment rows=5
	cols=70></textarea>
	<input name=register type=submit value=' �� �� ' 
	style="height:80;width:57">
	<span id=cancel></span>
	</td>
</tr>
</form>
</table>
