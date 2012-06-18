<?
  include "library.php";

  if (!$_POST[pass]) ErrorMessage('암호를 입력하세요');

  include "db_info.php";

  $query = "SELECT pass FROM comment WHERE id=$_GET[id]";
  $result = mysql_query($query, $conn) or ErrorMessage('덧글을 삭제하는데 실패하였습니다[DB].');
  $row    = mysql_fetch_array($result);

  if ($_POST['pass'] == $row['pass'] ) {
    $conndel = "DELETE FROM comment WHERE id=$_GET[id]";
    $result  = mysql_query($conndel, $conn) or ErrorMessage('덧글을 삭제하는데 실패하였습니다.');
  }
  else {
    ErrorMessage('비밀번호가 틀립니다.');
  }
?>
<meta http-equiv='Refresh' content='0; URL=read.php?id=<?=$_GET[bid]?>'>
