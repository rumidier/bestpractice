<?php
if ($_POST) {
	$firstname = $_POST["firstname"];
	$lastname = $_POST["lastname"];
?>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN"
   "http://www.w3.org/TR/html4/strict.dtd">

<html> 
<head> 
<meta name="robots" content="noindex,  nofollow">
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Head First HTML with CSS &amp; XHTML Chapter 14 Contest</title> 
<style type="text/css">
img {
	float: left;
	margin-right: 20px;
}
div {
	padding-top: 40px;
}
</style>
</head>
<body>

<p>
<img src="http://headfirstlabs.com/Images/hfguy.jpg" alt="Head First Guy" />
</p>

<div>
<p>
Thanks, <strong><?php print($firstname); print(" "); print($lastname); ?></strong>,
for entering the Head First HTML with CSS &amp; XHTML Chapter 14 contest.
</p>
<p>
If you win something, you'll be the first to know.
</p>
</div>


</body> 
</html>


<?php

}

?>
