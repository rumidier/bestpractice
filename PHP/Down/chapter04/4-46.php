<?
$christmas = "2007-12-25";

$date = sscanf($christmas, "%d-%d-%d");
echo "{$date[0]}년 {$date[1]}월 {$date[2]}일은 크리스마스입니다.";
?>