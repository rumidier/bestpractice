#!/bin/sh

echo "Is it morng please answer yes or no"
read timeofday

if [ "$timeofday" = "yes" ]; then
  echo "Good morning"
elif [ "$timeofday" = "no" ]; then
  echo "Good afternoon"
else
  echo "Sorry, "$timeofday" noe recognized. Enter yes or no"
  exit 1

fi

exit 0
