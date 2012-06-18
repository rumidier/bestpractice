<?
  include "library.php";
  $_POST[name]  = trim(strip_tags($_POST[name]));
  if  (!$_POST[name])    ErrorMessage('이름을 입력하세요.');
  $_POST[email] = trim(strip_tags($_POST[email]));
  if  (!$_POST[email])   ErrorMessage('이메일을 입력하세요.');
  if  (!$_POST[pass])    ErrorMessage('비밀번호를 입력하세요.');
  if  (!$_POST[title])   ErrorMessage('제목을 입력하세요.');
  if  (!$_POST[content]) ErrorMessage('내용을 입력하세요.');

  include "db_info.php";

  $prev_parent_thread = floor($_POST[parent_thread]/1000) * 1000 + 1000;

  $query = "UPDATE $board SET thread = thread + 1 WHERE
  thread < $prev_parent_thread and thread > $_POST[parent_thread] ORDER BY thread DESC";
  $update_thread = mysql_query($query, $conn);
	
  $name         = trim(strip_tags($_POST['name']));
  $parent_depth = $_POST['parent_depth'];
  $pass         = $_POST['pass'];
  $mail         = trim(strip_tags($_POST['email']));
  $title        = $_POST['title'];
  $REMOTE_ADDR  = $_SERVER['REMOTE_ADDR'];
  $content      = $_POST['content'];

  $query  = "INSERT into $board (thread, depth, name, pass, email, title, view, wdate, ip, content)";
  $query .= "VALUES (($_POST[parent_thread] + 1),
  ($parent_depth + 1),
  '$name',
  '$pass',
  '$email',
  '$title',
  0,
  UNIX_TIMESTAMP(),
  '$REMOTE_ADDR',
  '$content')";
  $result = mysql_query($query, $conn) or ErrorMessage('답변 글을 저장하는 데 실패하엿습니다.');

  mysql_close($conn);

  echo ("<meta http-equiv='Refresh' content='1; URL=list.php'>");
?>
<center>
<font size=2>정상적으로 저장되었습니다.</font>
