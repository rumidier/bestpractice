<?

$board="threadboard";

$conn=@mysql_connect("localhost","���̵�","�н�����") or die('�����ͺ��̽��� ������ �� �����ϴ�');
@mysql_select_db("�����ͺ��̽���", $conn) or die('������ �����ͺ��̽��� ����� �� �����ϴ�.');
@mysql_query("set names euckr");

?>