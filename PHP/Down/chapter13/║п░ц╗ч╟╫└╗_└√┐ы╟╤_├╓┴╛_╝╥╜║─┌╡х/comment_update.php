<?

include_once "library.php";

$id = (int)$_POST[id];
$_POST[name] = trim(strip_tags($_POST[name]));

//입력값 검증
if (!$_POST[name]) ErrorMessage('이름을 입력하세요.');
if (!$_POST[pass]) ErrorMessage('암호를 입력하세요.');
if (!$_POST[comment]) ErrorMessage('내용을 입력하세요.');

//데이터 베이스 연결하기
include_once "db_info.php";

// 글의 비밀번호를 가져온다.
$result=mysql_query("SELECT pass FROM comment WHERE id='$id'", $conn) or ErrorMessage('덧글을 수정하는데 실패하였습니다.');;
$row=mysql_fetch_array($result);

//입력된 값과 비교한다.
if ($_POST[pass]==$row[pass]) { //비밀번호가 일치하는 경우

	$query = "UPDATE comment SET name='$_POST[name]', comment='$_POST[comment]'";
	$query .= " WHERE id='$id' ";
	$result=mysql_query($query, $conn) or ErrorMessage('덧글을 수정하는데 실패하였습니다.');;
} 
else { // 비밀번호가 일치하지 않는 경우
	ErrorMessage('비밀번호가 틀립니다.');
}

//데이터베이스와의 연결 종료
mysql_close($conn);

//수정하기인 경우 수정된 글로..
echo ("<meta http-equiv='Refresh' content='0; URL=read.php?id=$_POST[bid]'>");

?>