<?
  $count = file("count.txt");
  $count = trim($count[0]);

  if (!isset($_COOKIE['visit'])) {
    $count++;
    $fp = fopen("count.txt", "w");
    fwrite($fp, $count);
    fclose($fp);

    setcookie("visit");
  }
  echo $count;
?>
