<?
  include "db_info.php";

  $query = "insert into guestbook (name, pass, content) ";
  $query .= " values ('$_POST[name]', '$_POST[pass]', '$_POST[content]')";
  $result = mysql_query($query, $conn);
?>

<script>
alert("글이 등록 되었습니다.");
location.href="list.php";
</script>
