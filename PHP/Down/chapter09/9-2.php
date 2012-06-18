<?
	$count=file("count.txt");// 파일에서 총 방문자 수를 읽어옴 
	$count=trim($count[0]); // 가져온 값에서 빈 공간을 없앰 
	
	if(!isset($_COOKIE['visit'])) {// 쿠키가 설정되지 않았으면
		$count++; 
		$fp=fopen("count.txt","w");// 파일을 쓰기모드로 열고
		fwrite($fp,$count);// 파일에다 $count 값을 저장 
		fclose($fp);// 파일을 닫음 
		setcookie("visit");// 쿠키를 생성 
	}
	echo $count;// 총 방문자 수를 출력 
?>