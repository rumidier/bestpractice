<?
//데이터 베이스 연결하기
include "db_info.php";

$prev_parent_thread = ceil($_POST[parent_thread]/1000)*1000 - 1000;

//원본글보다는 작고 위값보다는 큰 글들의 thread 값을 모두 1씩 낮춘다.
$query = "UPDATE $board SET thread=thread-1 WHERE 
thread > $prev_parent_thread and thread < $_POST[parent_thread]";
$update_thread = mysql_query($query, $conn);

//원본글보다는 1작은 값으로 답글을 등록한다.
//원본글의 바로 밑에 등록되게 된다.
//depth는 원본글의 depth + 1 이다. 원본글이 3(이글도 답글이군)이면 답글은 4가된다.
$query = "INSERT INTO $board (thread,depth,name,pass,email";
$query .= ",title,view,wdate,ip,content)";
$query .= " VALUES ('" . ($_POST[parent_thread]-1) . "'";
$query .= ",'" . ($parent_depth+1) ."','$name','$pass','$email'";
$query .= ",'$title',0, UNIX_TIMESTAMP(),'$REMOTE_ADDR'";
$query .= ",'$content')";
$result=mysql_query($query, $conn);

//데이터베이스와의 연결 종료
mysql_close($conn);

// 새 글 쓰기인 경우 리스트로..
echo ("<meta http-equiv='Refresh' content='1; URL=list.php'>");
?>
<center>
<font size=2>정상적으로 저장되었습니다.</font>