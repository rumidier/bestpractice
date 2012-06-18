<?
	include "db_info.php";

	//사용자가 입력한 아이디와 비밀번호를 갖는 레코드의 수를 검색한다.
	$query = "SELECT count(*) FROM users WHERE userid = '{$_POST[userid]}'
	and userpw = '{$_POST[userpw]}'";

	$result = mysql_query($query, $conn);
	$row = mysql_fetch_array($result);

	//검색 결과가 1이면 성공적으로 로그인이 된다.
	if ($row[0] == 1)
	{
		echo "안녕하세요. {$_POST['userid']} 님.<BR>";
	}
	else
	{
		echo "이 페이지는 사용자 인증이 필요합니다.";
		exit;
	}
?>