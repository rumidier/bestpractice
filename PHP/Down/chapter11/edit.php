<html>
<head>
<title>�� ���� �Խ���</title>
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
<form action=update.php?id=<?=$id?> method=post>
<table width=580 border=0 cellpadding=2 cellspacing=1 bgcolor=#777777>
	<tr>
		<td height=20 align=center bgcolor=#999999>
			<font color=white><B>�� �� �� �� ��</B></font>
		</td>
	</tr>
<?
	//������ ���̽� �����ϱ�
	include "db_info.php";

	// ���� �� ���� ������ �����´�.
	$result=mysql_query("SELECT * FROM board WHERE id=$id", $conn);
	$row=mysql_fetch_array($result);
?>
<!-- �Է� �κ� -->
	<tr>
		<td bgcolor=white>&nbsp;
		<table>
			<tr>
				<td width=60 align=left >�̸�</td>
				<td align=left >
					<INPUT type=text name=name size=20 
					value=<?=$row[name]?>>
				</td>
			</tr>
			<tr>
				<td width=60 align=left >�̸���</td>
				<td align=left >
					<INPUT type=text name=email size=20 
					value=<?=$row[email]?>>
				</td>
			</tr>
			<tr>
				<td width=60 align=left >��й�ȣ</td>
				<td align=left >
					<INPUT type=password name=pass size=8> 
					(��й�ȣ�� �¾ƾ� ��������)
				</td>
			</tr>
			<tr>
				<td width=60 align=left >�� ��</td>
				<td align=left >
					<INPUT type=text name=title size=60 
					value=<?=$row[title]?>>
				</td>
			</tr>
			<tr>
				<td width=60 align=left >����</td>
				<td align=left >
					<TEXTAREA name=content cols=65 rows=15>
					<?=$row[content]?></TEXTAREA>
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
</form>
</center>
</body>
</html>