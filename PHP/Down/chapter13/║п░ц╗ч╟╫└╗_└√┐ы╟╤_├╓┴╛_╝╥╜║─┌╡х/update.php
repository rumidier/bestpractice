<?

include_once "library.php";

$id = (int)$_GET[id];

$_POST[name] = trim(strip_tags($_POST[name]));
$_POST[email] = trim(strip_tags($_POST[email]));

//�Է°� ����
if (!$_POST[name]) ErrorMessage('�̸��� �Է��ϼ���.');
if (!$_POST[pass]) ErrorMessage('��ȣ�� �Է��ϼ���.');
if (!$_POST[title]) ErrorMessage('������ �Է��ϼ���.');
if (!$_POST[content]) ErrorMessage('������ �Է��ϼ���.');

$filename="";
$add_query="";
if (!empty($_FILES['upfile']['name']))
{
	//������ Ȯ����
	$ban_ext = array('php','php3','html','htm','cgi','pl');
	
	//Ȯ���ڸ� �̿��Ͽ� ���ε� ������ �������� üũ�Ѵ�.
	$fname = explode(".", $_FILES['upfile']['name']);
	//�迭�� ������ ����, �� Ȯ���ڸ� �ҹ��ڷ� �����´�.
	$ext = strtolower($fname[sizeof($fname)-1]);
	if (in_array($ext, $ban_ext)) {
		ErrorMessage("���ε尡 �Ұ����� Ȯ�����Դϴ�.");
	}

	if (move_uploaded_file($_FILES['upfile']['tmp_name'], './uploads_dir/' . $_FILES['upfile']['name']))
	{
		$filename = $_FILES['upfile']['name'];
		$add_query = ", filename = '$filename' ";
	}
	else {
		ErrorMessage('���ε忡 �����Ͽ����ϴ�.');
	}
}

//������ ���̽� �����ϱ�
include_once "db_info.php";

// ���� ��й�ȣ�� �����´�.
$result=mysql_query("select pass from $board where id='$id'", $conn) or ErrorMessage('���� �����ϴµ� �����Ͽ����ϴ�.');;
$row=mysql_fetch_array($result);

//�Էµ� ���� ���Ѵ�.
if ($_POST[pass]==$row[pass]) { //��й�ȣ�� ��ġ�ϴ� ���

	$query = "update $board set name='$_POST[name]',title='$_POST[title]',email='$_POST[email]',content='$_POST[content]'";
	$query .= $add_query; //���ο� ���ε� ������ �ִ� ���
	$query .= "where id='$id' ";
	$result=mysql_query($query, $conn) or ErrorMessage('���� �����ϴµ� �����Ͽ����ϴ�.');;
} 
else { // ��й�ȣ�� ��ġ���� �ʴ� ���
	ErrorMessage('��й�ȣ�� Ʋ���ϴ�.');
}

//�����ͺ��̽����� ���� ����
mysql_close($conn);

//�����ϱ��� ��� ������ �۷�..
echo ("<meta http-equiv='Refresh' content='0; URL=read.php?id=$id'>");

?>