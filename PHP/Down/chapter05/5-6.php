<?
	$arr = array('name'=>'brown', 'age'=>29, 'sex'=>'male');

	echo "<pre>";
	//�迭�� �� ���� ����
	unset($arr['sex']);
	print_r($arr);

	//�迭 ��ü ����
	unset($arr);
	print_r($arr);
	echo "</pre>";
?>