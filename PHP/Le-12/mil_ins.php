<?
  set_time_limit (0);

  include "db_info.php";

  $name  = "브라운";
  $pass  = "1234";
  $email = "happy@naver.com";

  if (ob_get_level () == 0)
    ob_start();

  for ($i = 1; $i <= 1000000; $i++)
  {
    $title = "$i 번째 테스트 게시물";
    $content = "$i 번째 테스트 게시물 내용";

    $max_thread = $i * 1000;

    $query = "INSERT INTO $board (id, thread, depth, name, pass, email, title, view, wdate, ip, content)
	    VALUES ('', '$max_thread', '0', '$name', '$pass', '$email', '$title', '0', UNIX_TIMESTAMP(), '$_SERVER[REMOTE_ADDR]', '$content')";
    $result = mysql_query($query, $conn);

    if ($result) {
      $success++;
      print ("$i INSERT <b>성공</b><br />\n");
    }
    else {
      $failure++;
      print ("$i INSERT <b>실패</b><br />\n");
    }

    if (($i % 10000) == 0) sleep(1);
  }

mysql_close($conn);
?>
