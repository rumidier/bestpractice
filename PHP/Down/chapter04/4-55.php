<?
	$subject = "책 정말 좋군요.";
	$message = "라면 받침대로 쓰기에...";

	$to = "moratorium@gmail.com";
	$from = "your@mail.com";

	$header = "From: {$from}\r\nReply-To: {$from}\r\n";

	mail($to, $title, $message, $header);
?>