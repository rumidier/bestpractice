<?
  // microtime(TRUE)의 역할을 하는 함수
  function microtime_float()
  {
    list($usec, $sec) = explode(" ", microtime());
    return ((float)$usec + (float)$sec);
  }

  $start_time = microtime_float();
  echo "$start_time";

  $sun = 0;
  for ($i = 1; $i <= 1000; $i++) {
    $sum += $i;
  }
  $end_time = microtime_float();

  echo "합 : $sum <br />";
  echo "총 소요시간 : " . ($end_time - $start_time);
?>
