#!/bin/sh

echo "Is it morng please answer yes or no"
read timeofday

if [ $timeofday = "yes" ]; then
	echo "Good morning"
else
	echo "Good afternoon"
fi

exit 0
