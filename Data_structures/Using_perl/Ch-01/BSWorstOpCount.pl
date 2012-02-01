#!/usr/bin/env perl

use 5.014;
use strict;
use warnings;

my @arr1 = map {$_ * 0} (1 .. 500);
my @arr2 = map {$_ * 0} (1 .. 5000);
my @arr3 = map {$_ * 0} (1 .. 50000);
my $idx;

$idx = BSearch (\@arr1, scalar @arr1, 1);
$idx == -1 ?  say "탐색실패\n" : say "타겟 저장 인덱스: $idx";

$idx = BSearch (\@arr2, scalar @arr2, 2);
$idx == -1 ?  say "탐색실패\n" : say "타겟 저장 인덱스: $idx";

$idx = BSearch (\@arr3, scalar @arr3, 3);
$idx == -1 ?  say "탐색실패\n" : say "타겟 저장 인덱스: $idx";

sub BSearch {
    my ( $arrs, $len, $target ) = @_;

    my $first = 0;
    my $last = $len - 1;
    my $opCount = 0;
    my $mid;

    while ( $first <= $last ) {
        $mid = int ( ($first + $last) / 2 );

        if ($target == $arrs->[$mid])
        {
            return $mid;
        }
        else {
            $target < $arrs->[$mid] ? ($last = $mid - 1) : ($first = $mid + 1);
        }

        $opCount += 1;
    }
    say "비교 연산 횟수: $opCount";

    return -1;
}
