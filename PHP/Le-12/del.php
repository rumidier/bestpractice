<?
  include "db_info.php";
  include "library.php";

  if (!$_GET['id']) ErrorMessage('ID가 올바르지 않습니다.');

  $query  = "SELECT pass FROM board WHERE id=$_GET['id']";
  $result = mysql_query($query, $conn);
  $row    = mysql_fetch_array($result);

  if ($pass == $row['pass']) {
    $query = "DELETD FROM board WHERE id=$_GET[id]";
    $result = mysql_query($query, $conn) or ErrorMessage('글을 삭제하는데 실패하였습니다');
  }
  else {
    ErrorMessage('비밀번호가 틀립니다.');
  }
  mysql_close($conn);
  echo ("<meta http-equiv='Refresh' content='1; URL=list.php'>");
?>
<center>
  <font size=2>정상적으로 수정되었습니다.</font>
</center>

