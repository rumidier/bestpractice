#!/usr/bin/env perl

use 5.014;
use strict;
use warnings;

my @arrs = qw/ 1 3 5 7 9 /;
my $idx;

my $sizeof = @arrs;

$idx = BSearch(\@arrs, $sizeof, 7);
$idx == -1 ? say "탐색 실패" : say "타겟 저장 인덱스: $idx";

$idx = BSearch(\@arrs, $sizeof, 4);
$idx == -1 ? say "탐색 실패" : say "타겟 저장 인덱스: $idx";

sub BSearch {
    my ( $arrs, $len, $target ) = @_;
    my $first = 0;
    my $last  = $len - 1;
    my $mid;

    while ( $first <= $last )
    {
        $mid = int ( ($first + $last) / 2 );

        if ($target == $arrs->[$mid])
        {
            return $mid;
        }
        else {
            if ($target < $arrs->[$mid])
            {
                $last = $mid - 1;
            }
            else
            {
                $first = $mid + 1;
            }
        }
    }

    return -1;
}
