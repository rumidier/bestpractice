<?
	$filename = "/var/www/temp/readfile.txt";

	//��� ������ �����Ѵ�.
	header("Pragma: public");
	header("Expires: 0");
	header("Cache-Control: must-revalidate, post-check=0, pre-check=0");
	header('Content-Description: File Transfer');

	//������ ������ ����
	header('Content-Type: application/octet-stream');

	//������ ũ��
	header('Content-Length: ' . filesize($filename));

	//���� �̸�
	header('Content-Disposition: attachment; filename=' 
	. basename($filename));
	//������ ���
	@readfile($filename);
?>