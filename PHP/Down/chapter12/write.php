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
<form action=insert.php method=post>
<table width=580 border=0 cellpadding=2 cellspacing=1 bgcolor=#777777>
<tr>
	<td height=20 align=center bgcolor=#999999>
		<font color=white><B>�� �� ��</B></font>
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
		<INPUT type=text name=title size=60 maxlength=35>
	</td>
</tr>
<tr>
	<td width=60 align=left >����</td>
	<td align=left >
		<TEXTAREA name=comment cols=65 rows=15></TEXTAREA>
	</td>
</tr>
<tr>
	<td colspan=10 align=center>
		<INPUT type=submit value="�� �����ϱ�">
		&nbsp;&nbsp;
		<INPUT type=reset value="�ٽ� ����">
		&nbsp;&nbsp;
		<INPUT type=button value="�ǵ��ư���" onclick="history.back(-1)">
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