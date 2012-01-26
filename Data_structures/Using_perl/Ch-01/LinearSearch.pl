#!/usr/bin/env perl

use 5.014;
use strict;
use warnings;
use utf8;
binmode(STDOUT, ":utf8");

my @arr = qw/ 3 5 2 4 9 /;
my $idx;

my $sizeof =  @arr;

$idx = LSearch(\@arr, $sizeof, 4);
if ($idx == -1) {
    say "탐색 실패";
}
else {
    say "타켓 저장 인덱스: $idx";
}

$idx = LSearch(\@arr, $sizeof, 7);
if ($idx == -1) {
    say "탐색 실패";
}
else {
    say "타켓 저장 인덱스: $idx";
}

sub LSearch {
    my ($arrs, $len, $target) = @_;

    my $i = 0;
    for my $arr (@{ $arrs }) {
        if ($arr == $target) {
            return $i;
        }
        $i++;
    }

    return -1;
}
