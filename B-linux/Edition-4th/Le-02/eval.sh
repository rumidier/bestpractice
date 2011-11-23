#!/bin/sh

foo=10;
x=foo
y='$'$x
echo $y

foo=10
x=foo
eval y='$'$x
echo $y
