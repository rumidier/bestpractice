<?
//������ ���̽� �����ϱ�
include "db_info.php";

$prev_parent_thread = ceil($_POST[parent_thread]/1000)*1000 - 1000;

//�����ۺ��ٴ� �۰� �������ٴ� ū �۵��� thread ���� ��� 1�� �����.
$query = "UPDATE $board SET thread=thread-1 WHERE 
thread > $prev_parent_thread and thread < $_POST[parent_thread]";
$update_thread = mysql_query($query, $conn);

//�����ۺ��ٴ� 1���� ������ ����� ����Ѵ�.
//�������� �ٷ� �ؿ� ��ϵǰ� �ȴ�.
//depth�� �������� depth + 1 �̴�. �������� 3(�̱۵� ����̱�)�̸� ����� 4���ȴ�.
$query = "INSERT INTO $board (thread,depth,name,pass,email";
$query .= ",title,view,wdate,ip,content)";
$query .= " VALUES ('" . ($_POST[parent_thread]-1) . "'";
$query .= ",'" . ($parent_depth+1) ."','$name','$pass','$email'";
$query .= ",'$title',0, UNIX_TIMESTAMP(),'$REMOTE_ADDR'";
$query .= ",'$content')";
$result=mysql_query($query, $conn);

//�����ͺ��̽����� ���� ����
mysql_close($conn);

// �� �� ������ ��� ����Ʈ��..
echo ("<meta http-equiv='Refresh' content='1; URL=list.php'>");
?>
<center>
<font size=2>���������� ����Ǿ����ϴ�.</font>