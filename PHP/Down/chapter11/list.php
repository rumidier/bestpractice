<?
//데이터 베이스 연결하기
include "db_info.php";

# LIST 설정
# 1. 한 페이지에 보여질 게시물의 수
$page_size=10;

# 2. 페이지 나누기에 표시될 페이지의 수
$page_list_size = 10;

if (!$no || $no < 0) $no=0;

// 데이터베이스에서 페이지의 첫번째 글($no)부터 
// $page_size 만큼의 글을 가져온다.
$query = "SELECT * FROM board ORDER BY id DESC LIMIT $no,$page_size";
$result = mysql_query($query, $conn);

// 총 게시물 수 를 구한다.
$result_count=mysql_query("SELECT count(*) FROM board",$conn);
$result_row=mysql_fetch_row($result_count);
$total_row = $result_row[0];
//결과의 첫번째 열이 count(*) 의 결과다.

# 총 페이지 계산
if ($total_row <= 0) $total_row = 0;
$total_page = ceil($total_row / $page_size);

# 현재 페이지 계산
$current_page = ceil(($no+1)/$page_size);
?>
<html>
<head>
<title>초 허접 게시판</title>
<style>
<!--
td {font-size : 9pt;}
A:link {font : 9pt;color : black;text-decoration : none; fontfamily
: 굴림;font-size : 9pt;}
A:visited {text-decoration : none; color : black; font-size : 9pt;}
A:hover {text-decoration : underline; color : black; font-size : 9pt;}
-->
</style>
</head>
<body topmargin=0 leftmargin=0 text=#464646>
<center>
<BR>
<!-- 게시판 타이틀 -->
<font size=2>자~ 버그를 찾읍시다~ 버그를~~</a>
<BR>
<BR>
<!-- 게시물 리스트를 보이기 위한 테이블 -->
<table width=580 border=0 cellpadding=2 cellspacing=1
bgcolor=#777777>
<!-- 리스트 타이틀 부분 -->
<tr height=20 bgcolor=#999999>
	<td width=30 align=center>
		<font color=white>번호</font>
	</td>
	<td width=370 align=center>
		<font color=white>제 목</font>
	</td>
	<td width=50 align=center>
		<font color=white>글쓴이</font>
	</td>
	<td width=60 align=center>
		<font color=white>날 짜</font>
	</td>
	<td width=40 align=center>
		<font color=white>조회수</font>
	</td>
</tr>
<!-- 리스트 타이틀 끝 -->
<!-- 리스트 부분 시작 -->
<?
while($row=mysql_fetch_array($result))
{
?>
<!-- 행 시작 -->
<tr>
	<!-- 번호 -->
	<td height=20 bgcolor=white align=center>
		<a href="read.php?id=<?=$row[id]?>&no=<?=$no?>">
		<?=$row[id]?></a>
	</td>
	<!-- 번호 끝 -->
	<!-- 제목 -->
	<td height=20 bgcolor=white>&nbsp;
		<a href="read.php?id=<?=$row[id]?>&no=<?=$no?>">
		<?=strip_tags($row[title], '<b><i>');?></a>
	</td>
	<!-- 제목 끝 -->
	<!-- 이름 -->
	<td align=center height=20 bgcolor=white>
		<font color=black>
		<a href="mailto:<?=$row[email]?>"><?=$row[name]?></a>
		</font>
	</td>
	<!-- 이름 끝 -->
	<!-- 날짜 -->
	<td align=center height=20 bgcolor=white>
		<font color=black><?=$row[wdate]?></font>
	</td>
	<!-- 날짜 끝 -->
	<!-- 조회수 -->
	<td align=center height=20 bgcolor=white>
		<font color=black><?=$row[see]?></font>
	</td>
	<!-- 조회수 끝 -->
</tr>
<!-- 행 끝 -->
<?
} // end While
//데이터베이스와의 연결을 끝는다.
mysql_close($conn);
?>
</table>
<!-- 게시물 리스트를 보이기 위한 테이블 끝-->
<!-- 페이지를 표시하기 위한 테이블 -->
<table border=0>
<tr>
	<td width=600 height=20 align=center rowspan=4>
	<font color=gray>
	&nbsp;
<?
$start_page = floor(($current_page - 1) / $page_list_size) 
				* $page_list_size + 1;

# 페이지 리스트의 마지막 페이지가 몇 번째 페이지인지 구하는 부분이다.
$end_page = $start_page + $page_list_size - 1;

if ($total_page < $end_page) $end_page = $total_page;
if ($start_page >= $page_list_size) {
	# 이전 페이지 리스트값은 첫 번째 페이지에서 한 페이지 감소하면 된다.
	# $page_size 를 곱해주는 이유는 글번호로 표시하기 위해서이다.

	$prev_list = ($start_page - 2)*$page_size;
	echo "<a href=\"$PHP_SELF?no=$prev_list\">◀</a>\n";
}

# 페이지 리스트를 출력
for ($i=$start_page;$i <= $end_page;$i++) {
	$page= ($i-1) * $page_size;// 페이지값을 no 값으로 변환.
	if ($no!=$page){ //현재 페이지가 아닐 경우만 링크를 표시
		echo "<a href=\"$PHP_SELF?no=$page\">";
	}
	
	echo " $i "; //페이지를 표시
	
	if ($no!=$page){
		echo "</a>";
	}
}

# 다음 페이지 리스트가 필요할때는 총 페이지가 마지막 리스트보다 클 때이다.
# 리스트를 다 뿌리고도 더 뿌려줄 페이지가 남았을때 다음 버튼이 필요할 것이다.
if($total_page > $end_page)
{
	$next_list = $end_page * $page_size;
	echo "<a href=$PHP_SELF?no=$next_list>▶</a><p>";
}
?>
	</font>
	</td>
</tr>
</table>
<a href=write.php>글쓰기</a>
</center>
</body>
</html>