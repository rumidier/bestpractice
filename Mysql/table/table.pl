USE sql-test;
DROP TABLE IF EXISTS `tbl_points`;
CREATE TABLE `tbl_namelist` (
	id 	INT,
	name 	VARCHAR(10),
	point   INT
);

DROP TABLE IF EXISTS `tbl_noodles`;
CREATE TABLE `tbl_noodles` (
	no 	INT NOT NULL,
	name 	VARCHAR(20),
	taste 	VARCHAR(5)
);

INSERT INTO tbl_noodles (section, name)
	VALUES (1, '서울 라면', '된장');
INSERT INTO tbl_noodles (section, name)
	VALUES (2, '부산 라면', '사골');
INSERT INTO tbl_noodles (section, name)
	VALUES (3, '광주 라면', '간장');

DROP TABLE IF EXISTS `tbl_snack`;
CREATE TABLE `tbl_snack` (
	no       INT PRIMARY KEY,
	name     VARCHAR(20)
);

INSERT INTO tbl_snack
	VALUES (1, '포테이토칩');
INSERT INTO tbl_snack
	VALUES (2, '전병');
INSERT INTO tbl_snack
	VALUES (3, '쿠키');

DROP TABLE IF EXISTS `tbl_test`;
CREATE TABLE `tbl_test` (
	student_no   INT PRIMARY KEY,
	name 	     VARCHAR(10),
	score_korean INT,
	score_math   INT
);

INSERT INTO tbl_test
	VALUES (1, '김상택', 70, 95);
INSERT INTO tbl_test
	VALUES (2, '이해준', 67, 59);
INSERT INTO tbl_test
	VALUES (3, '박원규', 58, 63);
INSERT INTO tbl_test
	VALUES (4, '임소천', 70, 47);
INSERT INTO tbl_test
	VALUES (5, '강유미', 50, 58);

USE sql-test;
DROP TABLE IF EXISTS `tbl_bowling`;
CREATE TABLE `tbl_bowling` (
	no      INT PRIMARY KEY,
	class   VARCHAR(4),
	sex     VARCHAR(4),
	name    VARCHAR(10),
	score1  INT
	score2  INT
);

INSERT INTO tbl_bowling
	VALUES (1, 'B', '여', '이소현', 75, 96);
INSERT INTO tbl_bowling
	VALUES (2, 'A', '여', '강윤주', 80, 77);
INSERT INTO tbl_bowling
	VALUES (3, 'B', '남', '전택일', 120, 105);
INSERT INTO tbl_bowling
	VALUES (4, 'A', '남', '박상규', 150, 130);
INSERT INTO tbl_bowling
	VALUES (5, 'B', '남', '김형준', 89, 91);
