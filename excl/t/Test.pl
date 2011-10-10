#!/usr/bin/env perl 

use strict;
use warnings;
use Test::More;

BEGIN { plan tests => 6, do => [3,4] } # load your module...

ok(0 == 0, test_sub("조한영 입니까?"));
ok(1);
ok(0);
ok(1);
ok(0); # ok, expected failure (see todo list, above)
ok(1); # surprise success!


sub test_sub {
    my $str = shift;
    print "$str\n";
}
=pud
ok(0,1);             # failure: '0' ne '1'
ok('broke','fixed'); # failure: 'broke' ne 'fixed'
ok('fixed','fixed'); # success: 'fixed' eq 'fixed'
ok('fixed',qr/x/);   # success: 'fixed' =~ qr/x/

ok(sub { 1+1 }, 2);  # success: '2' eq '2'
ok(sub { 1+1 }, 3);  # failure: '2' ne '3'

my @list = (0,0);
ok @list, 3, "\@list=".join(',',@list);      #extra notes
ok 'segmentation fault', '/(?i)success/';    #regex match

skip(
$^O =~ m/MSWin/ ? "Skip if MSWin" : 0,  # whether to skip
$foo, $bar  # arguments just like for ok(...)
);
skip(
$^O =~ m/MSWin/ ? 0 : "Skip unless MSWin",  # whether to skip
$foo, $bar  # arguments just like for ok(...)
);
