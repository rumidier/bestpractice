<?
  include "db_info.php";

  $query = "INSERT INTO board (id, name, email, pass, title, content, wdate, ip, view)
	VALUES ('', '$_POST[name]', '$_POST[email]', '$_POST[pass]', '$_POST[title]', '$_POST[content]', now(), '$_SERVER[REMOTE_ADDR]', 0)";
  $result = mysql_query($query, $conn);

  // 데이터베이스와의 연결 종료
  mysql_close($conn);

  // 새 글 쓰기인 경우 리스트로..
  echo ("<meta http-equiv='Refresh' content='1; URL=list.php'>");
?>
<center>
<font size=2>정상적으로 저장되었씁니다.</font>
</center>
