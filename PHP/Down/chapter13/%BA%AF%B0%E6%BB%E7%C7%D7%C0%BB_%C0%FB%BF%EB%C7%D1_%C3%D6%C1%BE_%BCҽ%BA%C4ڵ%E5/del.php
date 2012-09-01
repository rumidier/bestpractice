<?

include_once "library.php";

//입력값 검증
$id = (int)$_GET[id];

if (!$_POST[pass]) ErrorMessage('암호를 입력하세요.');

//데이터 베이스 연결하기
include_once "db_info.php";

$result=mysql_query("select pass from $board where id='$id'", $conn) 
		or ErrorMessage('글을 삭제하는데 실패하였습니다.');;
$row=mysql_fetch_array($result);

 if ($_POST[pass]==$row[pass] )
 {
	 $conndel = "delete from $board where id='$id'";
	 $result=mysql_query($conndel, $conn) or ErrorMessage('글을 삭제하는데 실패하였습니다.');;

 } 
 else
{
	ErrorMessage('비밀번호가 틀립니다.');
}

?>

<meta http-equiv='Refresh' content='0; URL=list.php'>
