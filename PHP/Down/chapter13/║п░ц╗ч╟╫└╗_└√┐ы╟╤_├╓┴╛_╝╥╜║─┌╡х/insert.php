<?

include_once "library.php";

$_POST[name] = trim(strip_tags($_POST[name]));
$_POST[email] = trim(strip_tags($_POST[email]));

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

//���� �ۿ��� ���� ū ���� �����´�.
$max_thread_result = mysql_query("select min(thread) from $board",$conn);
$max_thread_fetch = mysql_fetch_row($max_thread_result);
$max_thread = floor($max_thread_fetch[0]/1000)*1000-1000;

$query = "insert into $board (thread, depth, name, pass, email, title, view, wdate, ip, content, filename) values ($max_thread,0,'$_POST[name]','$_POST[pass]','$_POST[email]','$_POST[title]',0,UNIX_TIMESTAMP(),'$REMOTE_ADDR', '$_POST[content]', '$filename')";
$result=mysql_query($query, $conn) or ErrorMessage('���� �����ϴµ� �����Ͽ����ϴ�.');
//�����ͺ��̽����� ���� ����
mysql_close($conn);

 // �� �� ������ ��� ����Ʈ��..
echo ("<meta http-equiv='Refresh' content='1; URL=list.php'>");

?>
<center>
<font size=2>���������� ����Ǿ����ϴ�.</font>
