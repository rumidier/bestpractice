<?
//데이터 베이스 연결하기
include "db_info.php";
include_once "library.php";

#########################################################################
# LIST 설정
# 1. 한 페이지에 보여질 게시물의 수

$page_size=10; 

# 2. 페이지 나누기에 표시될 페이지의 수

$page_list_size = 10;

#########################################################################

$no = (int)$_GET[no];
if (!$no || $no < 0) $no=0; //$no 값이 안넘어 오거나 잘못된(음수)값이 넘어오는 경우 0으로 처리

#########################################################################

// 데이터베이스에서 페이지의 첫번째 글($no)부터 $page_size 만큼의 글을 가져온다.
$st = explode(" ", microtime());
$query = "
			SELECT * , (SELECT COUNT(*) FROM comment WHERE bid = board.id) as cnt FROM $board as board
			WHERE thread >= (
					SELECT thread FROM $board 
					ORDER bY thread 
					LIMIT $no,1
					) 
			ORDER BY thread 
			LIMIT $page_size;
		";
$result = mysql_query($query, $conn) or ErrorMessage('글 목록을 가져오는 도중 오류가 발생하였습니다.', false);

$et = explode(" ", microtime());
//echo $et[1]-$st[1]+$et[0]-$st[0];
// 총 게시물 수 를 구한다.
//count 를 통해 구할 수 있는데 count(항목) 과 같은 방법으로 사용한다. * 는 모든 항목을 뜻한다.
//총 해당 항목의 값을 가지는 게시물의 개수가 얼마인가를 묻는것이다.
//따라서 전체 글수가 된다. count(id) 와 같은 방법도 가능하지만 이례적으로 count(*)가 조금 빠르다. 일반적으로는 * 가 느리다.
$result_count=mysql_query("select count(*) from $board",$conn) or ErrorMessage('글 목록을 가져오는 도중 오류가 발생하였습니다.', false);
$result_row=mysql_fetch_row($result_count);
$total_row = $result_row[0]; 
//결과의 첫번째 열이 count(*) 의 결과다.

#########################################################################
# 총 페이지 계산

if ($total_row <= 0) $total_row = 0; // 총게시물의 값이 없거나 할경우 기본값으로 세팅

// 총게시물에 1을 뺀뒤 페이지 사이즈로 나누고 소수점이하를 버린다.
$total_page = floor(($total_row - 1) / $page_size);


# 총페이지는 총 게시물의 수를 $page_size 로 나누면 알수있다.
# 총 게시물이 12개(1을 빼서 11이된다)이고 페이지 사이즈가 10이라면 결과는 1.1 이 나올것이다.
# 1.1 라는 페이지수는 한 페이지를 다 표시하고도 글이 더 남아있다는 뜻이다.
# 따라서 실제의 페이지수는 2가된다. 한 페이지는 2개의 글만 표시될것이다.
# 그러나 내림을 해주는 이유는 페이지수가 0부터 시작하기 때문이다. 따라서 1은 두번째 페이지이다.
# 총 게시물에 1을 빼주는 이유는 10페이지가 되면 10/10 = 1 이기 때문이다.
# 앞에서도 말했지만 1은 2번째 페이지를 뜻한다.
# 그러나 총게시물이 10개인 경우 한페이지에 모두 출력이 되어야 한다.
# 그래서 1을 빼서 10개인 경우 (10-1) / 10 = 0.9 로 한페이지에 출력하게 한다.
# 글이 0개가 있는 경우는 결과가 -1 이 되지만 -1은 무시된다.
# ( floor 는 내림을 하는 수학함수이다.)
#########################################################################
# 현재 페이지 계산

$current_page = floor($no/$page_size);

# $no 을 통해서 페이지의 첫번째 글이 몇번째 글인지 전달된다.
# 따라서 페이지 사이즈로 나누면 현재가 몇번째 페이지인지 알수있다.
# $no 이 10이고 페이지사이즈가 10 이라면 결과는 1이다. 앞서 페이지는 0부터 시작이라고 했으니 두번째 페이지임을 나타낸다.
# 그렇다면 $no 이 11이라면 1.1 이 되어버린다. 11번째 글도 두번째 페이지에 존재하므로 0.1은 무의미하니 버린다.
# 그런데 $no 이란 값이 $page_size 만큼씩 증가되는 값이기때문에 (0,10,20,30 과 같은 등차수열) 내림을 하는것 또한 무의미하다.
# 그러나 내림을 하는 이유는 $no 값에 11과 같은 값이 들어와도 제대로 출력되기를 바라는 마음에서 해놓은것이다.
?>

<html>
<head>
<title>계층형 게시판</title>
<style>
<!--
td { font-size : 9pt; }
A:link { font : 9pt; color : black; text-decoration : none; font-family : 굴림; font-size : 9pt; }
A:visited { text-decoration : none; color : black; font-size : 9pt; }
A:hover { text-decoration : underline; color : black; font-size : 9pt; }

--> 
</style>
</head>

