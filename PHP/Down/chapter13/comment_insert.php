<?
	include_once "library.php";

	$_POST[name] = trim(strip_tags($_POST[name]));
	//입력값 검증

	if (!$_POST[name]) ErrorMessage('이름을 입력하세요.');
	if (!$_POST[pass]) ErrorMessage('비밀번호를 입력하세요.');
	if (!$_POST[comment]) ErrorMessage('내용을 입력하세요.');

	include_once "db_info.php";

	$query = " INSERT INTO comment (bid, name, pass, comment, ip) ";
	$query .= " VALUES ('{$_POST[bid]}','{$_POST[name]}',
	'{$_POST[pass]}','{$_POST[comment]}','$REMOTE_ADDR')";
	$result = mysql_query($query, $conn) 
	or ErrorMessage('덧글을 저장하는데 실패하였습니다.');
?>
<meta http-equiv='Refresh' content='1; URL=read.php?id=<?=$_GET[id]?>'>
<center>덧글이 등록되었습니다.</center>
