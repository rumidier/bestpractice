#!/usr/bin/env perl

use 5.014;
use strict;
use warnings;

chomp( my $cir = <STDIN> );
my $full_cir;

$full_cir = 12.5 * 2 * 3.14;
say "원주 : $full_cir";
