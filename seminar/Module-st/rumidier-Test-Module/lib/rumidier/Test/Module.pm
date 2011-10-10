package rumidier::Test::Module;

use 5.006;
use strict;
use warnings;
use Data::Section::Simple qw(get_data_section);

require Exproter;

our @ISA = qw(Exporter);

=head1 NAME

rumidier::Test::Module - The great new rumidier::Test::Module!

=head1 VERSION

Version 0.01

=cut

our @EXPORT = qw(
        cat_input
        index_out
);
our %EXPORT_TAGS = ( 'all' => [ @EXPORT ] );
our @EXPORT_OK = ( @{ $EXPORT_TAGS{'all'} } );
our $VERSION = '0.01';

=head1 SYNOPSIS

Quick summary of what the module does.

Perhaps a little code snippet.

    use rumidier::Test::Module;

    my $foo = rumidier::Test::Module->new();
    ...

=head1 EXPORT

A list of functions that can be exported.  You can delete this section
if you don't export anything, such as for a purely object-oriented module.

=head1 SUBROUTINES/METHODS

=head2 function1

=cut

sub index_out {
    my (@fn) = @_;
    my $file_index;

    foreach (@fn) {
        $file_index = get_data_section($_);
        open my $fh, '>', $_ or die "data_file: $_";
        print $fh $file_index;
        close $fh;
    }
}

=head2 function2

=cut

sub cat_input {
    my ($nomal, @in_put) = @_;
    my @out_put;

    if (@in_put) {
        foreach (@in_put) {
            given ($_) {
                when (@$nomal) {
                    push(@out_put, $_);
                }
                default {
                    print "BUG [$_] 그런 파일이나 디렉터리가 없습니다.\n";
                }
            }
        }
    }
    else {
        @out_put = @$nomal;
    }

    @out_put ? return @out_put : return @out_put = @$nomal;
}

=head1 AUTHOR

rumidier - 조한영, C<< <rumidier at gmail.com> >>

=head1 BUGS

Please report any bugs or feature requests to C<bug-rumidier-test-module at rt.cpan.org>, or through
the web interface at L<http://rt.cpan.org/NoAuth/ReportBug.html?Queue=rumidier-Test-Module>.  I will be notified, and then you'll
automatically be notified of progress on your bug as I make changes.




=head1 SUPPORT

You can find documentation for this module with the perldoc command.

    perldoc rumidier::Test::Module


You can also look for information at:

=over 4

=item * RT: CPAN's request tracker (report bugs here)

L<http://rt.cpan.org/NoAuth/Bugs.html?Dist=rumidier-Test-Module>

=item * AnnoCPAN: Annotated CPAN documentation

L<http://annocpan.org/dist/rumidier-Test-Module>

=item * CPAN Ratings

L<http://cpanratings.perl.org/d/rumidier-Test-Module>

=item * Search CPAN

L<http://search.cpan.org/dist/rumidier-Test-Module/>

=back


=head1 ACKNOWLEDGEMENTS


=head1 LICENSE AND COPYRIGHT

Copyright 2011 rumidier - 조한영.

This program is free software; you can redistribute it and/or modify it
under the terms of either: the GNU General Public License as published
by the Free Software Foundation; or the Artistic License.

See http://dev.perl.org/licenses/ for more information.


=cut

1; # End of rumidier::Test::Module
