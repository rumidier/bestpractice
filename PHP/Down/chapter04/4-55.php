<?
	$subject = "å ���� ������.";
	$message = "��� ��ħ��� ���⿡...";

	$to = "moratorium@gmail.com";
	$from = "your@mail.com";

	$header = "From: {$from}\r\nReply-To: {$from}\r\n";

	mail($to, $title, $message, $header);
?>