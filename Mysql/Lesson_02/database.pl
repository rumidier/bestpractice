#!/usr/bin/env perl 

use strict;
use warnings;

# 데이터베이스 만들기

CREATE TABLE tbl_picbook (
        code INT,
        title VARCAR(30),
        price INT
        );

SELECT * FROM tbl_picbook;

-------------------------

# 데이터베이스 제약 조건
CREATE TABLE tbl_picbook2 (
        code INT UNIQUE NOT NULL,
        title VARCHAR(30),
        price INT,
        PRIMARY KEY (title, price)
        );
