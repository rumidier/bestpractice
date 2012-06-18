<?
	session_start();

	echo $_SESSION['message'];
	echo "<P>";
	echo "PHPSESSID=" . session_id();
?>