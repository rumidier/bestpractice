#!/bin/sh

echo "Is it morning? Please answer yes or no"
read timeofday

case "$timeofday" in
  yes | y | Yes | YES )
    echo "Good Morning"
    echo "Up bright and early this morning"
    ;;

  [nN]*)
    echo "Good Afternoon"
    ;;

esac
exit 0

# [yY] | [Yy][Ee][Ss] )
