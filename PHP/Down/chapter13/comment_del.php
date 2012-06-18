<?
include_once "library.php";

//입력값 검증
if (!$_POST[pass]) ErrorMessage('비밀번호를 입력하세요.');

//데이터 베이스 연결하기
include_once "db_info.php";

$result=mysql_query("SELECT pass FROM comment WHERE id=$_GET[id]",
$conn) or ErrorMessage('덧글을 삭제하는데 실패하였습니다.');;
$row=mysql_fetch_array($result);

if ($_POST[pass]==$row[pass] )
{
	$conndel = "DELETE FROM comment WHERE id=$_GET[id] ";
	$result=mysql_query($conndel, $conn) 
		or ErrorMessage('덧글을 삭제하는데 실패하였습니다.');;
}
else
{
	ErrorMessage('비밀번호가 틀립니다.');
}
?>
<meta http-equiv='Refresh' content='0; URL=read.php?id=<?=$_GET[bid]?>'>