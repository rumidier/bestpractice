<?
//��ũ��Ʈ �����Ҷ�����
set_time_limit(0);

//������ ���̽� �����ϱ�
include "db_info.php";

// �� ��Ͽ� ���� �⺻���� ����
$name = "����";
$pass = "1234";
$email = "happybrown@naver.com";

if (ob_get_level() == 0) ob_start();

for ($i=1;$i<=1000000;$i++)
{
	$title = "$i ��° �׽�Ʈ �Խù�";
	$content = "$i ��° �׽�Ʈ �Խù� ����";

	// ����� ���� thread ���� index ���� 1000��
	$max_thread = $i * 1000;

	$query = "INSERT INTO $board (id,thread,depth,name,pass,email,
	title,view,wdate,ip,content) ";
	$query .= "VALUES ('',$max_thread,0,'$name','$pass','$email',
	'$title',0, UNIX_TIMESTAMP(), '$REMOTE_ADDR','$content')";
	$result=mysql_query($query, $conn);

	if ($result) {
		$success++;
		print("$i INSERT ����<BR>\r\n");
	}
	else {
		$failure++;
		print("$i INSERT <B>����</B><BR>\r\n");
	}
	
	// �� ���α׷��� �ý��� �ڿ��� ���� �Ҵ�޴°��� ��������
	// 10000���� 1�ʾ� �����ݴϴ�.
	if(($i%10000) == 0) sleep(1);
}
//�����ͺ��̽����� ���� ����
mysql_close($conn);
?>