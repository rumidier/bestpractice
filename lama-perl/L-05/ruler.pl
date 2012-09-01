#!/usr/bin/env perl 

use 5.010;
use strict;
use warnings;


my @lines;
while ( my $line = <> ) {
    chomp $line;
    push @lines, $line;
}

my $width = shift @lines;

print "1234567890" for 1 .. 5;
print "\n";

print map("1234567890", 1 .. 5), "\n";


my $format = sprintf "%%%ds", $width;
#my $format = "\%${width}s";

printf "$format\n", $_ for @lines;
