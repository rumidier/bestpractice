<?
//스크립트 종료할때까지
set_time_limit(0);

//데이터 베이스 연결하기
include "db_info.php";

// 글 등록에 대한 기본적인 정보
$name = "브라운";
$pass = "1234";
$email = "happybrown@naver.com";

if (ob_get_level() == 0) ob_start();

for ($i=1;$i<=1000000;$i++)
{
	$title = "$i 번째 테스트 게시물";
	$content = "$i 번째 테스트 게시물 내용";

	// 답글을 위해 thread 값은 index 값의 1000배
	$max_thread = $i * 1000;

	$query = "INSERT INTO $board (id,thread,depth,name,pass,email,
	title,view,wdate,ip,content) ";
	$query .= "VALUES ('',$max_thread,0,'$name','$pass','$email',
	'$title',0, UNIX_TIMESTAMP(), '$REMOTE_ADDR','$content')";
	$result=mysql_query($query, $conn);

	if ($result) {
		$success++;
		print("$i INSERT 성공<BR>\r\n");
	}
	else {
		$failure++;
		print("$i INSERT <B>실패</B><BR>\r\n");
	}
	
	// 이 프로그램이 시스템 자원을 많이 할당받는것을 막기위해
	// 10000번당 1초씩 쉬어줍니다.
	if(($i%10000) == 0) sleep(1);
}
//데이터베이스와의 연결 종료
mysql_close($conn);
?>