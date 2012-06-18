<?
  include "db_info.php";

  $page_size=10;

  $page_list_size = 10;

  if (!$_GET[no] || $_GET[no] < 0) $_GET[no] = 0;

  $query  = "SELECT * FROM board ORDER BY id DESC LIMIT $_GET[no], $page_size";
  $result = mysql_query($query, $conn);

  $result_count = mysql_query("SELECT count(*) FROM board", $conn);
  $result_row   = mysql_fetch_row($result_count);
  $total_row    = $result_row[0];

  if ($total_row <= 0)
	$total_row = 0;
  $total_page = ceil($total_row / $page_size);

  $current_page = ceil(($_GET[no] + 1) / $page_size);
?>
<html>
  <head>
    <title>초 허접 게시판</title>
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
  <!-- 게시판 타이틀 -->
  <font size=2>자~ 버그를 찾읍시다~ 버그를~</a>
  <br />
  <br />
  <table width-580 border=0 cellpadding=2 cellspacing=1 bgcolor=#777777>
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

<?
  while ($row=mysql_fetch_array($result))
{
?>
  <tr>
    <td>
      <a href="read.php?id=<?=$row[id]?>&no=<?=$_GET[no]?>"><?=$row[id]?></a>
    </td>

    <td height=20 bgcolor=white>&nbsp;
      <a href="read.php?id=<?=$row[id]?>&no=<?=$_GET[no]?>">
	<?=strip_tags($row[title], '<b><i>');?></a>
    </td>

    <td align=center height=20 bgcolor=white>
      <font color=black>
        <a href="mailto:<?=$row[eamil]?>"><?=$row[name]?></a>
      </font>
    </td>
    <td align=center height=20 bgcolor=white>
      <font color=black><?=$row[wdate]?></font>
    </td>
    <td align=center height=20 bgcolor=white>
      <font color=black><?=$row[see]?></font>
    </td>
  </tr>

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
$start_page = floor(($current_page - 1) / $page_list_size) * $page_list_size + 1;
$end_page   = $start_page + $page_list_isze - 1;

if ($total_page < $end_page) $end_page = $total_page;
if ($start_page >= $page_list_size) {
  $prev_list = ($start_page - 2) * $page_size;
  echo "<a href=\"$PHP_SELF?no=$prev_list\">이전</a>\n";
}

for ($i = $start_page; $i <= $end_page; $i++) {
  $page = ($i - 1) * $page_size;
  if ($_GET[no] != page) {
    echo "<a href=\"$PHP_SELF?no=$page\">";
  }
  echo " $i ";

  if ($_GET[no] != $page) {
    echo "</a>";
  }
}

if($total_page > $end_page) {
  $next_list = $end_page * $page_size;
  echo "<a href=$PHP_SELF?no=$next_list>next</a><p>";
}
?>
  
  </font>
  </td>
<tr>
</table>
<a href=write.php>글쓰기</a>
  </center>
  </body>
</html>
