<?
  include "library.php";

  $add_query="";
  if (!empty($_FILES['upfile']['name'])) {
    if(move_uploaded_file($_FILES['upfile']['tmp_name'],'/home/meadow/workspace/github/PHP/Le-12/uploads_dir/'.$_FILES['upfile']['name'])) 
    {
      $filename = $_FILES['upfile']['name'];
      $add_query = ", filename = '$filename' ";
    }
    else {
      ErrorMessage('업로드에 실패하였습니다.');
    }
  }

  $query = "update $board set name='$_POST[name]', title='$_POST[title]' ";
  $query .= $add_query;
  $query .= "where id='$_GET[id]' ";
  $result = mysql_query($query, $conn);

  $_POST[name] = trim(strip_tags($_POST[name]));
  $_POST[email] = trim(strip_tags($_POST[email]));
  if (!$_GET[id])      ErrorMessage('ID가 옳바르지 않습니다.');
  if  (!$_POST[name])    ErrorMessage('이름을 입력하세요.');
  if  (!$_POST[email])    ErrorMessage('이메일을 입력하세요.');
  if  (!$_POST[pass])    ErrorMessage('비밀번호를 입력하세요.');
  if  (!$_POST[title])   ErrorMessage('제목을 입력하세요.');
  if  (!$_POST[content]) ErrorMessage('내용을 입력하세요.');

  include "db_info.php";


  $query  = "SELECT pass FROM board WHERE id=$_GET[id]";
  $result = mysql_query($query, $conn);
  $row    = mysql_fetch_array($result);

  if ($pass == $row['pass']) {
    $query = "UPDATE threadboard SET name='$_POST[name]', email='$_POST[email]', title='$_POST[title]', content='$_POST[content]' WHERE id='$_GET[id]'";
    $result = mysql_query($query, $conn) or ErrorMessage('글을 수정하는데 실패하였습니다.');
  }
  else {
    ErrorMessage('비밀번호가 틀립니다.');
  }
  mysql_close($conn);

  echo ("<meta http-equiv='Refresh' content='1; URL=read.php?id=$_GET[id]'>");
?>
<center>
  <font size=2>정상적으로 수정되었습니다.</font>
</center>
