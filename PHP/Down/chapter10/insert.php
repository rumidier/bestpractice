<?
	$conn = mysql_connect("localhost", "����ھ��̵�", "��й�ȣ");
	mysql_select_db("�����ͺ��̽��̸�", $conn);
	mysql_query("set names euckr");

	$query = "INSERT INTO guestbook (name, pass, content) ";
	$query .= " VALUES ('$_POST[name]', '$_POST[pass]', '$_POST[content]')";
	$result = mysql_query($query, $conn);
?>

<script>
alert("���� ��ϵǾ����ϴ�.");
location.href="list.php";
</script>