<?
	if ($mode!="delete")
	{
?>
<HTML>
<FORM METHOD="POST" 
ACTION="<?=$PHP_SELF?>?id=<?=$_GET[id]?>&mode=delete">
<TABLE>
	<TR>
		<TD>��й�ȣ</TD>
		<TD><INPUT TYPE="PASSWORD" NAME="pass"></TD>
		<TD><INPUT TYPE="SUBMIT" VALUE=" Ȯ �� "></TD>
	</TR>
</TABLE>
<?
		exit;
	} //end if

	$conn = mysql_connect("localhost", "����ھ��̵�", "��й�ȣ");
	@mysql_select_db("�����ͺ��̽��̸�", $conn);
	@mysql_query("set names euckr");

	$query = "SELECT pass FROM guestbook WHERE id='$_GET[id]'";
	$result = mysql_query($query, $conn);
	$row = mysql_fetch_array($result);
	
	if ($row[pass] == $_POST[pass])
	{
		$query = "DELETE FROM guestbook WHERE id='$id'";
		$result = mysql_query($query, $conn);
	}
?>
<script> alert("���� �����Ǿ����ϴ�."); location.href="list.php"; </script>