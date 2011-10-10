use strict;
use warnings;
use Data::Section::Simple qw(get_data_section);
use Test::More;

my $x = get_data_section();
is_deeply [ sort keys %$x ], [ qw(start.html start.mkd) ];

is get_data_section('start.html'), <<HTML;
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Stric//EN"
   "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">

<html>
   <head>
      <meta http-equiv="Content-Type" content="text/html; charset=UTP-8" />
      <title>Main title</title>
   </head>
   <body>
      <form action="http://www.headfirstlabs.com/contest.php" mehod="POST">
         <p> Just type in your name (and click Submit) to
         enter the contest <br />
         First name: <input type="text" name="firstname" value="" /> <br />
     Last name:  <input type="text" name="lastname"  value="" /> <br />
     <input type="submit" />

     <textarea name="comments" rows="10" cols="48"> </textarea>

     <select name="characters">
      </form>
   </body>
</html>

HTML

is get_data_section('start.mkd'), <<MKD;
A First Level Headder
=====================

A Second Level Headder
---------------------
사람들은 모국어로 지원을 하며
이것을 일반적인 파라 그래프 입니다.

날쌘 갈색 여우는 게으른 개뒤로 뛰어 넘었다.

### Header 3
> 이부분은 blockquote 입니다.
>
> 두번째 blockquote 입니다. 
>
> ##blockquote 부분의 H2 부분 입니다.

강조 구절:

강조 하는 단어는(뉘입니다) *em 과 같습니다*
강조 하는 단어는  _em 과 같습니다_

별표를 두개씩 써도 됩니다(두껍게 합니다) **strong 와 같습니다**
또한 언더파를 두개씩 써도 됩니다 __strong 와 같습니다__

리스트
ul은 (* + -)  로 합니다. ol은 (1. str)입니다;

ul:

* first.
* second.
* third.

ul:

+ first
+ second
+ third

ul:

- first
- second
- third

ol:

1. first
2. second
3. third

리스트 사이에 tab넣기(스페이스 4칸)

    tab:

    * 아이템이 있고

    들여쓰기가 된다 근데 이상하다.

    * 또다른 아이템이 온다.

    링크
    -----------------------------

    링크시 마크다운의 두가지기능
    ----------------------------

첫번째
this is an [example link](http://naver.com/)

두번째
This is an [example link](http://navar.com/ "Witha Title")

또 다른 스타일
I het 10 times more traffic from[google][1] than from
[yahoo][2] or [naver][3]

[1]: http://google.com/     "google"
[2]: http://search.yahoo.com/   "Yahoo Search"
[3]: http://naver.com/      "naver"

그외 스타일
I start my morning with a cup of coffee and
[The New york Times][NY Times]

[ny times]: http://www.nytimes.com/

사진
------------
![alt text](image/jun.jpg "Title")

사진 다른 스타일
![alt text][id]

[id]: image/jun.jpg "Title"

MKD

done_testing;

__DATA__
@@ start.html
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Stric//EN"
   "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">

<html>
   <head>
      <meta http-equiv="Content-Type" content="text/html; charset=UTP-8" />
      <title>Main title</title>
   </head>
   <body>
      <form action="http://www.headfirstlabs.com/contest.php" mehod="POST">
         <p> Just type in your name (and click Submit) to
         enter the contest <br />
         First name: <input type="text" name="firstname" value="" /> <br />
     Last name:  <input type="text" name="lastname"  value="" /> <br />
     <input type="submit" />

     <textarea name="comments" rows="10" cols="48"> </textarea>

     <select name="characters">
      </form>
   </body>
</html>

@@ start.mkd
A First Level Headder
=====================

A Second Level Headder
---------------------
사람들은 모국어로 지원을 하며
이것을 일반적인 파라 그래프 입니다.

날쌘 갈색 여우는 게으른 개뒤로 뛰어 넘었다.

### Header 3
> 이부분은 blockquote 입니다.
>
> 두번째 blockquote 입니다. 
>
> ##blockquote 부분의 H2 부분 입니다.

강조 구절:

강조 하는 단어는(뉘입니다) *em 과 같습니다*
강조 하는 단어는  _em 과 같습니다_

별표를 두개씩 써도 됩니다(두껍게 합니다) **strong 와 같습니다**
또한 언더파를 두개씩 써도 됩니다 __strong 와 같습니다__

리스트
ul은 (* + -)  로 합니다. ol은 (1. str)입니다;

ul:

* first.
* second.
* third.

ul:

+ first
+ second
+ third

ul:

- first
- second
- third

ol:

1. first
2. second
3. third

리스트 사이에 tab넣기(스페이스 4칸)

    tab:

    * 아이템이 있고

    들여쓰기가 된다 근데 이상하다.

    * 또다른 아이템이 온다.

    링크
    -----------------------------

    링크시 마크다운의 두가지기능
    ----------------------------

첫번째
this is an [example link](http://naver.com/)

두번째
This is an [example link](http://navar.com/ "Witha Title")

또 다른 스타일
I het 10 times more traffic from[google][1] than from
[yahoo][2] or [naver][3]

[1]: http://google.com/     "google"
[2]: http://search.yahoo.com/   "Yahoo Search"
[3]: http://naver.com/      "naver"

그외 스타일
I start my morning with a cup of coffee and
[The New york Times][NY Times]

[ny times]: http://www.nytimes.com/

사진
------------
![alt text](image/jun.jpg "Title")

사진 다른 스타일
![alt text][id]

[id]: image/jun.jpg "Title"

