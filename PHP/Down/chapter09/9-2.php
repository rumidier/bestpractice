<?
	$count=file("count.txt");// ���Ͽ��� �� �湮�� ���� �о�� 
	$count=trim($count[0]); // ������ ������ �� ������ ���� 
	
	if(!isset($_COOKIE['visit'])) {// ��Ű�� �������� �ʾ�����
		$count++; 
		$fp=fopen("count.txt","w");// ������ ������� ����
		fwrite($fp,$count);// ���Ͽ��� $count ���� ���� 
		fclose($fp);// ������ ���� 
		setcookie("visit");// ��Ű�� ���� 
	}
	echo $count;// �� �湮�� ���� ��� 
?>