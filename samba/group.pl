#!/usr/bin/env perl 

use 5.010;
use strict;
use warnings;
use Unix::GroupFile;

my $grp = new Unix::GroupFile "/etc/group";
$grp->group("cv", "rumidier2", $grp->maxgid+1, 'rumidier2');
$grp->add_user("cv", "jo", "good");
$grp->passwd("cv", $grp->encpass("rumidier2"));
undef $grp;
