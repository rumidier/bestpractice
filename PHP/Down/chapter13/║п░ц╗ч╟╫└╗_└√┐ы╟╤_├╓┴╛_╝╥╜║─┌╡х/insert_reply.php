<?

include_once "library.php";

$_POST[name] = trim(strip_tags($_POST[name]));
$_POST[email] = trim(strip_tags($_POST[email]));
$_POST[parent_thread]=(int)$_POST[parent_thread];

//�Է°� ����
if (!$_POST[name]) ErrorMessage('�̸��� �Է��ϼ���.');
if (!$_POST[pass]) ErrorMessage('��ȣ�� �Է��ϼ���.');
if (!$_POST[title]) ErrorMessage('������ �Է��ϼ���.');
if (!$_POST[content]) ErrorMessage('������ �Է��ϼ���.');

$filename="";
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
	}
	else {
		ErrorMessage('���ε忡 �����Ͽ����ϴ�.');
	}
}

//������ ���̽� �����ϱ�
include_once "db_info.php";

$prev_parent_thread = floor($_POST[parent_thread]/1000)*1000 +1000; 
$update_query = "update $board set thread=thread+1 where thread < $prev_parent_thread and thread > $_POST[parent_thread]";
$update_query .= " order by thread desc";
$update_thread = mysql_query($update_query, $conn) or ErrorMessage('�亯 ���� �����ϴµ� �����Ͽ����ϴ�.');;

$query = "insert into $board (thread,depth,name,pass,email,title,view,wdate,ip,content)";
$query .= " values ('" . ($_POST[parent_thread]+1) . "'";
$query .= ",'" . ($_POST[parent_depth]+1) ."','$_POST[name]','$_POST[pass]','$_POST[email]','$_POST[title]',0";
$query .= ", UNIX_TIMESTAMP(),'$REMOTE_ADDR','$_POST[content]')";
$result=mysql_query($query, $conn) or ErrorMessage('�亯 ���� �����ϴµ� �����Ͽ����ϴ�.');;

//�����ͺ��̽����� ���� ����
mysql_close($conn);

// �� �� ������ ��� ����Ʈ��..
echo ("<meta http-equiv='Refresh' content='1; URL=list.php'>");

?>
<center>
<font size=2>���������� ����Ǿ����ϴ�.</font> 