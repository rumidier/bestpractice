<?
//������ ���̽� �����ϱ�
include "db_info.php";

// ���� �� ���� ������ �����´�.
$id = (int)$_GET[id];

$result=mysql_query("select * from $board where id='$id'", $conn);
$row=mysql_fetch_array($result);
?>
<html>
<head>
<title>������ �Խ���</title>
<style>
<!--
td { font-size : 9pt; }
A:link { font : 9pt; color : black; text-decoration : none; font-family : ����; font-size : 9pt; }
A:visited { text-decoration : none; color : black; font-size : 9pt; }
A:hover { text-decoration : underline; color : black; font-size : 9pt; }

--> 
</style>
<script>

	function FormCheck() {
		if (!fm.name.value)
		{
			alert("�̸��� �Է��ϼ���.");
			fm.name.focus();
			return false;
		}
		if (!fm.pass.value)
		{
			alert("��ȣ�� �Է��ϼ���.");
			fm.pass.focus();
			return false;
		}
		if (!fm.title.value)
		{
			alert("������ �Է��ϼ���.");
			fm.title.focus();
			return false;
		}
		if (!fm.content.value)
		{
			alert("������ �Է��ϼ���.");
			fm.content.focus();
			return false;
		}
	}

</script>
</head>

<body topmargin=0 leftmargin=0 >

<center>
<BR>

<!-- �Էµ� ���� ���� �������� �ѱ�� ���� FORM�� �����. -->
<form action=update.php?id=<?=$id?> method=post name=fm onsubmit="return FormCheck()" enctype="multipart/form-data">

<table width=580 border=0 cellpadding=2 cellspacing=1 bgcolor=#777777>
<tr>
	<td height=20 align=center bgcolor=#999999>
		<font color=white><B>�� �� �� �� ��</B></font>
	</td>
</tr>
<!-- �Է� �κ� -->
<tr>
	<td bgcolor=white>&nbsp;
		<table>
		<tr>
			<td width=60 align=left >�̸�</td>
			<td align=left >
			<INPUT type=text name=name size=20 maxlength=10 value="<?=$row[name]?>">
			</td>
		</tr>
		<tr>
			<td width=60 align=left >�̸���</td>
			<td align=left >
			<INPUT type=text name=email size=20 maxlength=25 value="<?=$row[email]?>">
			</td>
		</tr>
		<tr>
			<td width=60 align=left >��й�ȣ</td>
			<td align=left >
			<INPUT type=password name=pass size=8 maxlength=8 AUTOCOMPLETE="OFF"> (��й�ȣ�� �¾ƾ� ��������)
			</td>
		</tr>
		<tr>
			<td width=60 align=left >�� ��</td>
			<td align=left >
			<INPUT type=text name=title size=60 maxlength=35 value="<?=$row[title]?>">
			</td>
		</tr>
		<tr>
			<td width=60 align=left >����</td>
			<td align=left >
			<TEXTAREA name=content cols=65 rows=15><?=$row[content]?></TEXTAREA>
			</td>
		</tr>
		<tr>
			<td width=60 align=left >����</td>
			<td align=left >
			<INPUT type=file name=upfile size=40>
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