<?
include "db_info.php";
$query = "SELECT * FROM $board WHERE id='$_GET[id]'";
$parent_result = mysql_query($query, $conn);
$parent_row = mysql_fetch_array($parent_result);
$parent_title = "RE:" . $parent_row[title];
$parent_content = "\n>" . str_replace("\n", "\n>", 
$parent_row[content]);
?>
<html>
<head>
<title>������ �Խ���</title>
<style>
<!--
td { font-size : 9pt; }
A:link { font : 9pt; color : black; text-decoration : none; 
font-family: ����; font-size : 9pt; }
A:visited { text-decoration : none; color : black; 
font-size : 9pt; }
A:hover { text-decoration : underline; color : black; 
font-size : 9pt;}
-->
</style>
</head>
<body topmargin=0 leftmargin=0 text=#464646>
<center>
<BR>
<!-- �Էµ� ���� ���� �������� �ѱ�� ���� FORM�� �����. -->
<form action=insert_reply.php method=post>
<input type=hidden name=parent_depth value=<?=$parent_row[depth]?>>
<input type=hidden name=parent_thread value=<?=$parent_row[thread]?>>
<table width=580 border=0 cellpadding=2 cellspacing=1 bgcolor=#777777>
<tr>
	<td height=20 align=center bgcolor=#999999>
		<font color=white><B>�亯 �ޱ�</B></font>
	</td>
</tr>
<!-- �Է� �κ� -->
<tr>
	<td bgcolor=white>&nbsp;
	<table>
	<tr>
		<td width=60 align=left >�̸�</td>
		<td align=left >
			<INPUT type=text name=name size=20 maxlength=10>
		</td>
	</tr>
	<tr>
		<td width=60 align=left >�̸���</td>
		<td align=left >
			<INPUT type=text name=email size=20 maxlength=25>
		</td>
	</tr>
	<tr>
		<td width=60 align=left >��й�ȣ</td>
		<td align=left >
			<INPUT type=password name=pass size=8 maxlength=8> 
			(����,������ �ݵ�� �ʿ�)
		</td>
	</tr>
	<tr>
		<td width=60 align=left >�� ��</td>
		<td align=left >
			<INPUT type=text name=title size=60 maxlength=35 
			value="<?=$parent_title?>">
		</td>
	</tr>
	<tr>
		<td width=60 align=left >����</td>
		<td align=left >
			<TEXTAREA name=content cols=65 rows=15>
			<?=$parent_content?></TEXTAREA>
		</td>
	</tr>
	<tr>
		<td colspan=10 align=center>
			<INPUT type=submit value="�� �����ϱ�">
			&nbsp;&nbsp;
			<INPUT type=reset value="�ٽ� ����">
			&nbsp;&nbsp;
			<INPUT type=button value="�ǵ��ư���" 
			onclick="history.back(-1)">
		</td>
	</tr>
	</TABLE>
	</td>
</tr>
<!-- �Է� �κ� �� -->
</table>
</center>
</body>
</html>