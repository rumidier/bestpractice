<?
	/* Human Ŭ������ ���⿡ ���� */
	include "p247-human-php4.php";

	//5��¥�� ö���� �����մϴ�.
	$charles = new Human('ö��', 5);

	//ö���� �� ��?
	$charles->Talk($charles->Age);

	//ö����! �� ����~
	$charles->Eat("dinner");

	//���� �԰� �� �� ö���� Ű�� �����԰� �þ���.
	$charles->Height = 110; // 110 cm
	$charles->Weight = 22; // 22 Kg
?>