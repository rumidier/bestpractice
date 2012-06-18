<?
  include "human.php";
  $charles = new Human('철수', 5);
  $charles->Talk($charles->Age);
  $charles->Eat("dinner"); 

  $charles->Height = 100;
  $charles->Weight = 22;
?>
