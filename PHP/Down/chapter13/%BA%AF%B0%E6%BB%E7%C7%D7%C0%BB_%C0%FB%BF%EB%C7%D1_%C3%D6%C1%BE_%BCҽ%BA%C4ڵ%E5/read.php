<?
//������ ���̽� �����ϱ�
include "db_info.php";
include_once "library.php";

$id = (int)$_GET[id];
$no = (int)$_GET[no];

// ��ȸ�� ������Ʈ
$result=mysql_query("update $board set view=view+1 where id=$id", $conn);

// �� ���� ��������
$result=mysql_query("select * from $board where id=$id", $conn);
$row=mysql_fetch_array($result);

?>
<html>
<head>
<title>������ �Խ���</title>
<style>
<!--
td { font-size : 9pt; }
A:link { font : 9pt; color : black; text-decoration : none; font-family : ����; font-size : 9pt; }
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
<td width=50 height=20 align=center bgcolor=#EEEEEE>�۾���</td><td width=240 bgcolor=white><?=$row[name]?></td>
<td width=50 height=20 align=center bgcolor=#EEEEEE>�̸���</td><td width=240 bgcolor=white><?=$row[email]?></td>
</tr>
<tr>
<td width=50 height=20 align=center bgcolor=#EEEEEE>��&nbsp;&nbsp;&nbsp;¥</td><td width=240 bgcolor=white><?=date("Y-m-d",$row[wdate])?></td>
<td width=50 height=20 align=center bgcolor=#EEEEEE>��ȸ��</td><td width=240 bgcolor=white><?=$row[view]?></td>
</tr>
<tr>
<td bgcolor=white colspan=4 style="word-break:break-all;">
<BR>
<font color=black>
<?
	if ($row[filename]) {
		echo "÷�ε� ���� : <a href='uploads_dir/$row[filename]'>$row[filename]</a><BR><BR>";
	}
?>
<?=nl2br(str_replace(" ", "&nbsp;", remove_html($row[content])));?>
</font>
        <BR><BR>
        <? include "comment.php"; ?>

</td> 
</tr>
<!-- ��Ÿ ��ư �� -->
<tr>
<td colspan=4 bgcolor=#999999>
<table width=100%>
<tr>
<td width=280 align=left height=20>
<a href=list.php?no=<?=$no?>><font color=white>[��Ϻ���]</font></a>
<a href=reply.php?id=<?=$id?>><font color=white>[��۴ޱ�]</font></a>
<a href=write.php><font color=white>[�۾���]</font></a>
<a href=edit.php?id=<?=$id?>><font color=white>[����]</font></a>
<a href=predel.php?id=<?=$id?>><font color=white>[����]</font></a>
</td>
</tr>
</table>
</td>
</tr>
</table>

<table  width=580 bgcolor=white style="border-bottom-width:1; border-bottom-style:solid;border-bottom-color:cccccc;">
<?
// ���� �ۺ��� thread ���� ū �� �� ���� ���� ���� id�� �����´�.
$query=mysql_query("select id, name, title from $board where thread < $row[thread] and depth=0 order by thread desc limit 1", $conn);
$up_id=mysql_fetch_array($query);

if ($up_id[id]) // ���� ���� ���� ���
{
echo "<tr><td width=500 align=left height=25>";
echo "<a href=read.php?id=$up_id[id]>�� " . remove_html($up_id[title]) . "</a></td><td align=right>$up_id[name]</td></tr>";
}

// ���� �ۺ��� thread ���� ���� �� �� ���� ū ���� id�� �����´�.
$query=mysql_query("select id, name, title from $board where thread > $row[thread] and depth=0 limit 1", $conn);
$down_id=mysql_fetch_array($query);

if ($down_id[id])
{
echo "<tr><td width=500 align=left height=25>";
echo "<a href=read.php?id=$down_id[id]>�� " . remove_html($down_id[title]) . "</a></td><td align=right>$down_id[name]</td></tr>";
}
?>
</table>
<BR>
<?
//����Ʈ ����� ���� thread�� ����Ѵ�.
//��µ� ����Ʈ�� �� ��ü ����Ʈ�� �ƴ϶�
//1000�� ����� ���۰� �̸� ������ �亯�۵��� ����Ʈ�̴�.
//�亯���� ���� ��� �����۸� ����Ʈ�� ������
//�亯���� ������ �亯�� ��ΰ� �� �����Եȴ�.
//���� ���� �亯���̾ ���ۺ��� ��ü �亯�۱��� ���´�.
//�׷����� 1000~2000 �� ���� ���ۻ��̿� �۵��� ��� �ѷ��ָ� �ȴ�.
$thread_start = (floor($row[thread]/1000)+1)*1000;
$thread_end = floor($row[thread]/1000)*1000;
$query = "select * from $board where thread >= $thread_end and thread < $thread_start order by thread";
$result = mysql_query($query, $conn);
?>
<!-- �Խù� ����Ʈ�� ���̱� ���� ���̺� -->
<table width=600 border=0 cellpadding=2 cellspacing=1 bgcolor=#777777>
<!-- ����Ʈ Ÿ��Ʋ �κ� -->
<tr height=20 bgcolor=#999999>
<td width=30 align=center>
<font color=white>��ȣ</font>
</td>
<td width=370 align=center>
<font color=white>�� ��</font>
</td>
<td width=50 align=center>
<font color=white>�۾���</font>
</td> 
<td width=80 align=center>
<font color=white>�� ¥</font>
</td>
<td width=40 align=center>
<font color=white>��ȸ��</font>
</td> 
</tr>
<!-- ����Ʈ Ÿ��Ʋ �� -->
<!-- ����Ʈ �κ� ���� -->
<?
while($row=mysql_fetch_array($result))
{

?>
<!-- �� ���� -->
<tr>
<!-- ��ȣ -->
<td height=20 bgcolor=white align=center>
<a href=read.php?id=<?=$row[id]?>&no=<?=$no?>><?=$row[id]?></a>
</td>
<!-- ��ȣ �� -->
<!-- ���� -->
<td height=20 bgcolor=white>&nbsp;
<? //depth ���� ���ؼ� �鿩���⸦ �Ѵ�. �����̹����� ���λ���� ���̴� ���
if ($row[depth] > 0) echo "<img src=img/dot.gif height=1 width=" . $row[depth]*7 . ">��";
?><a href=read.php?id=<?=$row[id]?>&no=<?=$no?>><?=remove_html($row[title]);?></a>
</td>
<!-- ���� �� -->
<!-- �̸� -->
<td align=center height=20 bgcolor=white>
<font color=black>
<a href="mailto:<?=$row[email]?>"><?=$row[name]?></a>
</font>
</td>
<!-- �̸� �� -->
<!-- ��¥ -->
<td align=center height=20 bgcolor=white>
<font color=black><?=date("Y-m-d",$row[wdate])?></font>
</td>
<!-- ��¥ �� -->
<!-- ��ȸ�� -->
<td align=center height=20 bgcolor=white>
<font color=black><?=$row[view]?></font>
</td>
<!-- ��ȸ�� �� -->
</tr>
<!-- �� �� -->
<?
} // end While
mysql_close($conn);
?>

</center>
</body>
</html>