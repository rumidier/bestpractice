<?
  $array = file('http://www.yahoo.com/');

  foreach ($array as $line_num => $line) {
    echo htmlspecialchars($line) ." <br>\n";
  }
?>
