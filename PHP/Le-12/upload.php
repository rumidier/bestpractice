<?
  if (empty($_FILES['upfile']['name'])) {
    echo "업로드된 파일이 없습니다.";
    exit;
  }

  echo "파일명      : " . $_FILES['upfile']['name'] . "<br />";
  echo "MIME        : " . $_FILES['upfile']['type'] . "<br />";
  echo "파일크기    : " . $_FILES['upfile']['size'] . "<br />";
  echo "임시 파일   : " . $_FILES['upfile']['tmp_name'] . "<br />";
  echo "에러코드    : " . $_FILES['upfile']['error'] . "<br />";

  $temp_name = $_FILES['upfile']['tmp_name'];
  $upload = '/home/meadow/workspace/github/PHP/Le-12/uploads_dir/';
  $name   = $_FILES['upfile']['name'];
  move_uploaded_file($temp_name, "$upload$name");
  echo "파일이 업로드 되었습니다.";
?>
