<html>
<head>
<title>�� ���� �Խ���</title>
<style>
<!--
td {font-size : 9pt;}
A:link {font : 9pt; color : black; text-decoration : none;
font-family : ����; font-size : 9pt;}
A:visited {text-decoration : none; color : black; font-size : 9pt;}
A:hover {text-decoration : underline; color : black; 
font-size : 9pt;}
-->
</style>
</head>

<body topmargin=0 leftmargin=0 text=#464646>
<center>
<BR>
<?
	//������ ���̽� �����ϱ�
	include "db_info.php";

	// �� ���� ��������
	$result=mysql_query("SELECT * FROM board WHERE id=$id", $conn);
	$row=mysql_fetch_array($result);
?>
<table width=580 border=0 cellpadding=2 cellspacing=1
bgcolor=#777777>
<tr>
	<td height=20 colspan=4 align=center bgcolor=#999999>
		<font color=white><B><?=$row[title]?></B></font>
	</td>
</tr>
<tr>
	<td width=50 height=20 align=center bgcolor=#EEEEEE>�۾���</td>
	<td	width=240 bgcolor=white><?=$row[name]?></td>
	<td width=50 height=20 align=center bgcolor=#EEEEEE>�̸���</td>
	<td	width=240 bgcolor=white><?=$row[email]?></td>
</tr>
<tr>
	<td width=50 height=20 align=center bgcolor=#EEEEEE>
	��&nbsp;&nbsp;&nbsp;¥</td><td width=240
	bgcolor=white><?=$row[wdate]?></td>
	<td width=50 height=20 align=center bgcolor=#EEEEEE>��ȸ��</td>
	<td	width=240 bgcolor=white><?=$row[view]?></td>
</tr>
<tr>
	<td bgcolor=white colspan=4>
	<font color=black>
	<pre><?=$row[content]?></pre>
	</font>
	</td>
</tr>
<!-- ��Ÿ ��ư �� -->
<tr>
	<td colspan=4 bgcolor=#999999>
	<table width=100%>
		<tr>
			<td width=200 align=left height=20>
				<a href=list.php?no=<?=$no?>><font color=white>
				[��Ϻ���]</font></a>
				<a href=write.php><font color=white>
				[�۾���]</font></a>
				<a href=edit.php?id=<?=$id?>><font color=white>
				[����]</font></a>
				<a href=predel.php?id=<?=$id?>>
				<font color=white>[����]</font></a>
			</td>
			<!-- ��Ÿ ��ư �� -->
			<!-- ���� ���� ǥ�� -->
			<td align=right>
<?
	// ���� �ۺ��� id ���� ū �� �� ���� ���� ���� �����´�. 
	// �� �ٷ� ���� ��
	$query=mysql_query("SELECT id FROM board WHERE id > $id LIMIT 1", 
	$conn);
	$prev_id=mysql_fetch_array($query);

	if ($prev_id[id]) // ���� ���� ���� ���
	{
		echo "<a href=read.php?id=$prev_id[id]>
		<font color=white>[����]</font></a>";
	}
	else
	{
		echo "[����]";
	}

	$query=mysql_query("SELECT id FROM board WHERE id < $id 
	ORDER BY id DESC LIMIT 1", $conn);
	$next_id=mysql_fetch_array($query);

	if ($next_id[id])
	{
		echo "<a href=read.php?id=$next_id[id]>
		<font color=white>[����]</font></a>";
	}
	else
	{
		echo "[����]";
	}
?>
			</td>
		</tr>
	</table>
	</b></font>
	</td>
</tr>
</table>
</center>
</body>
</html>
<?
	// ��ȸ�� ������Ʈ
	$result=mysql_query("UPDATE testboard SET see=see+1 WHERE id=$id",
	$conn);

	mysql_close($conn);
?>