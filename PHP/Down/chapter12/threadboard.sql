CREATE TABLE `threadboard` (
id int(11) unsigned NOT NULL auto_increment,
thread int(11) signed NOT NULL,
depth int(11) unsigned NOT NULL default '0',
name varchar(20) NOT NULL,
email varchar(30),
pass varchar(10) NOT NULL,
title varchar(70) NOT NULL,
content text NOT NULL,
wdate int(11) NOT NULL,
ip varchar(16) NOT NULL,
view int(11) NOT NULL default '0',
PRIMARY KEY (id)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
