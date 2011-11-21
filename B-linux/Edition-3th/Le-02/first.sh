#!/bin/sh

for file in *
do
if grep -q POSIX $file
then
more $file
fi
done

exit 0

