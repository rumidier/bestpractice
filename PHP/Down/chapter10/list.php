<?
	$conn = mysql_connect("localhost", "root", "rumidier");
	mysql_select_db("brain", $conn);
	mysql_query("set names utf8");

	$query = "SELECT * FROM guestbook ORDER BY id DESC";
	$result = mysql_query($query, $conn);
	$total = mysql_affected_rows();

	$pagesize=5;
?>

<FORM ACTION="insert.php" METHOD="POST">
<TABLE BORDER=1 WIDTH=500>
	<TR>
		<TD>�̸�</TD><TD><INPUT TYPE="TEXT" NAME="name"></TD>
		<TD>��й�ȣ</TD><TD><INPUT TYPE="PASSWORD" NAME="pass"></TD>
	</TR>
	<TR>
		<TD COLSPAN=4><TEXTAREA NAME="content" COLS=65 ROWS=5></TEXTAREA></TD>
	</TR>
	<TR>
		<TD COLSPAN=4 align=right><INPUT TYPE="SUBMIT" VALUE=" Ȯ�� "></TD>
	</TR>
</TABLE>
</FORM>
<BR>
<?
	for($i=$_GET[no] ; $i < $_GET[no]+$pagesize ; $i++) {

		if ($i < $total)
		{
			mysql_data_seek($result,$i);
			$row = mysql_fetch_array($result);
?>
<TABLE WIDTH=500 BORDER=1>
	<TR>
		<TD>No. <?=$row[id]?></TD>
		<TD><?=$row[name]?></TD>
		<TD>(<?=$row[wdate]?>)</TD>
		<TD><a href="delete.php?id=<?=$row[id]?>">del</a></TD>
	</TR>
	<TR>
		<TD COLSPAN=4><?=$row[content]?></TD>
	</TR>
</TABLE>
<?
		} //end if
	} //end for

	$prev = $no - $pagesize ; // ���� �������� ���� �ۿ��� $scale�� �� ������
	$next = $no + $pagesize ; // ���� �������� ���� �ۿ��� $scale�� ���� ������

	if ($prev >= 0) {
		echo("<a href='$PHP_SELF?no=$prev'>����</a> ");
	}
	if ($next < $total) {
		echo("<a href='$PHP_SELF?no=$next'>����</a></center>");
	}
?>
