package Test::Module;

use 5.010000;
use strict;
use warnings;
use Data::Section::Simple qw(get_data_section);

require Exporter;

our @ISA = qw(Exporter);

# Items to export into callers namespace by default. Note: do not export
# names by default without a very good reason. Use EXPORT_OK instead.
# Do not simply export all your public functions/methods/constants.

# This allows declaration	use Test::Module ':all';
# If you do not need this, moving things directly into @EXPORT or @EXPORT_OK
# will save memory.
our @EXPORT = qw(
        cat_input
        index_out
);
our %EXPORT_TAGS = ( 'all' => [ @EXPORT ] );
our @EXPORT_OK = ( @{ $EXPORT_TAGS{'all'} } );

our $VERSION = '0.01';
sub index_out {
    my (@fn) = @_;
    my $file_index;

    foreach (@fn) {
        $file_index = get_data_section($_);
        open my $fh, '>', $_ or die "data_file: $_";
        print $fh $file_index;
        close $fh;
    }
}

sub cat_input {
    my ($nomal, @in_put) = @_;
    my @out_put;

    if (@in_put) {
        foreach (@in_put) {
            given ($_) {
                when (@$nomal) {
                    push(@out_put, $_);
                }
                default {
                    print "BUG [$_] 그런 파일이나 디렉터리가 없습니다.\n";
                }
            }
        }
    }
    else {
        @out_put = @$nomal;
    }

    @out_put ? return @out_put : return @out_put = @$nomal;
}
# Preloaded methods go here.
1;
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

### Code ###

I strongly recommend against using any `<blink>` tags.

I wish SmartyPants used named entities like `&mdash;`
instead of decimal-encoded entites like `&#8212;`.

Use the `printf ()` function.

``There is a literal backtick (`) here.``

__END__
# Below is stub documentation for your module. You'd better edit it!

=head1 NAME

Test::Module - Perl extension for blah blah blah

=head1 SYNOPSIS

  use Test::Module;
  blah blah blah

=head1 DESCRIPTION

Stub documentation for Test::Module, created by h2xs. It looks like the
author of the extension was negligent enough to leave the stub
unedited.

Blah blah blah.

=head2 EXPORT

None by default.



=head1 SEE ALSO

Mention other useful documentation such as the documentation of
related modules or operating system documentation (such as man pages
in UNIX), or any relevant external documentation such as RFCs or
standards.

If you have a mailing list set up for your module, mention it here.

If you have a web site set up for your module, mention it here.

=head1 AUTHOR

rumidier, E<lt>rumidier@(none)E<gt>

=head1 COPYRIGHT AND LICENSE

Copyright (C) 2011 by rumidier

This library is free software; you can redistribute it and/or modify
it under the same terms as Perl itself, either Perl version 5.14.1 or,
at your option, any later version of Perl 5 you may have available.


=cut

__END__
# Below is stub documentation for your module. You'd better edit it!

=head1 NAME

Test::Module - Perl extension for blah blah blah

=head1 SYNOPSIS

  use Test::Module;
  blah blah blah

=head1 DESCRIPTION

Stub documentation for Test::Module, created by h2xs. It looks like the
author of the extension was negligent enough to leave the stub
unedited.

Blah blah blah.

=head2 EXPORT

None by default.



=head1 SEE ALSO

Mention other useful documentation such as the documentation of
related modules or operating system documentation (such as man pages
in UNIX), or any relevant external documentation such as RFCs or
standards.

If you have a mailing list set up for your module, mention it here.

If you have a web site set up for your module, mention it here.

=head1 AUTHOR

rumidier, E<lt>rumidier@(none)E<gt>

=head1 COPYRIGHT AND LICENSE

Copyright (C) 2011 by rumidier

This library is free software; you can redistribute it and/or modify
it under the same terms as Perl itself, either Perl version 5.14.1 or,
at your option, any later version of Perl 5 you may have available.


=cut
