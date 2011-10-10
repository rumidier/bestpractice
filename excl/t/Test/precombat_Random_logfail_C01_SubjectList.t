use 5.014;
use strict;
use warnings;
use DBI;
use Text::CSV::Encoded;
use Text::CSV_XS;
use Data::Dumper;


use Test::More 'no_plan';                      # last test to print

my @csv_rows;
my $csv = Text::CSV_XS->new(
    {
        binary       => 1,
        eol          => $/,
        always_quote => 1,
    }
) or die "Cannot use CSV: " . Text::CSV_XS->error_diag();

open my $fh, '<',
     'csv/precombat_logfail-mapping/precombat_logfail-mapping_C01_SubjectList.csv';

my $header = $csv->getline($fh);
$csv->column_names(@$header);

my $master_lookup_file   = 'csv/lookup.csv';
my $serial_local_id_file = 'csv/precombat_logfail-mapping/file-localid.csv';
;
my $master         = load_master($master_lookup_file);
my $serial_localid = load_localid($serial_local_id_file);


my $pat_localid = qr/^\d{8}$/;
my $pat_serial  = qr/^\w{1,2}\d{6}$/;
my $main_serial  = qr/^\d{5}$/;

my $old_serial;
my $localid;
my $serial;
while ( my $csv_row = $csv->getline_hr($fh) ) {
    $old_serial = $csv_row->{'serial'};
    $localid    = $serial_localid->{$old_serial};
    $serial     = $master->{$localid};
    diag $serial;
exit;
}

my $dbh = DBI->connect(
    "DBI:mysql:database=rum-test;host=localhost",
    "rumidier",
    "rumidier",
    {
        RaiseError => 1,
        AutoCommit => 1,
    }
);

sub load_localid {
    my ($serial_local_id_file) = @_;

    print "328 : $serial_local_id_file\n";
    my $csv = Text::CSV_XS->new( { binary => 1, eol => $/, always_quote => 1 } )
        or die "Cannot use CSV: " . Text::CSV_XS->error_diag();

    open $fh, "<:encoding(utf8)", "$serial_local_id_file"
        or die "$serial_local_id_file:e $!";

    my %serial_localid;
    while ( my $row = $csv->getline($fh) ) {
        unless ($row->[0] =~ $main_serial) {
            die unless $row->[0] =~ $pat_serial;
        }
        die unless $row->[1] =~ $pat_localid;
        $serial_localid{ $row->[0] } = $row->[1];
    }

    close $fh;
    return \%serial_localid;
}

sub load_master {

    my ($master_lookup_file) = @_;
    my $csv = Text::CSV_XS->new( { binary => 1, eol => $/, always_quote => 1 } )
        or die "Cannot use CSV: " . Text::CSV_XS->error_diag();

    open my $fh, "<:encoding(utf8)", "$master_lookup_file"
        or die "$master_lookup_file:e $!";

    my %master;
    while ( my $row = $csv->getline($fh) ) {
        die unless $row->[0] =~ $pat_localid;
        die unless $row->[1] =~ $pat_serial;
        $master{ $row->[0] } = $row->[1];
    }

    close $fh;
    die unless scalar keys %master == 1771;
    return \%master;
}

sub load_header {
# %header = [ COLUMN_NAME->TABLE_NAME->COLUMN_INFO ]
    my ($target_header_file) = @_;
    my $csv = Text::CSV_XS->new( { binary => 1, eol => $/, always_quote => 1 } )
        or die "Cannot use CSV: " . Text::CSV_XS->error_diag();

    open $fh, "<:encoding(utf8)", "$target_header_file"
        or die "$target_header_file:e $!";

    my %header;
    while ( my $row = $csv->getline($fh) ) {
        $header{ $row->[0] } = [ $row->[1], $row->[2], $row->[3] ];
    }
    close $fh;
    return \%header;
}

sub get_type {
    my ( $path ) = @_;

    my ( $filename, $dirname, $suffix ) = fileparse($path, qr/\..*$/);
    return unless $suffix eq '.csv';

    if ($filename =~ m/([A|C|E].*)/) {
        $filename = $1;
        return $filename;
    }
    else {
        print "get_type : $filename\n";
        return;
    }
}

ok 1;

__DATA__
"serial","enrolldate","name","birth_date","age","gender","selected_random"
"S010001","2004-09-09","HKS","1950-04-11","54","M","CABG"
S010001 => 14036387 => AM010001;
C01_SubjectList

