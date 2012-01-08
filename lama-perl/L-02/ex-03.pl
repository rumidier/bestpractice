#!/usr/bin/env perl

use 5.014;
use strict;
use warnings;

chomp( my $cir = <STDIN> );
my $full_cir;

if ($cir le 0 ) {
    say '원주 : 0';
}
else {
    $full_cir = $cir * 2 * 3.14;

    say "원주 : $full_cir";
}
