USE sql-test;
DROP TABLE IF EXISTS `tbl_exam`;
CREATE TABLE `tbl_exam` (
	id         INT PRIMARY KEY,
	name 	   VARCHAR(20),
	score_kor  INT,
	score_eng  INT
);

INSERT INTO tbl_exam (id, name, score_kor, score_eng)
	VALUES (1, '김상택', 100, 98);
INSERT INTO tbl_exam (id, name, score_kor, score_eng)
	VALUES (2, '최산해', 75, 80);
INSERT INTO tbl_exam (id, name, score_kor, score_eng)
	VALUES (3, '강택구', 70, 93);
INSERT INTO tbl_exam (id, name, score_kor, score_eng)
	VALUES (4, '이소림', 54, 65);

USE sql-test;
DROP TABLE IF EXISTS `tbl_stdlist`;
CREATE TABLE `tbl_stdlist` (
	id        INT PRIMARY KEY,
	lastname  VARCHAR(10),
	firstname VARCHAR(10)
);

INSERT INTO tbl_stdlist (id, lastname, firstname)
	VALUES (1, '김', '상택');
INSERT INTO tbl_stdlist (id, lastname, firstname)
	VALUES (2, '최', '산해');
INSERT INTO tbl_stdlist (id, lastname, firstname)
	VALUES (3, '강', '택구');
INSERT INTO tbl_stdlist (id, lastname, firstname)
	VALUES (4, '이', '소림');

USE sql-test;
DROP TABLE IF EXISTS `tbl_bookprice`;
CREATE TABLE `tbl_bookprice` (
	code   INT PRIMARY KEY,
	title  VARCHAR(40),
	price  INT
);
INSERT INTO tbl_bookprice (code, title, price)
	VALUES (1, 'C가 보이는 그림책',  12000);
INSERT INTO tbl_bookprice (code, title, price)
	VALUES (2, 'Java가 보이는 그림책', 13000);
INSERT INTO tbl_bookprice (code, title, price)
	VALUES (3, 'SQL이 보이는 그림책', 14000);
