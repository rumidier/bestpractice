USE sql-test;
DROP TABLE IF EXISTS `tbl_subjects`;
CREATE TABLE `tbl_subjects` (
	id 	INT PRIMARY KEY,
	name 	VARCHAR(20),
	math 	INT,
	english	INT
);

USE sql-test;
DROP TABLE IF EXISTS `tbl_employee`;
CREATE TABLE `tbl_employee` (
	section  VARCHAR(10),
	name	 VARCHAR(10)
);

DROP TABLE IF EXISTS `tbl_insa`;
CREATE TABLE `tbl_insa` (
	name VARCHAR(10)
);

INSERT INTO tbl_employee (section, name)
	VALUES ('총무부', '고미희');
INSERT INTO tbl_employee (section, name)
	VALUES ('인사부', '궁선영');
INSERT INTO tbl_employee (section, name)
	VALUES ('경리부', '강영주');
INSERT INTO tbl_employee (section, name)
	VALUES ('인사부', '송만식');
INSERT INTO tbl_employee (section, name)
	VALUES ('사장실', '이석천');
INSERT INTO tbl_employee (section, name)
	VALUES ('경리부', '서일도');
INSERT INTO tbl_employee (section, name)
	VALUES ('인사부', '전진만');

USE sql-test;
DROP TABLE IF EXISTS `tbl_shopping`;
CREATE TABLE `tbl_shopping` (
	priority INT,
	material VARCHAR(20),
	number   INT
);
INSERT INTO tbl_shopping
	VALUES (1, '톱', 1);
INSERT INTO tbl_shopping
	VALUES (2, '못', 30);
INSERT INTO tbl_shopping
	VALUES (3, '사포', 5);
INSERT INTO tbl_shopping
	VALUES (4, '합판', 1);

USE sql-test;
DROP TABLE IF EXISTS `tbl_novel`;
CREATE TABLE `tbl_novel` (
	code 	INT PRIMARY KEY,
	title 	VARCHAR(20),
	price 	INT
);
INSERT INTO tbl_novel
	VALUES (1111, '또또와 뚜뚜', 5800);
INSERT INTO tbl_novel
	VALUES (2222, '또또를 둘러싼 탐험', 6800);
INSERT INTO tbl_novel
	VALUES (3333, 'SQL 끝내기', 4300);
INSERT INTO tbl_novel
	VALUES (4444, '또또 아빠의 선물', 9800);

USE sql-test;
DROP TABLE IF EXISTS `tbl_results`;
CREATE TABLE `tbl_results` (
	id 	INT PRIMARY KEY,
	team 	VARCHAR(1),
	name    VARCHAR(10),
	point1 	INT,
	point2  INT
);

INSERT INTO tbl_results
	VALUES (1, 'C', '강택규', 120, 105);
INSERT INTO tbl_results
	VALUES (2, 'A', '유본희', 150, 130);
INSERT INTO tbl_results
	VALUES (3, 'B', '김대원', 105, 98);
INSERT INTO tbl_results
	VALUES (4, 'A', '민상철', 170, 153);
INSERT INTO tbl_results
	VALUES (5, 'C', '사준영', 147, 151);
INSERT INTO tbl_results
	VALUES (6, 'B', '장도운', 130, 125);

USE sql-test;
DROP TABLE IF EXISTS `tbl_advance`;
CREATE TABLE `tbl_advance` (
	id 	INT PRIMARY KEY,
	team 	VARCHAR(1),
	name    VARCHAR(10),
	point1 	INT,
	point2  INT
);

USE sql-test;
DROP TABLE IF EXISTS `tbl_results`;
CREATE TABLE `tbl_results` (
	id 	 INT PRIMARY KEY,
	name     VARCHAR(10),
	overtime INT,
	travel 	 INT,
	total    INT
);

INSERT INTO tbl_results
	VALUES (1, '강택규', 35000, 18000, NULL);
INSERT INTO tbl_results
	VALUES (2, '유본희', 45000, 23600, NULL);
INSERT INTO tbl_results
	VALUES (3, '김대원', 56000, 32000, NULL);
INSERT INTO tbl_results
	VALUES (4, '민상철', 21000, 145000, NULL);
