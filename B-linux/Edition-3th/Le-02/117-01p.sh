#!/bin/sh

for image in *.gif
do
	cjpeg $image > ${image%%fig}jpg
done
