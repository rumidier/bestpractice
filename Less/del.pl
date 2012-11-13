#!/usr/bin/env perl 

use 5.010;
use strict;
use warnings;

my @del = q{ ../iseeimageC/03\354\236\245/p66.c
../iseeimageC/03\354\236\245/p67.c
../iseeimageC/03\354\236\245/p68.c
../iseeimageC/03\354\236\245/p69.c
../iseeimageC/03\354\236\245/p70.c
../iseeimageC/03\354\236\245/p71.c
../iseeimageC/03\354\236\245/p73.c
../iseeimageC/03\354\236\245/p74.c
../iseeimageC/03\354\236\245/p75.c
../iseeimageC/03\354\236\245/p77.c
../iseeimageC/03\354\236\245/p78.c
../iseeimageC/03\354\236\245/p79.c
../iseeimageC/04\354\236\245/Makefile
../iseeimageC/04\354\236\245/p101.c
../iseeimageC/04\354\236\245/p105.c
../iseeimageC/04\354\236\245/p106.c
../iseeimageC/04\354\236\245/p106_2.c
../iseeimageC/04\354\236\245/p107.c
../iseeimageC/04\354\236\245/p87.c
../iseeimageC/04\354\236\245/p89.c
../iseeimageC/04\354\236\245/p91.c
../iseeimageC/04\354\236\245/p93.c
../iseeimageC/04\354\236\245/p95.c
../iseeimageC/04\354\236\245/p97.c
../iseeimageC/04\354\236\245/p99.c
../iseeimageC/05\354\236\245/Makefile
../iseeimageC/05\354\236\245/p116.c
../iseeimageC/05\354\236\245/p117.c
../iseeimageC/05\354\236\245/p119.c
../iseeimageC/05\354\236\245/p121.c
../iseeimageC/05\354\236\245/p123.c
../iseeimageC/05\354\236\245/p126.c
../iseeimageC/06\354\236\245/Makefile
../iseeimageC/06\354\236\245/abc.txt
../iseeimageC/06\354\236\245/bintest.dat
../iseeimageC/06\354\236\245/dog.txt
../iseeimageC/06\354\236\245/ex/Makefile
../iseeimageC/06\354\236\245/ex/ex-04.c
../iseeimageC/06\354\236\245/ex/ex-05.c
../iseeimageC/06\354\236\245/mat.txt
../iseeimageC/06\354\236\245/p137.c
../iseeimageC/06\354\236\245/p139.c
../iseeimageC/06\354\236\245/p143.c
../iseeimageC/06\354\236\245/p145.c
../iseeimageC/06\354\236\245/p147.c
../iseeimageC/06\354\236\245/p148.c
../iseeimageC/06\354\236\245/p149.c
../iseeimageC/07\354\236\245/Makefile
../iseeimageC/07\354\236\245/cal.c
../iseeimageC/07\354\236\245/p161.c
../iseeimageC/07\354\236\245/p163.c
../iseeimageC/07\354\236\245/p167.c };

 foreach my $del (@del) {
     eval "git rm $del";
 };
