<?
include_once "library.php";

$_POST[name] = trim(strip_tags($_POST[name]));

//�Է°� ����
if (!$_POST[name]) ErrorMessage('�̸��� �Է��ϼ���.');
if (!$_POST[pass]) ErrorMessage('��й�ȣ�� �Է��ϼ���.');
if (!$_POST[comment]) ErrorMessage('������ �Է��ϼ���.');

//������ ���̽� �����ϱ�
include_once "db_info.php";

// ���� ��й�ȣ�� �����´�.
$query = "SELECT pass FROM comment WHERE id='$_POST[id]'";
$result=mysql_query($query, $conn) 
or ErrorMessage('������ �����ϴµ� �����Ͽ����ϴ�.');
$row=mysql_fetch_array($result);

//�Էµ� ���� ���Ѵ�.
if ($_POST[pass]==$row[pass]) { //��й�ȣ�� ��ġ�ϴ� ���
	$query = "UPDATE comment SET name='$_POST[name]',"; 
	$query .= "comment='$_POST[comment]' WHERE id='$_POST[id]'";
	$result=mysql_query($query, $conn) 
	or ErrorMessage('������ �����ϴµ� �����Ͽ����ϴ�.');
}
else { // ��й�ȣ�� ��ġ���� �ʴ� ���
	ErrorMessage('��й�ȣ�� Ʋ���ϴ�.');
}

//�����ͺ��̽����� ���� ����
mysql_close($conn);

//�����ϱ��� ��� ������ �۷�..
echo ("<meta http-equiv='Refresh' content='0; 
URL=read.php?id=$_POST[bid]'>");
?>
