USE sql-test;
DROP TABLE IF EXISTS `tbl_namelist`;
CREATE TABLE `tbl_namelist` (
	no 	INT,
	name 	VARCHAR(10)
);
DROP TABLE IF EXISTS `tbl_grades`;
CREATE TABLE `tbl_grades` (
	no 	INT,
	history	INT,
	science	INT
);


INSERT INTO tbl_namelist (section, name)
	VALUES (1, '강유미');
INSERT INTO tbl_namelist (section, name)
	VALUES (2, '전상철');
INSERT INTO tbl_namelist (section, name)
	VALUES (3, '박나리');
INSERT INTO tbl_grades (section, name)
	VALUES (1, 78, 65);
INSERT INTO tbl_grades (section, name)
	VALUES (2, 81, 93);

USE sql-test;
DROP TABLE IF EXISTS `tbl_race`;
CREATE TABLE `tbl_race` (
	no       INT,
	team     VARCHAR(20),
	result   INT
);
INSERT INTO tbl_race
	VALUES (92, 'team9292', 1);
INSERT INTO tbl_race
	VALUES (10, 'nonstop', 3);
INSERT INTO tbl_race
	VALUES (46, 'v-rossi', 4);
INSERT INTO tbl_race
	VALUES (74, 'daechan', 5);
INSERT INTO tbl_race
	VALUES (19, 'senior', 6);
INSERT INTO tbl_race
	VALUES (11, 'uran', 7);

USE sql-test;
DROP TABLE IF EXISTS `tbl_club1`;
CREATE TABLE `tbl_club1` (
	no 	INT,
	fname 	VARCHAR(10),
	sname 	VARCHAR(10)
);
DROP TABLE IF EXISTS `tbl_club2`;
CREATE TABLE `tbl_club2` (
	no 	INT,
	fname 	VARCHAR(10),
	sname 	VARCHAR(10)
);

INSERT INTO tbl_novel
	VALUES (1, 'juhee', 'kim');
INSERT INTO tbl_novel
	VALUES (2, 'yumi', 'kang');
INSERT INTO tbl_novel
	VALUES (3, 'youngmi', 'noh');
INSERT INTO tbl_novel
	VALUES (1, 'youngjun', 'park');
INSERT INTO tbl_novel
	VALUES (2, 'yumi', 'kang');
INSERT INTO tbl_novel
	VALUES (3, 'taemin', 'jung');

USE sql-test;
DROP TABLE IF EXISTS `tbl_dinner`;
CREATE TABLE `tbl_dinner` (
	no 	INT,
	menu    VARCHAR(20),
	price   INT
);

INSERT INTO tbl_dinner
	VALUES (1111, '햄버그 스테이크', 13000);
INSERT INTO tbl_dinner
	VALUES (1112, '닭고기 프라이', 9000);
INSERT INTO tbl_dinner
	VALUES (1113, '생갈비구이', 10000);
INSERT INTO tbl_dinner
	VALUES (1114, '닭다리 허브구이', 13500);
INSERT INTO tbl_dinner
	VALUES (1115, '펠레 스테이크', 18000);
INSERT INTO tbl_dinner
	VALUES (1116, '두부 스파게티', 15500);

USE sql-test;
DROP TABLE IF EXISTS `tbl_lunch`;
CREATE TABLE `tbl_lunch` (
	no 	INT,
	menu    VARCHAR(20),
	prince  INT
);

INSERT INTO tbl_lunch
	VALUES (2221, '닭튀김 정식', 8500);
INSERT INTO tbl_lunch
	VALUES (2222, '카레라이스', 9000);
INSERT INTO tbl_lunch
	VALUES (2223, '폭찹 정식', 10000);
INSERT INTO tbl_lunch
	VALUES (2224, '튀김 우동', 11000);
INSERT INTO tbl_lunch
	VALUES (2225, '버섯 스파게티', 13500);
INSERT INTO tbl_lunch
	VALUES (2226, '샥스핀 스프', 14000);
