<?
//������ ���̽� �����ϱ�
include "db_info.php";

$result=mysql_query("SELECT pass FROM board WHERE id=$id",
$conn);
$row=mysql_fetch_array($result);

if ($pass==$row[pass] )
{
	$query = "DELETE FROM board WHERE id=$id ";
	$result=mysql_query($query, $conn);
}
else
{
	echo ("
	<script>
	alert('��й�ȣ�� Ʋ���ϴ�.');
	history.go(-1);
	</script>
	");
	exit;
}
?>
<center>
<meta http-equiv='Refresh' content='1; URL=list.php'>
<FONT size=2 >�����Ǿ����ϴ�.</font>