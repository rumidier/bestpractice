<?
  setcookie('php', 'Cool~');
  echo $_COOKIE['php'];
  echo '쿠키 예제';

  $result = setcookie('php', 'Cool~', time()+1000);

  if ($result)
    echo '쿠키 생성 완료';
  else
    echo '쿠키 생성 실패';
?>
