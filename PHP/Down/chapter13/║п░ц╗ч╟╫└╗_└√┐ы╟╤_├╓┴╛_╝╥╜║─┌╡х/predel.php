<html>
<head>
<title>������ �Խ���</title>
<style>
<!--
    td  { font-size : 9pt;   }
    A:link  { font : 9pt;color : black;text-decoration : none;font-family : ����;font-size : 9pt;  }
    A:visited  {   text-decoration : none; color : black;    font-size : 9pt;  }
    A:hover  {     text-decoration : underline; color : black; font-size : 9pt;  }

-->    
</style>
<script>

	function FormCheck() {

		if (!fm.pass.value)
		{
			alert("��ȣ�� �Է��ϼ���.");
			fm.pass.focus();
			return false;
		}
	}

</script>
</head>

<body topmargin=0 leftmargin=0 text=#464646>

<center>
<BR>

<!-- �Էµ� ���� ���� �������� �ѱ�� ���� FORM�� �����. -->
<form action=del.php?id=<?=$_GET[id]?> method=post name=fm onsubmit="return FormCheck()">

<table width=300 border=0  cellpadding=2 cellspacing=1 bgcolor=#777777>
<tr>
    <td height=20 align=center bgcolor=#999999>
        <font color=white><B>�� �� �� ȣ Ȯ ��</B></font>
    </td>
</tr>
<tr>
    <td align=center >
        <font color=white><B>��й�ȣ : </b>
        <INPUT type=password name=pass size=8 maxlength=8 AUTOCOMPLETE="OFF">
        <INPUT type=submit value="Ȯ ��">
        <INPUT type=button value="�� ��" onclick="history.back(-1)">
    </td>
</tr>
</table> 