<?
  if ($_GET['mode'] != "delete") {
?>

<html>
  <form method="POST" action="<?=$_SERVER['PHP_SELF']?>?id=<?=$_GET['id']?>&mode=delete">
  <table>
    <tr>
      <td>비밀번호</td>
      <td><input type="password" name="pass"></td>
      <td><input type="submit" value="확인"></td>
    </tr>
  </table>
<?
  exit;
  }
?>
<?
  $conn = mysql_connect("localhost", "root", "rumidier");
  @mysql_select_db("brain", $conn);
  @mysql_query("set name utf8");

  $query  = "select pass from guestbook where id='$_GET[id]'";

  $result = mysql_query($query, $conn);
  $row    = mysql_fetch_array($result);

  if ($row['pass'] == $_POST['pass'])
  {
    $query = "delete from guestbook where id='$_GET[id]'";
    $result = mysql_query($query,$conn);
  }
?>
<script>alert("글이 삭제되었습니다."); locatioin.href="list.php";</script>
</html>
