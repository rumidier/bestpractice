<?
//데이터 베이스 연결하기
include "db_info.php";

//Thread 값을 계산한다.
$query = "SELECT max(thread) FROM $board";
$max_thread_result = mysql_query($query, $conn);
$max_thread_fetch = mysql_fetch_row($max_thread_result);

$max_thread = ceil($max_thread_fetch[0]/1000)*1000+1000;

$query = "INSERT INTO $board (thread, depth, name, pass, email,
title, view, wdate, ip, content) 
VALUES ($max_thread, 0, '$_POST[name]', '$_POST[pass]', 
'$_POST[email]', '$_POST[title]', 0,
UNIX_TIMESTAMP(), '$REMOTE_ADDR', '$_POST[content]')";
$result=mysql_query($query, $conn);

//데이터베이스와의 연결 종료
mysql_close($conn);

// 새 글 쓰기인 경우 리스트로..
echo ("<meta http-equiv='Refresh' content='1; URL=list.php'>");
?>
<center>
<font size=2>정상적으로 저장되었습니다.</font>
