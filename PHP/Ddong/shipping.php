<?php
$ajax = $_SERVER['HTTP_X_REQUESTED_WITH'];


if (!$ajax):
// include header only if the page is NOT being returned via ajax.
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" 
        "http://www.w3.org/TR/html4/strict.dtd">

<html lang="en">
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
	<title>Shipping</title>
  <link rel="stylesheet" href="../styles/bookstore.css" type="text/css" media="screen" />
  <link rel="stylesheet" href="../styles/tables.css" type="text/css" media="screen" />
  <link rel="stylesheet" href="../styles/forms.css" type="text/css" media="screen" />
  <link rel="stylesheet" href="../styles/rotators.css" type="text/css" media="screen" />
  <script src="../scripts/jquery.js" type="text/javascript"></script>
  <script src="../scripts/cookbook.js" type="text/javascript"></script>
  <script src="../scripts/tables.js" type="text/javascript"></script>
  <script src="../scripts/rotators.js" type="text/javascript"></script>

</head>
<body>

  <div id="wrapper">
  	<div id="branding">
			<h1><a href="../index.html">Learning jQuery</a></h1>
  	</div>
  	<div id="container">
  		<div id="content">
  			<h2>Shipping</h2>  
<?php
endif;

if (isset($_POST['op']) && $_POST['op'] == 'Save') {
  // Code here would save the new shipping address back to the database, or to the session variables.
  $name = $_POST['first-name'] .' '. $_POST['last-name'];
  print('<p id="shipping-name"><a href="shipping.php">'. $name .'</a></p>');
} else {
  $shipping = array();
  $shipping['first-name'] = 'Steve';
  $shipping['last-name'] = 'Schoon';
  $shipping['address'] = '52 Rodeo Drive';
  $shipping['city'] = 'Beverly Hills';
  $shipping['state'] = 'CA';
  $shipping['zip'] = '90210';
  $shipping['message'] = 'Enjoy these great books! You\'ll love the cliff-hangers!';
?>
<form action="shipping.php" method="post" accept-charset="utf-8">
  <ol>
    <li><label for="first-name">First name:</label><input type="text" name="first-name" value="<?php print $shipping['first-name']; ?>" id="first-name" /></li>
    <li><label for="last-name">Last name:</label><input type="text" name="last-name" value="<?php print $shipping['last-name']; ?>" id="last-name" /></li>
    <li><label for="address">Address:</label><input type="text" name="address" value="<?php print $shipping['address']; ?>" id="address" /></li>
    <li><label for="city">City:</label><input type="text" name="city" value="<?php print $shipping['city']; ?>" id="city" /></li>
    <li><label for="state">State:</label><input type="text" name="state" value="<?php print $shipping['state']; ?>" id="state" /></li>
    <li><label for="zip">ZIP:</label><input type="text" name="zip" value="<?php print $shipping['zip']; ?>" id="zip" /></li>
    <li><label for="message">Gift message:</label><textarea name="message" id="message"><?php print $shipping['message']; ?></textarea></li>
    <li>
      <input type="submit" name="op" id="op" value="Save" />  
    </li>
  </ol>
</form>
  <?php
}
if (!$ajax):
// include footer only if the page is NOT being returned via ajax.
?>
  
  	  </div> <!-- end content -->
      <div id="primary-nav">
    		<ul>
    			<li><a href="../books/index.html">Books</a></li>
    			<li><a href="../news/index.html">News</a></li>
    			<li><a href="../contact/index.html">Contact</a></li>
    		</ul>    
      </div>
  	  
  	</div> <!-- end container -->
  	<div id="secondary-nav">
  		<h3><a href="./index.html">Your Cart</a></h3>
        			<ul>
        				<li>Lorem ipsum dolor</li>
        				<li>Lorem ipsum dolor</li>

        				<li>Lorem ipsum dolor</li>
        				<li>Lorem ipsum dolor</li>
        				<li>Lorem ipsum dolor</li>
        				<li>Lorem ipsum dolor</li>
        				<li>Lorem ipsum dolor</li>
        			</ul>
      
  	</div> 

  	<div id="sidebar">

  			<h2>Sidebar</h2>
        <div>
  			  <form id="search" action="search/index.php" method="post" accept-charset="utf-8">
            <label for="search-text">search the site</label><input type="text" name="search-text" id="search-text" />
    			</form>
        </div>
  			<p>Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Nam adipiscing, risus quis fringilla venenatis, diam nisi adipiscing magna, sit amet rutrum risus nunc sit amet odio. Praesent ullamcorper. Donec sit amet ipsum. Nam consequat rhoncus lacus. Pellentesque libero erat, elementum a, mattis in, molestie id, magna. Integer sed libero vitae lacus elementum egestas. Nullam massa magna, gravida sed, porta vel, ultricies at, purus. Maecenas turpis. Vivamus ante risus, eleifend sed, scelerisque at, lacinia vitae, nunc. Vestibulum ut arcu. Cras ut magna. Pellentesque eleifend commodo est. Sed vitae odio eget ipsum tristique hendrerit. Cras elementum turpis ut sapien. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Ut sed erat at velit bibendum varius. Sed venenatis sagittis lectus. Cras ligula felis, ultrices et, imperdiet et, laoreet sed, odio. Morbi nunc tellus, hendrerit in, aliquet eget, rutrum a, magna. Nunc nunc.</p>

  	</div> <!-- end sidebar -->
  	<div id="footer">
  		This is the footer.
  	</div>
  </div> <!-- end wrapper -->

</body>
</html>
<?php endif;