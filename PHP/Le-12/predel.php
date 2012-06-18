<!DOCTYPE html PUBLIC "-//W3C//DTD XTHML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html>
  <head>
    <title>초 허접 게시판</title>
    <script type="text/javascript">
    function FormCheck() {
      if(!document.fm.pass.value) {
	alert("비밀번호를 입력하세요.");
	document.fm.pass.focus();

	return false;
      }
    }
    </script>
    <style>
    <!--
    td { font-size : 9pt; }
    A:link { font : 9pt; color : black; text-decoration : none; font-family : 굴림; font-size : 9pt; }
    A:visited { text-decoration : none; color : black; font-size : 9pt; }
    A:hover { text-decoration : underline; color : black; font-size : 9pt; }
    -->
    </style>
  </head>

  <body topmargin=0 leftmargin=0 text=#464646>
  <center>
  <br />

  <form action=del.php?id=<?=$_GET[id]?> method="POST" name="fm" onsubmit="return FormCheck()">
    <table width=300 border=0 cellpadding=2 cellspaching=1 bgcolor=#777777>
      <tr>
	<td height=20 align=center bgcolor=#999999>
	  <font color=white><b>비 밀 번 호 확 인</b></font>
	</td>
      </tr>
      <tr>
	<td align=center>
	  <font color=white><b>비밀번호 : </b>
	  <input type=password name=pass size=8>
	  <input type=submit value="확 인">
	  <input type=button value="취 소" onclick="history.back(-1)">
	</td>
      </tr>
    </table>
