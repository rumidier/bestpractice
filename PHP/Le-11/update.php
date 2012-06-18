<?
  include "db_info.php";

  $query  = "SELECT pass FROM board WHERE id=$_GET['id']";
  $result = mysql_query($query, $conn);
  $row    = mysql_fetch_array($result);

  if ($pass == $row['pass']) {
    $query = "UPDATE board SET name='$_POST[name]', email='$_POST[email]', title='$_POST[title]', content='$_POST[content]'
      WHERE id='$_GET[id]'";
    $result = mysql_query($query, $conn);
  }
  else {
    echo ("
	    <script>
	      alert('비밀번호가 틀립니다.');
	      history.go(-1);
	    </script>
	");
    exit;
  }
  mysql_close($conn);

  echo ("<meta http-equiv='Refresh' content='1; URL=read.php?id=$_GET[id]'>");
?>
<center>
  <font size=2>정상적으로 수정되었습니다.</font>
</center>
