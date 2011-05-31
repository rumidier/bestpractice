#!/usr/bin/env perl 
#===============================================================================
#
#         FILE:  mailer.pl
#
#        USAGE:  ./mailer.pl 
#
#  DESCRIPTION:  
#
#      OPTIONS:  ---
# REQUIREMENTS:  ---
#         BUGS:  ---
#        NOTES:  ---
#       AUTHOR:   (), <>
#      COMPANY:  
#      VERSION:  1.0
#      CREATED:  2011년 05월 23일 16시 03분 48초 KST
#     REVISION:  ---
#===============================================================================

use strict;
use warnings;
use CGI qw(:standard);

print header(), start_html( "Mail form results"), \
          h1( "Mail form results" );
my $to = parse( "to");
my $from = parse( " from" );
my $subject = parse( "subject");
my $body = parse( "body" );

open (MAIL, "|/usr/lib/sendmail $to" ) ||
die "<p>Error: Couldn't execute sendmail.\n";

print MAIL "To: $to\n";
print MAIL "From: $from\n";
print MAIL "subject: $subject\n\n";
print MAIL "$body\n";
close MAIL;

print p( "All right, mainled the following to <tt>$to</tt>:" );
print p( "<pre>\nTo: $to\nFrom: $from\nsubject:\$subject\n\n$body\n</pre>" );
print end_html();
