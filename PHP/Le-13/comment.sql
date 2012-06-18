CREATE TABLE comment (
    id int(11) unsigned NOT NULL auto_increment,
    bid int(11) unsigned NOT NULL,
    name varchar(20) NOT NULL,
    pass varchar(10) NOT NULL,
    comment text NOT NULL,
    wdate timestamp NOT NULL default CURRENT_TIMESTAMP,
    ip varchar(15) NOT NULL,
    PRIMARY KEY(id),
    KEY idx(bid)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
