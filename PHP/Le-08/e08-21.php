<?
  include "db_info.php";

  //사용자가 입력한 아이디와 비밀번호를 갖는 레코드의 수를 검색한다.
  $query = "select count(*) from users where userid = '{$_POST[userid]}' and userpw='{$_POST[userpw]}'";
  $result = mysql_query($query, $conn);
  $row = mysql_fetch_row($result);

  //검색 결과가 1이면 성공적으로 로그인 된다.
  if ($row[0] == 1)
  {
    //로그인 상태를 유지하기 위해 쿠키를 발급한다.
    setcookie("userid",$_POST['userid'],0,"/");
    echo "안녕하세요. {$_POST['userid']} 님.<br />";
  }
  else {
    echo "이 페이지는 사용자 인증이 필요합니다.";
    exit;
  }
?>
