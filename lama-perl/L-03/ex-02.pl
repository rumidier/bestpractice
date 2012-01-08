#!/usr/bin/env perl

use 5.014;
use strict;
use warnings;

my @strings = qw/ fred betty barney dino wilma pebbles bamm-bamm  /;

my @inputs;
chomp( @inputs = <STDIN> );

for my $key ( @inputs ) {
    say $strings[$key - 1];
}
