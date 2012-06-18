<?
	$conn = mysql_connect("localhost", "사용자아이디", "비밀번호");
	mysql_select_db("데이터베이스이름", $conn);
	mysql_query("set names euckr");

	$query = "INSERT INTO guestbook (name, pass, content) ";
	$query .= " VALUES ('$_POST[name]', '$_POST[pass]', '$_POST[content]')";
	$result = mysql_query($query, $conn);
?>

<script>
alert("글이 등록되었습니다.");
location.href="list.php";
</script>