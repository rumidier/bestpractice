#!/usr/bin/env perl

use 5.014;
use strict;
use warnings;

my @inputs;
chomp( @inputs = <STDIN> );

for my $key ( sort @inputs ) {
    say $key;
}
