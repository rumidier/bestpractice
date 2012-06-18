<?
//데이터 베이스 연결하기
include "db_info.php";
include "library.php";
$id = $_GET[id];
$no = $_GET[no];

// 조회수 업데이트
$query  = "UPDATE $board SET view= view + 1 WHERE id=$id";
$result = mysql_query($query, $conn);

// 글 정보 가져오기
$query  = "SELECT * FROM $board WHERE id=$id";
$result = mysql_query($query, $conn);
$row    = mysql_fetch_array($result);
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html>
  <head>
    <title>계층형 게시판</title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
    <style>
	<!--
	td { font-size : 9pt; }
	A:link { font : 9pt; color : black; text-decoration : none; font-family: 굴림; font-size : 9pt; }
	A:visited { text-decoration : none; color : black; font-size : 9pt; }
	A:hover { text-decoration : underline; color : black; font-size : 9pt;}
	-->
    </style>
  </head>

  <body topmargin=0 leftmargin=0 text=#464646>
    <center>
    <br />
    <table width=580 border=0 cellpadding=2 cellspacing=1 bgcolor=#777777>
	<tr>
	  <td height=20 colspan=4 align=center bgcolor=#999999>
	    <font color=white><b><?=strip_tags(remove_html($row[title]));?></b></font>
	  </td>
	</tr>
	<tr>
	  <td width=50 height=20 align=center bgcolor=#EEEEEE>글쓴이</td>
	  <td width=240 bgcolor=white><?=$row[name]?></td>
	  <td width=50 height=20 align=center bgcolor=#EEEEEE>이메일</td>
	  <td width=240 bgcolor=white><?=$row[email]?></td>
	</tr>
        <tr>
	  <td width=50 height=20 align=center bgcolor=#EEEEEE>
		날&nbsp;&nbsp;&nbsp;짜</td><td width=240 bgcolor=white>
		<?=date("Y-m-d", $row[wdate])?></td>
	  <td width=50 height=20 align=center bgcolor=#EEEEEE>조회수</td>
	  <td width=240 bgcolor=white><?=$row[view]?></td>
	</tr>
	<tr>
	  <td bgcolor=white colspan=4 style="table-layout:fixed;">
	    <font color=black>
	    <?=nl2br(str_replace(" ","&nbsp;", strip_tags(remove_html($row[content]))));?>
	    </font>

	    <br /><br />
	    <? include "comment.php"; ?>
	  </td>
	</tr>
<!-- 기타 버튼 들 -->
        <tr>
	  <td colspan=4 bgcolor=#999999>
	    <table width=100%>
	    <tr>
	      <td width=280 align=left height=20>
		<a href=list.php?no=<?=$no?>><font color=white>[목록보기]</font></a>
		<a href=reply.php?id=<?=$id?>><font color=white>[답글달기]</font></a>
		<a href=write.php><font color=white>[글쓰기]</font></a>
		<a href=edit.php?id=<?=$id?>><font color=white>[수정]</font></a>
		<a href=predel.php?id=<?=$id?>><font color=white>[삭제]</font></a>
	      </td>
	    </tr>
	    </table>
	  </td>
	</tr>
    </table>

    <table width=580 bgcolor=white style="border-bottom-width:1;
    border-bottom-style:solid;border-bottom-color:cccccc;">
<?
  $query   = "SELECT id, name, title FROM $board WHERE thread < $row[thread] and depth=0 ORDER BY thread DESC LIMIT 1";
  $query   = mysql_query($query, $conn);
  $up_id   = mysql_fetch_array($query);

  if ($up_id[id]) // 이전 글이 있을 경우
  {
    echo "<tr><td width=500 align=left height=25>";
    echo "<a href=read.php?id=$up_id[id]>△ " . remove_html($up_id[title]) . "</a></td>
    <td	align=right>$up_id[name]</td></tr>";
  }

  $query   = "SELECT id, name, title FROM $board WHERE thread > $row[thread] and depth=0 LIMIT 1";
  $query   = mysql_query($query, $conn);
  $down_id = mysql_fetch_array($query);

  if ($down_id[id])
  {
    echo "<tr><td width=500 align=left height=25>";
    echo "<a href=read.php?id=$down_id[id]>▽ " . remove_html($down_id[title]) . "</a> </td>
      <td align=right>$down_id[name]</td></tr>";
  }
?>

    </table>
    <br />

<?
  $thread_end   = floor($row[thread]/1000)*1000;
  $thread_start = $thread_end + 1000;

  $query = "SELECT * FROM $board WHERE thread >= $thread_end and thread < $thread_start ORDER BY thread";
  $result = mysql_query($query, $conn);
?>

    <!-- 게시물 리스트를 보이기 위한 테이블 -->
    <table width=580 border=0 cellpadding=2 cellspacing=1 bgcolor=#777777>
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
	      <a href="read.php?id=<?=$row[id]?>&no=<?=$no?>"><?=$row[id]?></a>
      </td>
      <!-- 번호 끝 -->
      <!-- 제목 -->
      <td height=20 bgcolor=white>&nbsp;
	      <? //depth 값을 통해서 들여쓰기를 한다. 투명이미지의 가로사이즈를 늘이는 방법
	      if ($row[depth] > 0) 
		      echo "<img src=img/dot.gif height=1 width=" . 
		      $row[depth]*7 . ">->";
	      ?>
	      <a href="read.php?id=<?=$row[id]?>&no=<?=$no?>">
	      <?=strip_tags(remove_html($row[title]), '<b><i>');?></a>
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
mysql_close($conn);
?>
  </center>
  </body>
</html>
