#!/bin/sh

if [ -f .profile ]
  then
    exit 0
fi

exit 1

# [ -f .profile ] && exit 0 || exit 1
