#!/usr/bin/env perl
use 5.014;
use strict;
use warnings;
use DBI;
use Text::CSV::Encoded;
use Text::CSV_XS;
use Data::Dumper;
use Test::More 'no_plan';

my $csv = Text::CSV_XS->new(
    {
        binary      => 1,
        eol          => $/,
        always_quote => 1,
    }
)or die "Cannot use  CSV: " . Text::CSV_XS->error_diag();

my $target_data_file = 'csv/precombat-2-mapping/precombat-2-mapping_C14_AngiographicFunctionalTe.csv';
open my $fh, "<:encoding(utf8)", $target_data_file or die "$target_data_file: $!";
my @excl_columns = qw/
        serial
        FUANGIO
        FATYP
        FAGIOD
        FUCATHRT
        FUCATHLT
        FUIVUS
        FUISR
        FUISRS1
        FUISR1TY
        FUISRS1R
        FUISRS2
        FUISR2TY
        FUISRS2R
        FUISRS3
        FUISR3TY
        FUISRS3R
        FUNL
        FUNLS1
        FUNLR1
        FUNLS2
        FUNLR2
        FUNLS3
        FUNLR3
        FUNCTEST
        FTTYP
        FSPECTD
        FSPECTR
        FTMTD
        FTMTR
        FSECHOD
        FSECHOR
        FMRID
        FMRIR
        FANGCOMT
/;

my %csv_info;
while ( my $row_ref = $csv->getline($fh) ) {
    $csv_info{ $row_ref->[0] } = convert_row_to_hashref($row_ref);
}
=pod
csv 파일을 한줄씩 읽어 들여(레퍼런스) %csv_info {

my $header = $csv->getline($fh);
$csv->column_names(@$header);

my $dbh = DBI->connect(
        "DBI:mysql:database=rum-test;host=localhost",
        "rumidier",
        "rumidier",
        {
            RaiseError => 1,
            AutoCommit => 1,
        }
);

my $sth = $dbh->prepare("SELECT serial, FUANGIO, FATYP, FAGIOD, FUCATHRT,
        FUCATHLT, FUIVUS, FUISR FROM C13_AngioFU");
$sth->execute();

my %db_info;
my @db_row_ref;
while ( @db_row_ref = $sth->fetchrow_array ) {
    my $db_ref = \@db_row_ref;
    $db_info{ $db_ref->[0] } = convert_row_to_hashref($db_ref);
}

=pod
sub convert_row_to_hashref {
    my $row_ref = shift;

    my %result = (
        'FUANGIO'  => $row_ref->[1],
        'FATYP'    => $row_ref->[2],
        'FAGIO'    => $row_ref->[3],
        'FUCATHRT' => $row_ref->[4],
        'FUCATHLT' => $row_ref->[5],
    );

    return \%result;
}
=cut

1;

sub convert_row_to_hashref {
    my $row_ref = shift;

    my @row = @$row_ref;
    shift @row;

    my %result;
    @result{ @excl_columns[1 .. $#excl_columns] } = @row;

    return \%result;
}
