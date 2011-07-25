#!/usr/bin/env perl 

use utf8;
use 5.010;
use strict;
use warnings;
use Text::CSV::Encoded;
use Text::CSV_XS;



my @rows;
my $csv = Text::CSV_XS->new ({ binary => 1, eol=> $/, always_quote => 1}) or die "Cannot use CSV: ".Text::CSV_XS->error_diag ();
open my $fh, "<:encoding(utf8)", "precombat_logfail-mapping.csv" or die "precombat_logfail-mapping.csv:e $!";

while (my $row = $csv->getline ($fh)) {
    push @rows, $row;
# do something with @$row
}
$csv->eof or $csv->error_diag;
close $fh;

open $fh, ">:encoding(utf8)", "new.csv" or die "new.csv: $!";
foreach my $row (@rows) {
    $csv->print ($fh, $row);
}
close $fh or die "file.csv: $!";
