<?
//�⺻�� ����
$realm = "ezphp.net";
$user = "brown";
$pass = "brown1234";

if (empty($_SERVER['PHP_AUTH_DIGEST']) || $_COOKIE['login'] != "1") {
	header('HTTP/1.1. 401 Unauthorized');
	header('WWW-Authenticate: Digest realm="' . $realm . '",qop="auth",nonce="'. uniqid() .'",opaque="'. md5($realm).'"');

	setcookie("login","1");

	//��� ��ư�� ������ ���
	echo "<meta http-equiv=\"refresh\" content=\"0\">";
	exit;
}
else {
	//�α׾ƿ�
	if($_GET['logout'] == "1") {
		setcookie("login", "", 0);
		header("location: {$_SERVER['PHP_SELF']}");
		exit;
	}
}

//����� ���� ó��
if (!check_response( $data = http_digest_parse() ))
{
	setcookie("login","",0);
	echo "�� �������� ����� ������ �ʿ��մϴ�.<BR>";
	echo "<a href='{$PHP_SELF}'>�α���</a>�Ͻʽÿ�.";
	exit;
}

//���� �м� �Լ�
function http_digest_parse()
{
	$txt = str_replace("=","=>",$_SERVER['PHP_AUTH_DIGEST']);
	$txt = "\$data = array($txt);";
	eval($txt);

	$data[nc] = str_pad($data[nc], 8, "0", STR_PAD_LEFT);
	$data = str_replace("=>","=",$data);

	return $data;
}

//MD5 �� ���� �Լ�
function check_response($data)
{
	global $realm, $user, $pass;

	$A1 = md5($user . ':' . $realm . ':' . $pass);
	$A2 = md5($_SERVER['REQUEST_METHOD'].':'.$data['uri']);
	
	$valid_response = "{$A1}:{$data[nonce]}:{$data[nc]}";
	$valid_response .= ":{$data['cnonce']}:{$data['qop']}:{$A2}";
	$valid_response = md5($valid_response);

	return $data['response']==$valid_response?true:false;
}
?>

�ȳ��ϼ���. <?=$data['username']?>��<BR>
<a href='<?=$_SEVER['PHP_SELF']?>?logout=1'>�α׾ƿ�</a>