#!/usr/bin/env perl

use 5.014;
use strict;
use warnings;

print "하나 : ";
chomp( my $first = <STDIN> );

print "둘 : ";
chomp( my $second = <STDIN> );

say $first * $second;
