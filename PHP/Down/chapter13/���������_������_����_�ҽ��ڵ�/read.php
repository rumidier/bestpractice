<?
//데이터 베이스 연결하기
include "db_info.php";
include_once "library.php";

$id = (int)$_GET[id];
$no = (int)$_GET[no];

// 조회수 업데이트
$result=mysql_query("update $board set view=view+1 where id=$id", $conn);

// 글 정보 가져오기
$result=mysql_query("select * from $board where id=$id", $conn);
$row=mysql_fetch_array($result);

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
<BR>
<table width=600 border=0 cellpadding=2 cellspacing=1 bgcolor=#777777 style="table-layout:fixed;">
<tr>
<td height=20 colspan=4 align=center bgcolor=#999999>
<font color=white><B><?=remove_html($row[title]);?></B></font>
</td>
</tr>
<tr>
<td width=50 height=20 align=center bgcolor=#EEEEEE>글쓴이</td><td width=240 bgcolor=white><?=$row[name]?></td>
<td width=50 height=20 align=center bgcolor=#EEEEEE>이메일</td><td width=240 bgcolor=white><?=$row[email]?></td>
</tr>
<tr>
<td width=50 height=20 align=center bgcolor=#EEEEEE>날&nbsp;&nbsp;&nbsp;짜</td><td width=240 bgcolor=white><?=date("Y-m-d",$row[wdate])?></td>
<td width=50 height=20 align=center bgcolor=#EEEEEE>조회수</td><td width=240 bgcolor=white><?=$row[view]?></td>
</tr>
<tr>
<td bgcolor=white colspan=4 style="word-break:break-all;">
<BR>
<font color=black>
<?
	if ($row[filename]) {
		echo "첨부된 파일 : <a href='uploads_dir/$row[filename]'>$row[filename]</a><BR><BR>";
	}
?>
<?=nl2br(str_replace(" ", "&nbsp;", remove_html($row[content])));?>
</font>
        <BR><BR>
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

<table  width=580 bgcolor=white style="border-bottom-width:1; border-bottom-style:solid;border-bottom-color:cccccc;">
<?
// 현재 글보다 thread 값이 큰 글 중 가장 작은 것의 id를 가져온다.
$query=mysql_query("select id, name, title from $board where thread < $row[thread] and depth=0 order by thread desc limit 1", $conn);
$up_id=mysql_fetch_array($query);

if ($up_id[id]) // 이전 글이 있을 경우
{
echo "<tr><td width=500 align=left height=25>";
echo "<a href=read.php?id=$up_id[id]>△ " . remove_html($up_id[title]) . "</a></td><td align=right>$up_id[name]</td></tr>";
}

// 현재 글보다 thread 값이 작은 글 중 가장 큰 것의 id를 가져온다.
$query=mysql_query("select id, name, title from $board where thread > $row[thread] and depth=0 limit 1", $conn);
$down_id=mysql_fetch_array($query);

if ($down_id[id])
{
echo "<tr><td width=500 align=left height=25>";
echo "<a href=read.php?id=$down_id[id]>▽ " . remove_html($down_id[title]) . "</a></td><td align=right>$down_id[name]</td></tr>";
}
?>
</table>
<BR>
<?
//리스트 출력을 위해 thread를 계산한다.
//출력될 리스트는 글 전체 리스트가 아니라
//1000의 배수인 새글과 이를 포함한 답변글들의 리스트이다.
//답변글이 없는 경우 원본글만 리스트에 나오고
//답변글이 있으면 답변글 모두가 다 나오게된다.
//현재 글이 답변글이어도 새글부터 전체 답변글까지 나온다.
//그럴려면 1000~2000 과 같이 새글사이에 글들을 모두 뿌려주면 된다.
$thread_start = (floor($row[thread]/1000)+1)*1000;
$thread_end = floor($row[thread]/1000)*1000;
$query = "select * from $board where thread >= $thread_end and thread < $thread_start order by thread";
$result = mysql_query($query, $conn);
?>
<!-- 게시물 리스트를 보이기 위한 테이블 -->
<table width=600 border=0 cellpadding=2 cellspacing=1 bgcolor=#777777>
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
<td width=80 align=center>
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
<a href=read.php?id=<?=$row[id]?>&no=<?=$no?>><?=$row[id]?></a>
</td>
<!-- 번호 끝 -->
<!-- 제목 -->
<td height=20 bgcolor=white>&nbsp;
<? //depth 값을 통해서 들여쓰기를 한다. 투명이미지의 가로사이즈를 늘이는 방법
if ($row[depth] > 0) echo "<img src=img/dot.gif height=1 width=" . $row[depth]*7 . ">└";
?><a href=read.php?id=<?=$row[id]?>&no=<?=$no?>><?=remove_html($row[title]);?></a>
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