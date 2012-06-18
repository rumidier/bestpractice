<?
	$arr = array('name'=>'brown', 'age'=>29, 'sex'=>'male');

	echo "<pre>";
	//배열의 한 원소 제거
	unset($arr['sex']);
	print_r($arr);

	//배열 전체 제거
	unset($arr);
	print_r($arr);
	echo "</pre>";
?>