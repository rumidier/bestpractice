<?
	//������ ���̽� �����ϱ�
	include "db_info.php";

	// ���� ��й�ȣ�� �����´�.
	$query = "SELECT pass FROM board WHERE id=$id";
	$result=mysql_query($query, $conn);
	$row=mysql_fetch_array($result);

	//�Էµ� ���� ���Ѵ�.
	if ($pass==$row[pass]) { //��й�ȣ�� ��ġ�ϴ� ���
		$query = "UPDATE board SET name='$name', email='$email',
		title='$title', content='$content' WHERE id=$id";
		$result=mysql_query($query, $conn);
	}
	else { // ��й�ȣ�� ��ġ���� �ʴ� ���
		echo ("
		<script>
		alert('��й�ȣ�� Ʋ���ϴ�.');
		history.go(-1);
		</script>
		");
		exit;
	}

	//�����ͺ��̽����� ���� ����
	mysql_close($conn);

	//�����ϱ��� ��� ������ �۷�..
	echo ("<meta http-equiv='Refresh' content='1; 
	URL=read.php?id=$id'>");
?>
<center>
<font size=2>���������� �����Ǿ����ϴ�.</font>