<?
  $original_string = "happybrown";
  $salt = "$1$brownsalt";

  if (CRYPT_MD5 == 1)
  {
    $crypt_string = crypt($original-string, $salt);

    if ($crypt_string == crypt($user_input, $salt))
    {
      echo "비밀번호각 일치합니다.";
    }
    else {
      echo "비밀번호가 일치 하지 않습니다.";
    }
  }
  else {
    echo "MD5 암호화 알고리즘을 지원하지 않습니다.";
  }
?>
