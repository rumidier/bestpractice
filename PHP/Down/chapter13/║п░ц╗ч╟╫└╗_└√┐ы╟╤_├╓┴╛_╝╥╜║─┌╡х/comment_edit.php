<style>
<!--
td { font-size : 9pt; }
A:link { font : 9pt; color : black; text-decoration : none; font-family : ����; font-size : 9pt; }
A:visited { text-decoration : none; color : black; font-size : 9pt; }
A:hover { text-decoration : underline; color : black; font-size : 9pt; }

--> 
</style>

<script>
	function CommentFormCheck() {
		if (!comment_update.name.value) {
			alert("�̸��� �Է��ϼ���.");
			comment_update.name.focus();
			return false;
		}
		if (!comment_update.pass.value) {
			alert("��й�ȣ�� �Է��ϼ���.");
			comment_update.pass.focus();
			return false;
		}
		if (!comment_update.comment.value) {
			alert("������ �Է��ϼ���.");
			comment_update.comment.focus();
			return false;
		}
	}
</script>


<table width=600 align=center border=0 cellpadding=5 cellspacing=0>
<form name=comment_update method=post action='comment_update.php' onsubmit="return CommentFormCheck()">
<input type=hidden name=id value='<?=$_GET[id]?>'>
<input type=hidden name=bid value='<?=$_GET[bid]?>'>
	<tr bgcolor=#CCCCCC><td colspan=4></td></tr>
	<tr bgcolor=#F0F0F0>
		<td width=50 align=center>�̸�</td><td width=100><input type=text name=name size=15></td>
		<td width=50 align=center>��й�ȣ</td><td><input type=password name=pass size=15></td>
	</tr>
	<tr>
		<td valign=absmiddle colspan=4><textarea name=comment rows=5 cols=70></textarea>
		<input type=submit value=' �� �� ' style="height:80;width:57">
		</td>
    </tr>
</form>
</table>