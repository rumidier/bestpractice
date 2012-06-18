<?
	if ($mode!="delete")
	{
?>
<HTML>
<FORM METHOD="POST" 
ACTION="<?=$PHP_SELF?>?id=<?=$_GET[id]?>&mode=delete">
<TABLE>
	<TR>
		<TD>비밀번호</TD>
		<TD><INPUT TYPE="PASSWORD" NAME="pass"></TD>
		<TD><INPUT TYPE="SUBMIT" VALUE=" 확 인 "></TD>
	</TR>
</TABLE>
<?
		exit;
	} //end if

	$conn = mysql_connect("localhost", "사용자아이디", "비밀번호");
	@mysql_select_db("데이터베이스이름", $conn);
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
<script> alert("글이 삭제되었습니다."); location.href="list.php"; </script>