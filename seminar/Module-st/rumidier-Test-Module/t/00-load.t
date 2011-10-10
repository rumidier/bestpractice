#!perl -T

use Test::More tests => 1;

BEGIN {
    use_ok( 'rumidier::Test::Module' ) || print "Bail out!\n";
}

diag( "Testing rumidier::Test::Module $rumidier::Test::Module::VERSION, Perl $], $^X" );
