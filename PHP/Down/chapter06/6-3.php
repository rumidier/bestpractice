<?
	$result = setcookie('php' , 'Cool~' , time()+1000);
	if ($result)
		echo '쿠키 생성 완료';
	else
		echo '쿠키 생성 실패';
?>