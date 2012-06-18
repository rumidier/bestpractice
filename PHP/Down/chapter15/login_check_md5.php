<?
	function check_sid() {
		$get_userid = $_COOKIE['userid'];
		$get_sid = $_COOKIE['sid'];

		if (!$get_userid) return false;
		if (!$get_sid) return false;

		$get_userid .="brown";
		$real_sid = md5($get_userid);

		if ($get_sid == $real_sid) return true;
		else return false;
	}

	if (check_sid()) echo $_COOKIE['userid'] . "님 안녕하세요.";
	else { echo "로그인 하세요."; exit; }
	if ($_COOKIE['userid'] == 'admin') echo "<BR>관리자로 로그인되었습니다.";
?>