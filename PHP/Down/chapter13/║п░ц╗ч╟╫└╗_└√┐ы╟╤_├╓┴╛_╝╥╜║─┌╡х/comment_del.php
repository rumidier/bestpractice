<?

include_once "library.php";

//�Է°� ����
$id = (int)$_GET[id];
if (!$_POST[pass]) ErrorMessage('��ȣ�� �Է��ϼ���.');

//������ ���̽� �����ϱ�
include_once "db_info.php";

$result=mysql_query("SELECT pass FROM comment WHERE id='$id'", $conn) or ErrorMessage('���� �����ϴµ� �����Ͽ����ϴ�.');;
$row=mysql_fetch_array($result);

 if ($_POST[pass]==$row[pass] )
 {
	 $conndel = "DELETE FROM comment WHERE id='$id'";
	 $result=mysql_query($conndel, $conn) or ErrorMessage('���� �����ϴµ� �����Ͽ����ϴ�.');;

 } 
 else
{
	ErrorMessage('��й�ȣ�� Ʋ���ϴ�.');
}
?>

<meta http-equiv='Refresh' content='0; URL=read.php?id=<?=$_GET[bid]?>'>
