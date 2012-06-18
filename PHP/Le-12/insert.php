<?
  $filename = "";
  if (!empty($_FILES['upfile']['name'])) {
    if(move_uploaded_file($_FILES['upfile']['tmp_name'], './uploads_dir/'.$_FILES['upfile']['name'])) {
      $filename = $_FILES['upfile']['name'];
    }
    else {
      ErrorMessage('업로드에 실패하였습니다.');
    }
  }
?>
<?
  include "library.php";
  if  (!$_POST[name])    ErrorMessage('이름을 입력하세요.');
  if  (!$_POST[pass])    ErrorMessage('비밀번호를 입력하세요.');
  if  (!$_POST[title])   ErrorMessage('제목을 입력하세요.');
  if  (!$_POST[content]) ErrorMessage('내용을 입력하세요.');

  include "db_info.php";

  $_POST[name] = trim(strip_tags($_POST[name]));
  $_POST[email] = trim(strip_tags($_POST[email]));

  $query             = "SELECT min(thread) FROM $board";
  $max_thread_result = mysql_query($query, $conn);
  $max_thread_fetch  = mysql_fetch_row($max_thread_result);

  $max_thread = floor($max_thread_fetch[0] / 1000) * 1000 - 1000;
  $query = "INSERT INTO $board (thread, depth, name, pass, email,
  title, view, wdate, ip, content, filename) 
  VALUES ($max_thread, 0, '$_POST[name]', '$_POST[pass]', 
	 '$_POST[email]', '$_POST[title]', 0,
	  UNIX_TIMESTAMP(), '$REMOTE_ADDR', '$_POST[content]', '$filename')";

  $result = mysql_query($query, $conn) or ErrorMessage('글을 저장하는데 실패하였습니다.');

  mysql_close($conn);
echo ("<meta http-equiv='Refresh' content='1; URL=list.php'>");
?>
<center>
<font size=2>정상적으로 저장되었습니다.</font>
