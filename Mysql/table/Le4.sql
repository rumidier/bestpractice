USE sql-test;
DROP TABLE IF EXISTS `tbl_sum`;
CREATE TABLE `tbl_sum` (
	cost DECIMAL(6, 3);
);

INSERT INTO tbl_sum (cost)
	VALUES (1,248);
INSERT INTO tbl_sum (cost)
	VALUES (29.4);
INSERT INTO tbl_sum (cost)
	VALUES (105.05);

USE sql-test;
DROP TABLE IF EXISTS `tbl_stdname`;
CREATE TABLE `tbl_stdname` (
	stname  VARCHAR(20),
	fname VARCHAR(20)
);

INSERT INTO tbl_stdname (sname, fname)
	VALUES ('KIM', 'sangtaek');
INSERT INTO tbl_stdname (sname, fname)
	VALUES (2, 'CHOI', 'sanhae');
INSERT INTO tbl_stdname (sname, fname)
	VALUES (3, 'KANG', 'taekgu');
INSERT INTO tbl_stdname (sname, fname)
	VALUES (4, 'LEE', 'solim');

USE sql-test;
DROP TABLE IF EXISTS `tbl_pet`;
CREATE TABLE `tbl_pet` (
	pname  VARCHAR(10),
);
INSERT INTO tbl_pet (pname)
	VALUES ('   KKOMA   ');
INSERT INTO tbl_pet (pname)
	VALUES ('   ALEX   ');
INSERT INTO tbl_pet (pname)
	VALUES ('   RAN ');
INSERT INTO tbl_pet (pname)
	VALUES ('   SHAM   ');

USE sql-test;
DROP TABLE IF EXISTS `tbl_datelist`;
CREATE TABLE `tbl_datelist` (
	no INT,
	date1 DATETIME,
	date2 DATETIME
);

INSERT INTO tbl_datelist (no, date1, date2)
	VALUES (1, '2004-04-13', '2004-07-03');
INSERT INTO tbl_datelist (no, date1, date2)
	VALUES (2, '2004-10-11', '2005-01-24');


USE sql-test;
DROP TABLE IF EXISTS `tbl_game`;
CREATE TABLE `tbl_game` (
	name VARCHAR(20),
	score INT
);

INSERT INTO tbl_game (name, score) VALUES ('yumi', 125);
INSERT INTO tbl_game (name, score) VALUES ('june', 140);
INSERT INTO tbl_game (name, score) VALUES ('woori', 110);
INSERT INTO tbl_game (name, score) VALUES ('yumi', 75);
INSERT INTO tbl_game (name, score) VALUES ('woorri', 160);
INSERT INTO tbl_game (name, score) VALUES ('june', 98);
INSERT INTO tbl_game (name, score) VALUES ('woori', 90);
INSERT INTO tbl_game (name, score) VALUES ('yumi', 64);
INSERT INTO tbl_game (name, score) VALUES ('june', 105);


USE sql-test;
DROP TABLE IF EXISTS `tbl_schedule`;
CREATE TABLE `tbl_schedule` (
	time VARCHAR(30),
);

INSERT INTO tbl_schedule (time) VALUES ('12 29 2003 8:50AM' );
INSERT INTO tbl_schedule (time) VALUES ('02 06 2004 12:46AM' );
INSERT INTO tbl_schedule (time) VALUES ('06 30 2005 1:29PM' );
