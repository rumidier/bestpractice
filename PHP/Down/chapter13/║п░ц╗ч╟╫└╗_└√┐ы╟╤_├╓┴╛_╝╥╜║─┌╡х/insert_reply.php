<?

include_once "library.php";

$_POST[name] = trim(strip_tags($_POST[name]));
$_POST[email] = trim(strip_tags($_POST[email]));
$_POST[parent_thread]=(int)$_POST[parent_thread];

//입력값 검증
if (!$_POST[name]) ErrorMessage('이름을 입력하세요.');
if (!$_POST[pass]) ErrorMessage('암호를 입력하세요.');
if (!$_POST[title]) ErrorMessage('제목을 입력하세요.');
if (!$_POST[content]) ErrorMessage('내용을 입력하세요.');

$filename="";
if (!empty($_FILES['upfile']['name']))
{
	//금지할 확장자
	$ban_ext = array('php','php3','html','htm','cgi','pl');
	
	//확장자를 이용하여 업로드 가능한 파일인지 체크한다.
	$fname = explode(".", $_FILES['upfile']['name']);
	//배열의 마지막 원소, 즉 확장자를 소문자로 가져온다.
	$ext = strtolower($fname[sizeof($fname)-1]);
	if (in_array($ext, $ban_ext)) {
		ErrorMessage("업로드가 불가능한 확장자입니다.");
	}

	if (move_uploaded_file($_FILES['upfile']['tmp_name'], './uploads_dir/' . $_FILES['upfile']['name']))
	{
		$filename = $_FILES['upfile']['name'];
	}
	else {
		ErrorMessage('업로드에 실패하였습니다.');
	}
}

//데이터 베이스 연결하기
include_once "db_info.php";

$prev_parent_thread = floor($_POST[parent_thread]/1000)*1000 +1000; 
$update_query = "update $board set thread=thread+1 where thread < $prev_parent_thread and thread > $_POST[parent_thread]";
$update_query .= " order by thread desc";
$update_thread = mysql_query($update_query, $conn) or ErrorMessage('답변 글을 저장하는데 실패하였습니다.');;

$query = "insert into $board (thread,depth,name,pass,email,title,view,wdate,ip,content)";
$query .= " values ('" . ($_POST[parent_thread]+1) . "'";
$query .= ",'" . ($_POST[parent_depth]+1) ."','$_POST[name]','$_POST[pass]','$_POST[email]','$_POST[title]',0";
$query .= ", UNIX_TIMESTAMP(),'$REMOTE_ADDR','$_POST[content]')";
$result=mysql_query($query, $conn) or ErrorMessage('답변 글을 저장하는데 실패하였습니다.');;

//데이터베이스와의 연결 종료
mysql_close($conn);

// 새 글 쓰기인 경우 리스트로..
echo ("<meta http-equiv='Refresh' content='1; URL=list.php'>");

?>
<center>
<font size=2>정상적으로 저장되었습니다.</font> 