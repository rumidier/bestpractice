<?
//������ ���̽� �����ϱ�
include "db_info.php";

//Thread ���� ����Ѵ�.
$query = "SELECT max(thread) FROM $board";
$max_thread_result = mysql_query($query, $conn);
$max_thread_fetch = mysql_fetch_row($max_thread_result);

$max_thread = ceil($max_thread_fetch[0]/1000)*1000+1000;

$query = "INSERT INTO $board (thread, depth, name, pass, email,
title, view, wdate, ip, content) 
VALUES ($max_thread, 0, '$_POST[name]', '$_POST[pass]', 
'$_POST[email]', '$_POST[title]', 0,
UNIX_TIMESTAMP(), '$REMOTE_ADDR', '$_POST[content]')";
$result=mysql_query($query, $conn);

//�����ͺ��̽����� ���� ����
mysql_close($conn);

// �� �� ������ ��� ����Ʈ��..
echo ("<meta http-equiv='Refresh' content='1; URL=list.php'>");
?>
<center>
<font size=2>���������� ����Ǿ����ϴ�.</font>
