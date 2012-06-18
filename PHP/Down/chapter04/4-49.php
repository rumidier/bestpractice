<?
	$text = "브라운님아. 사시미 조낸 많이 먹어서 배가 만땅이예요.";

	$bad_words = array("님아", "만땅", "조낸", "사시미");
	$good_words = array("님", "가득", "매우", "회");

	$text = str_replace($bad_words, $good_words, $text);
	echo $text;
?>