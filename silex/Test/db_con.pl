#!/usr/bin/env perl 

use strict;
use warnings;
use DBI;
use User::pwent;

my $dbh = DBI->connect("DBI:mysql:database=rumidier-test;host=localhost","rumidier","rumidier", { RaiseError => 1, AutoCommit => 1 });

my $sql_fmt = "INSERT INTO users VALUES( %d, %s )";
my $sql;
while (my $user = getpwent) {
    $sql = sprintf ($sql_fmt, $user->uid, $dbh->quote($user->name));
    $dbh->do($sql);
}
my $sth = $dbh->prepare("SELECT * FROM users WHERE uid < 50");
$sth->execute;

my @row;
while ((@row) = $sth->fetchrow_array) {
    print join(",", map {defined $_ ? $_ : "(null)"} @row), "\n";
}
$sth->do("DROP TABLE users");
$dbh->disconnect;
