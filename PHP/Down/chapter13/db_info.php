<?

$board="threadboard";

$conn=@mysql_connect("localhost","아이디","패스워드") or die('데이터베이스에 연결할 수 없습니다');
@mysql_select_db("데이터베이스명", $conn) or die('선택한 데이터베이스를 사용할 수 없습니다.');
@mysql_query("set names euckr");

?>