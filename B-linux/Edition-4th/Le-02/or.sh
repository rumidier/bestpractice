#!/bin/sh

rm -rf file_one

if [ -f file_one ] || echo "hello" || echo " there"
then
  echo "in if"
  fi

  exit 0

##
# [ -f file_one ] &&  명령문1 || 명령문2
##
