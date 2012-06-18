<!DOCTYPE html PUBLIC "-//W3C//DTD XTHML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html>
  <head>
    <title></title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
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

<?
  include "db_info.php";

  $result = mysql_query("SELECT * FROM board WHERE id=$_GET[id]", $conn);
  $row    = mysql_fetch_array($result);
?>
   <table width=580 border=0 cellpadding=2 cellspacing=1 bgcolor=#777777>
     <tr>
       <td height=20 colspan=4 align=center bgcolor=#999999>
         <font color=white><b><?=$row[title]?></b></font>
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
       날&nbsp;&nbsp;&nbsp;짜
       </td>
       <td width=240 bgcolor=white><?=$row[wdate]?></td>
       <td width=50 height=20 align=center bgcolor=#EEEEEE>조회수</td>
       <td width=240 bgcolor=white><?=$row[view]?></td>
     </tr>
     <tr>
       <td bgcolor=white colspan=4>
         <font color=black>
	 <pre><?=$row[content]?></pre>
	 </font>
       </td>
     </tr>
     <tr>
       <td colspan=4 bgcolor=#999999>
         <table width=100%>
	   <tr>
	     <td width=200 align=left height=20>
	       <a href=list.php?no=<?=$_GET[no]?>><font color=while>[목록보기]</font></a>
	       <a href=list.php?id=<?=$_GET[id]?>><font color=while>[수정]</font></a>
	       <a href=list.php?id=<?=$_GET[id]?>><font color=while>[삭제]</font></a>
	     </td>
	     <td align=right>
<?
  $query   = mysql_query("SELECT id FROM board WHERE id > $_GET[id] LIMIT 1", $conn);
  $prev_id = mysql_fetch_array($query);

  if ($prev_id[id]) {
    echo "<a href=read.php?id=$prev_id[id]><font color=white>[이전]</font></a>";
  }
  else {
    echo "[이전]";
  }

  $query   = mysql_query("SELECT id FROM board WHERE id < $_GET[id] ORDER BY id DESC LIMIT 1", $conn);
  $next_id = mysql_fetch_array($query);

  if ($next_id[id]) {
    echo "<a href=read.php?id=$next_id[id]> <font color=white>[다음]</font></a>";
  }
  else {
    echo "[다음]";
  }
?>
             </td>
	   </tr>
	 </table>
	 </b></font>
       </td>
     </tr>
   </table>
  </center>
  </body>
</html>
<?
  $result=mysql_query("UPDATE testboard SET see=see+1 WHERE id=$_GET[id]", $conn);
  mysql_close($conn);
?>
