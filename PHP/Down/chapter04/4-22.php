<?
	$name = 'zend.png';
	$fp = fopen($name, 'rb');

	header("Content-Type: image/png");
	header("Content-Length: " . filesize($name));

	fpassthru($fp);
	exit;
?>