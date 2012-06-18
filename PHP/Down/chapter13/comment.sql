CREATE TABLE `comment` (
id int(11) unsigned NOT NULL auto_increment,
bid int(11) unsigned NOT NULL,
name varchar(20) NOT NULL,
pass varchar(10) NOT NULL,
comment text NOT NULL,
wdate timestamp NOT NULL default CURRENT_TIMESTAMP,
ip varchar(15) NOT NULL,
PRIMARY KEY(id),
KEY idx (bid)
) ENGINE=MyISAM DEFAULT CHARSET=euckr;

CREATE TABLE `tb_count` (
id int(11) unsigned NOT NULL auto_increment,
bid int(11) unsigned NOT NULL,
cnt int(11) unsigned NOT NULL,
PRIMARY KEY(id),
KEY idx (bid)
) ENGINE=MyISAM DEFAULT CHARSET=UTF8;

CREATE TABLE `tb_text` (
id int(11) unsigned NOT NULL auto_increment,
bid int(11) unsigned NOT NULL,
word_n varchar(108) NOT NULL,
word text NOT NULL,
PRIMARY KEY(id),
KEY idx (bid)
) ENGINE=MyISAM DEFAULT CHARSET=UTF8;

CREATE TABLE `word` (
id int(11) unsigned NOT NULL auto_increment,
word varchar(108) NOT NULL,
) ENGINE=MyISAM DEFAULT CHARSET=UTF8;
