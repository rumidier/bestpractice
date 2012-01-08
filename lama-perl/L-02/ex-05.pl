#!/usr/bin/env perl

use 5.014;
use strict;
use warnings;

print '문자열 : ';
chomp( my $str = <STDIN> );

print '숫자 : ';
chomp( my $num = <STDIN> );

say $str x $num;
