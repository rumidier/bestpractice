<?
//������ ���̽� �����ϱ�
include "db_info.php";

# LIST ����
# 1. �� �������� ������ �Խù��� ��
$page_size=10;

# 2. ������ �����⿡ ǥ�õ� �������� ��
$page_list_size = 10;

if (!$no || $no < 0) $no=0;

// �����ͺ��̽����� �������� ù��° ��($no)���� 
// $page_size ��ŭ�� ���� �����´�.
$query = "SELECT * FROM board ORDER BY id DESC LIMIT $no,$page_size";
$result = mysql_query($query, $conn);

// �� �Խù� �� �� ���Ѵ�.
$result_count=mysql_query("SELECT count(*) FROM board",$conn);
$result_row=mysql_fetch_row($result_count);
$total_row = $result_row[0];
//����� ù��° ���� count(*) �� �����.

# �� ������ ���
if ($total_row <= 0) $total_row = 0;
$total_page = ceil($total_row / $page_size);

# ���� ������ ���
$current_page = ceil(($no+1)/$page_size);
?>
<html>
<head>
<title>�� ���� �Խ���</title>
<style>
<!--
td {font-size : 9pt;}
A:link {font : 9pt;color : black;text-decoration : none; fontfamily
: ����;font-size : 9pt;}
A:visited {text-decoration : none; color : black; font-size : 9pt;}
A:hover {text-decoration : underline; color : black; font-size : 9pt;}
-->
</style>
</head>
<body topmargin=0 leftmargin=0 text=#464646>
<center>
<BR>
<!-- �Խ��� Ÿ��Ʋ -->
<font size=2>��~ ���׸� ã���ô�~ ���׸�~~</a>
<BR>
<BR>
<!-- �Խù� ����Ʈ�� ���̱� ���� ���̺� -->
<table width=580 border=0 cellpadding=2 cellspacing=1
bgcolor=#777777>
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
	<td width=60 align=center>
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
		<a href="read.php?id=<?=$row[id]?>&no=<?=$no?>">
		<?=$row[id]?></a>
	</td>
	<!-- ��ȣ �� -->
	<!-- ���� -->
	<td height=20 bgcolor=white>&nbsp;
		<a href="read.php?id=<?=$row[id]?>&no=<?=$no?>">
		<?=strip_tags($row[title], '<b><i>');?></a>
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
		<font color=black><?=$row[wdate]?></font>
	</td>
	<!-- ��¥ �� -->
	<!-- ��ȸ�� -->
	<td align=center height=20 bgcolor=white>
		<font color=black><?=$row[see]?></font>
	</td>
	<!-- ��ȸ�� �� -->
</tr>
<!-- �� �� -->
<?
} // end While
//�����ͺ��̽����� ������ ���´�.
mysql_close($conn);
?>
</table>
<!-- �Խù� ����Ʈ�� ���̱� ���� ���̺� ��-->
<!-- �������� ǥ���ϱ� ���� ���̺� -->
<table border=0>
<tr>
	<td width=600 height=20 align=center rowspan=4>
	<font color=gray>
	&nbsp;
<?
$start_page = floor(($current_page - 1) / $page_list_size) 
				* $page_list_size + 1;

# ������ ����Ʈ�� ������ �������� �� ��° ���������� ���ϴ� �κ��̴�.
$end_page = $start_page + $page_list_size - 1;

if ($total_page < $end_page) $end_page = $total_page;
if ($start_page >= $page_list_size) {
	# ���� ������ ����Ʈ���� ù ��° ���������� �� ������ �����ϸ� �ȴ�.
	# $page_size �� �����ִ� ������ �۹�ȣ�� ǥ���ϱ� ���ؼ��̴�.

	$prev_list = ($start_page - 2)*$page_size;
	echo "<a href=\"$PHP_SELF?no=$prev_list\">��</a>\n";
}

# ������ ����Ʈ�� ���
for ($i=$start_page;$i <= $end_page;$i++) {
	$page= ($i-1) * $page_size;// ���������� no ������ ��ȯ.
	if ($no!=$page){ //���� �������� �ƴ� ��츸 ��ũ�� ǥ��
		echo "<a href=\"$PHP_SELF?no=$page\">";
	}
	
	echo " $i "; //�������� ǥ��
	
	if ($no!=$page){
		echo "</a>";
	}
}

# ���� ������ ����Ʈ�� �ʿ��Ҷ��� �� �������� ������ ����Ʈ���� Ŭ ���̴�.
# ����Ʈ�� �� �Ѹ��� �� �ѷ��� �������� �������� ���� ��ư�� �ʿ��� ���̴�.
if($total_page > $end_page)
{
	$next_list = $end_page * $page_size;
	echo "<a href=$PHP_SELF?no=$next_list>��</a><p>";
}
?>
	</font>
	</td>
</tr>
</table>
<a href=write.php>�۾���</a>
</center>
</body>
</html>