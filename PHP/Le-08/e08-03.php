<?
  if (!isset($_SERVER['PHP_AUTH_USER']) || $_COOKIE['login'] != "1") {
    //웹 브라우저의 헤더로 전송
    header('WWW-Authenticate: Basic realm="사용자 인증 시스템"');
    header('HTTP/1.0 401 Unauthorized');
    setcookie ("login", "1");
    //취소 버튼을 눌렀을 경우
    echo "이 페이지는 사용자 인증이 필요합니다.<br />";
    echo "<a href='{$_SERVER['PHP_SELF']}'>로그인</a>하십시오.";
    exit;
  }
  else {
    //로그아웃
    if($_GET['logout'] == "1") {
      setcookie ("login", "", 0);
      header("location: {$_SERVER['PHP_SELF']}");
      exit;
    }
    //사용자 인증 처리
    if ($_SERVER['PHP_AUTH_USER'] == "brown" && $_SERVER['PHP_AUTH_PW'] == "1234") {
      //로그인된 후 메시지 출력
      echo "안녕하세요. {$_SERBER['PHP_AUTH_USER']}님<br />";
      echo "<a href='".$_SERVER['PHP_SELF']."?logout=1'>로그아웃</a>";
    }
    else {
      //사용자 인증 실패 후
      setcookie ("login", "0");
      echo "이 페이지는 사용자 인증이 필요합니다.<br />";
      echo "<a href='{$_SERVER[PHP_SELF]}'>로그인</a>하십시오.";
      exit;
    }
  }
?>