<body topmargin=0 leftmargin=0 text=#464646 style="table-layout:fixed;">
<center>
<BR>
<!-- 게시물 리스트를 보이기 위한 테이블 -->
<table width=600 border=0 cellpadding=2 cellspacing=1 bgcolor=#777777>
<!-- 리스트 타이틀 부분 -->
<tr height=20 bgcolor=#999999>
<td width=50 align=center>
<font color=white>번호</font>
</td>
<td width=370 align=center>
<font color=white>제 목</font>
</td>
<td width=50 align=center>
<font color=white>글쓴이</font>
</td> 
<td width=80 align=center>
<font color=white>날 짜</font>
</td>
<td width=50 align=center>
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
<a href=read.php?id=<?=$row[id]?>&no=<?=$no?>><?=$row[id]?></a>
</td>
<!-- 번호 끝 -->
<!-- 제목 -->
<td height=20 bgcolor=white>&nbsp;
<? if ($row[depth] > 0) echo "<img height=1 width=" . $row[depth]*7 . ">└"?>
<a href=read.php?id=<?=$row[id]?>&no=<?=$no?>><?=remove_html($row[title]);?> <FONT style="font-size:8pt" COLOR="orange">[<?=$row[cnt];?>]</FONT></a>
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
<font color=black><?=date("Y-m-d",$row[wdate])?></font>
</td>
<!-- 날짜 끝 -->
<!-- 조회수 -->
<td align=center height=20 bgcolor=white>
<font color=black><?=$row[view]?></font>
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
<table border=0 width=700>
<tr>
<td  height=20 align=center rowspan=4>
<font color=gray>
&nbsp;
<?
#########################################################################
# 페이지 리스트
# 페이지 리스트의 첫번째로 표시될 페이지가 몇번째 페이지인지 구하는 부분이다.

$start_page = (int)($current_page / $page_list_size) * $page_list_size;

#현재 페이지를 페이지 리스트 수로 나누면 현재 페이지가 몇번째 페이지리스트에 있는지 알게된다.
# 이또한 0을 기준으로 하기에 형변환(타입 캐스팅)을 해주었다.
# 형변환은 앞 강좌에서 배웠지만 위의 나누어지는 수가 1.2와 같이 유리수로 표시되기때문에
# int(정수) 형으로 형변환을 하게되면 소수점자리가 사라지게 된다.
# 즉, 위에서 사용한 floor 랑 같은 효과를 하게 되는 것이다. 
# 여기에 floor 함수를 취하거나 위의 floor 를 형변환을 해도 상관없다.

# 페이지 리스트의 마지막 페이지가 몇번째 페이지인지 구하는 부분이다.
$end_page = $start_page + $page_list_size - 1;
if ($total_page < $end_page) $end_page = $total_page;

# 보여주는 페이지 리스트중에서 마지막 페이지가 되는 경우는 두가지이다.
# 1. 페이지가 페이지리스트 크기보다 더 많이 남아있을때 
# 10개씩 뿌려주는데 총 11페이지가 존재한다면 11페이지는 두번째 목록페이지에 뿌려진다.
# 그렇다면 마지막 페이지 리스트는 10페이지 즉, 첫번째 페이지 + 9 번째 페이지이다.
# 2. 10개씩 뿌려주는데 5페이지 밖에 없다면?
# 마지막 리스트 페이지는 5 페이지가 된다.

#########################################################################
# 이전 페이지 리스트 보여주기
# 페이지 리스트가 10인데 13번째 페이지에 있다면 두번째 목록페이지를 보고 있는것이다.
# 이전 목록페이지로 가고 싶을 때 사용한다.

# 이전 페이지 리스트가 필요할때는 페이지 리스트의 첫 페이지가 페이지 리스트 수보다 클때다.
# 페이지가 적어도 페이지 리스트 수보다는 커야 이전 페이지 리스트가 존재할테니까 말이다.
# 페이지 리스트의 수가 10인데 총 5페이지밖에 없다면 이전 페이지 리스트는 존재하지 않는다.
if ($start_page >= $page_list_size) {

# 이전 페이지 리스트값은 첫번째 페이지 리스트에서 뒤로 리스트의 수만큼 이동하면된다.
# $page_size 를 곱해주는 이유는 글번호로 표시하기 위해서이다. 
$prev_list = ($start_page - 1)*$page_size;
echo "<a href=\"$PHP_SELF?no=$prev_list\">◀</a>\n";
}

# 페이지 리스트를 출력
for ($i=$start_page;$i <= $end_page;$i++) {

$page=$page_size*$i; // 페이지값을 no 값으로 변환.
$page_num = $i+1; // 실제 페이지 값이 0부터 시작하므로 표시할때는 1을 더해준다. 페이지 0 -> 1

if ($no!=$page){ //현재 페이지가 아닐 경우만 링크를 표시
echo "<a href=\"$PHP_SELF?no=$page\">";
}

echo " $page_num "; //페이지를 표시

if ($no!=$page){
echo "</a>";
}

}

# 다음 페이지 리스트가 필요할때는 총 페이지가 마지막 리스트보다 클 때이다.
# 리스트를 다 뿌리고도 더 뿌려줄 페이지가 남았을때 다음 버튼이 필요할 것이다.

if($total_page > $end_page)
{
# 다음 페이지 리스트는 마지막 리스트 페이지보다 한 페이지 뒤로 이동하면 된다.
$next_list = ($end_page + 1)* $page_size;
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