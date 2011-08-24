#!/usr/bin/env perl 

use 5.010;
use strict;
use warnings;
use Test::Module;

my @nomal_files = qw/ start.html start.mkd /;

my @input_files = cat_input (\@nomal_files, @ARGV);
index_out (@input_files);
