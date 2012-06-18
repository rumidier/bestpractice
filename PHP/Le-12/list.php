<?
  include "db_info.php";
  include "library.php";

  $page_size=10;
  $page_list_size = 10;

  $no = $_GET[no];
  if (!$no || $no < 0)
    $no = 0;

  $query        = "SELECT * , (SELECT COUNT(*) FROM comment WHERE bid = board.id)
  as cnt FROM $board as board WHERE thread >= (SELECT thread FROM $board ORDER BY thread LIMIT $no, 1) ORDER BY thread LIMIT $page_size";
  $result       = mysql_query($query, $conn) or ErrorMessage(' 글 목록을 가져오는 도중 오류가 발생하였습니다.', false);

  $result_count = mysql_query("SELECT count(*) FROM $board", $conn) or ErrorMessage('글 목록을 가져오는 도중 오류가 발생하였습니다.', false);
  $result_row   = mysql_fetch_row($result_count);
  $total_row    = $result_row[0];

  if ($total_row <= 0) $total_row = 0; // 총 게시물의 값이 없을 경우 기본값으로 세팅

  $total_page = floor(($total_row - 1) / $page_size);
 $current_page = floor($no / $page_size); 
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

  <body topmargin=0 leftmargin=0 text=#464646>
  <center>
  <br />
  <!-- 게시물 리스트를 보이기 위한 테이블 -->
  <table width=580 border=0 cellpadding=2 cellsacing=1 bgcolor=#777777>
  <!-- 리스트 타이틀 부분 -->
  <tr height=20 bgcolor=#999999>
    <td width=30 align=center>
      <font color=white>번호</font>
    </td>
    <td width=370 align=center>
      <font color=white>제목</font>
    </td>
    <td width=50 align=center>
      <font color=white>글쓴이</font>
    </td>
    <td width=60 align=center>
      <font color=white>날짜</font>
    </td>
    <td width=40 align=center>
      <font color=white>조회수</font>
    </td>
  </tr>
<!-- 리스트 타이틀 끝 -->
<!-- 리스트 부분 시작 -->
<?
  while ($row=mysql_fetch_array($result)) {
?>
  <!-- 행 시작 -->
  <tr>
    <!-- 번호 -->
    <td height=20 bgcolor=white align=center>
      <a href="read.php?id=<?=$row[id]?>&no=<?=$no?>"><?=$row[id]?></a>
    </td>
    <!-- 번호 끝 -->

    <!-- 제목 -->
    <td height=20 bgcolor=white>&nbsp;
      <?
	if ($row[depth] > 0)
	  echo "<img height=1 width=" . $row[depth]* 7 . ">L";
      ?>
	<a href="read.php?id=<?=$row[id]?>&no=<?=$no?>"><?=strip_tags(remove_html($row[title]));?><font sytle="font-size:8pt" color="orange">[<?=$row[cnt];?>]</font></a>
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
      <font color=black><?=date("Y-m-d", $row[wdate])?></font>
    </td>
    <!-- 날짜 끝 -->
    <!-- 조회 수 -->
    <td align=center height=20 bgcolor=white>
      <font color=black><?=$row[view]?></font>
    </td>
<!-- 조회 수 끝 -->
  </tr>
<!-- 행 끝 -->

<?
  }
mysql_close($conn);
?>
</table>
<table border=0>
  <tr>
    <td width=600 height=20 align=center rowspan=4>
    <font color=gray>
    &nbsp;
<?
  $start_page = (int)($current_page / $page_list_size) * $page_list_size;
  $end_page   = $start_page + $page_list_size - 1;

  if ($total_page < $end_page)
    $end_page = $total_page;

  if ($start_page >= $page_list_size) {
    $prev_list = ($start_page - 1) * $page_size;
    echo "<a href=\"$PHP_SELF?no=$prev_llit\">pre</a>\n";
  }

for ($i=$start_page; $i <= $end_page; $i++) {
  $page = $page_size * $i;
  $page_num = $i + 1;

  if ($no != $page) {
    echo "<a href=\"$PHP_SELF?no=$page\">";
  }
  echo " $page_num ";

  if ($no != $page) {
    echo "</a>";
  }
}
if ($total_page > $end_page)
{
  $next_list = ($end_page + 1) * $page_size;
  echo "<a href=$PHP_SELF?no=$next_list>next</a><p>";
}
?>
</font>
</td>
  </tr>
</table>
  <a href=write.php>글쓰기</a>
  </body>
</html>
