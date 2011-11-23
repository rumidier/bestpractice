#!/bin/sh

echo "Is it morning? Please answer yes or no"
read timeofday

case "$timeofday" in
yeas | y | Yes | YES ) echo "Good Morning";;
n* | N* )              echo "Good Afternoon";;
* )                    echo "Sorry, answer not recofnized";;
esac

exit 0
