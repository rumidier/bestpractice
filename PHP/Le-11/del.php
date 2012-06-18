<?
  include "db_info.php";

  $query  = "SELECT pass FROM board WHERE id=$_GET['id']";
  $result = mysql_query($query, $conn);
  $row    = mysql_fetch_array($result);

  if ($pass == $row['pass']) {
    $query = "DELETD FROM board WHERE id=$_GET[id]";
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

?>
<center>
  <meta http-equiv='Refresh' content='1; URL=list.php'>
  <font size=2>정상적으로 수정되었습니다.</font>
</center>

