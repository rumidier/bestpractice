<?
	/* Human 클래스를 여기에 삽입 */
	include "p247-human-php4.php";

	//5살짜리 철수를 생성합니다.
	$charles = new Human('철수', 5);

	//철수는 몇 살?
	$charles->Talk($charles->Age);

	//철수야! 밥 먹자~
	$charles->Eat("dinner");

	//밥을 먹고 난 후 철수의 키와 몸무게가 늘었다.
	$charles->Height = 110; // 110 cm
	$charles->Weight = 22; // 22 Kg
?>