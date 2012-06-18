<?
	$txt = '
	username="brown",
	realm="ezphp.net",
	qop="auth",
	algorithm="MD5",
	uri="/login/digest.php",
	nonce="472d4699aba99",
	nc=00000001,
	cnonce="d9736db68233f72060e43e416d29ebe9",
	opaque="2376e4fe270a0eaee637100877a779f3",
	response="3d65f9e6943c17ba9ff28108c1351bba"
	';

	//배열 생성문 형식으로 변경한다.
	$txt = str_replace("=", "=>", $txt);

	//$data 배열을 생성한다.
	$txt = "\$data = array($txt);";
	eval($txt);

	echo "<PRE>";
	print_r($data);
	echo "</PRE>";
?>