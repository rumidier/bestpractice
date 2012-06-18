<html>
  <head>
    <title>계층형 게시판</title>
    <style>
      <!--
      td { font-size : 9pt; }
      A:link { font : 9pt; color : black; text-decoration : none; font-family: 굴림; font-size : 9pt; }
      A:visited { text-decoration : underline; color : black; }
      A:hover { text-decoration : underline; color : black; font-size : 9pt; }
      -->
    </style>

    <script>
      function FormCheck() {
	if (!document.fm.pass.value) {
	  alert("암호를 입력하세요.");
	  document.fm.pass.focus();
	  return false;
	}
      }
    </script>
  </head>

  <body topmargin=0 leftmargin=0 text=#464646>
  <center>
  <br />
  <!-- 입력된 값을 다음 페이지로 넘기기 위해 FORM을 만든다. -->
  <form action="comment_del.php?id=<?=$_GET['id']?>&bid=<?=$_GET['bid']?>" method=post name=fm onsubmit="return FormCheck()">
  <table width=300 border=0 cellpadding=2 cellspacing=1 bgcolor=#777777>
    <tr>
      <td height=20 align=center bgcolor=#999999>
	<font color=white><b>비 밀 번 호 확 인</b></font>
      </td>
    </tr>
    <tr>
      <td align=center>
	<font color=white><b>비밀번호 : </b>
	<input type=password name=pass size=8 maxlength=8>
	<input type=submit value="확인">
	<input type=button value="취소" onclick="history.back(-1)">
      </td>
    </tr>
  </table>
</html>
