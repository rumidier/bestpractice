<?
	include "db_info.php";

	//사용자가 입력한 아이디의 비밀번호를 검색한다.
	$query = "SELECT userpw FROM users WHERE userid = '{$_POST[userid]}'";
	$result = mysql_query($query, $conn);
	$row = mysql_fetch_array($result);

	//사용자가 입력한 비밀번호와 비교한다.
	if (!empty($row) && ($row[userpw] == $_POST[userpw]))
	{
		echo "안녕하세요. {$_POST['userid']} 님.<BR>";
	}
	else
	{
		echo "이 페이지는 사용자 인증이 필요합니다.";
		exit;
	}
?>