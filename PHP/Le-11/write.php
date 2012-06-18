<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xthml1-transitional.dtd">
<html>
  <head>
    <title>초 허접 게시판</title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />

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
  <!-- 입력된 값을 다음 페이지로 넘기기 위해 form을 만든다. -->
  <form action="insert.php" method="POST">
    <table width=580 border=0 cellpadding=2 cellspacing=1 bgcolor=#777777>
      <tr>
        <td height=20 align="center" bgcolor=#999999>
	  <font color="white"><b>글 쓰 기</b></font>
	</td>
      </tr>
      <!-- 입력 부분 -->
      <tr>
        <td bgcolor="white">&nbsp;
	  <table>
	    <tr>
	      <td width=60 align="left">이름</td>
	      <td align="left">
	        <input type="text" name="name" size=20 maxlength=10>
	      </td>
	    </tr>
	    <tr>
	      <td width=60 align="left">이메일</td>
	      <td align="left">
	        <input type="text" name="email" size=20 maxlength=25>
	      </td>
	    </tr>
	    <tr>
	      <td width=60 align="left">비밀번호</td>
	      <td align="left">
	        <input type="password" name="pass" size=8 maxlength=8>
	      </td>
	    </tr>
	    <tr>
	      <td width=60 align="left">제 목</td>
	      <td align="left">
	        <input type="text" name="title" size=60 maxlength=35>
	      </td>
	    </tr>
	    <tr>
	      <td width=60 align="left">내용</td>
	      <td align="left">
		<textarea name=content cols=65 rows=15></textarea>
	      </td>
	    </tr>
	    <tr>
	      <td colspan=10 align=center>
	        <input type=submit value="글 저장하기">
		&nbsp;&nbsp;
		<input type=reset value="다시 쓰기">
		&nbsp;&nbsp;
		<input type=button value="되돌아가기"
		onclick="history.back(-1)">
	      </td>
	    </tr>
	  </table>
	</td>
      </tr>
      <!-- 입력 부분 끝 -->
    </table>
  </form>
  </center>
  </body>
</html>
