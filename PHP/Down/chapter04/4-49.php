<?
	$text = "����Ծ�. ��ù� ���� ���� �Ծ �谡 �����̿���.";

	$bad_words = array("�Ծ�", "����", "����", "��ù�");
	$good_words = array("��", "����", "�ſ�", "ȸ");

	$text = str_replace($bad_words, $good_words, $text);
	echo $text;
?>