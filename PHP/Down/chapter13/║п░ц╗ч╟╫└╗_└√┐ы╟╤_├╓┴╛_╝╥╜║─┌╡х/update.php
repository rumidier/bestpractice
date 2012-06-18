<?

include_once "library.php";

$id = (int)$_GET[id];

$_POST[name] = trim(strip_tags($_POST[name]));
$_POST[email] = trim(strip_tags($_POST[email]));

//입력값 검증
if (!$_POST[name]) ErrorMessage('이름을 입력하세요.');
if (!$_POST[pass]) ErrorMessage('암호를 입력하세요.');
if (!$_POST[title]) ErrorMessage('제목을 입력하세요.');
if (!$_POST[content]) ErrorMessage('내용을 입력하세요.');

$filename="";
$add_query="";
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
		$add_query = ", filename = '$filename' ";
	}
	else {
		ErrorMessage('업로드에 실패하였습니다.');
	}
}

//데이터 베이스 연결하기
include_once "db_info.php";

// 글의 비밀번호를 가져온다.
$result=mysql_query("select pass from $board where id='$id'", $conn) or ErrorMessage('글을 수정하는데 실패하였습니다.');;
$row=mysql_fetch_array($result);

//입력된 값과 비교한다.
if ($_POST[pass]==$row[pass]) { //비밀번호가 일치하는 경우

	$query = "update $board set name='$_POST[name]',title='$_POST[title]',email='$_POST[email]',content='$_POST[content]'";
	$query .= $add_query; //새로운 업로드 파일이 있는 경우
	$query .= "where id='$id' ";
	$result=mysql_query($query, $conn) or ErrorMessage('글을 수정하는데 실패하였습니다.');;
} 
else { // 비밀번호가 일치하지 않는 경우
	ErrorMessage('비밀번호가 틀립니다.');
}

//데이터베이스와의 연결 종료
mysql_close($conn);

//수정하기인 경우 수정된 글로..
echo ("<meta http-equiv='Refresh' content='0; URL=read.php?id=$id'>");

?>