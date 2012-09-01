#!/usr/bin/env perl 

use 5.010;
use strict;
use warnings;

my @lines;
while ( my $line = <> ) {
    push @lines, $line;
}
print reverse @lines;

print reverse <>;
