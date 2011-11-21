#!/bin/sh

salutation="Hello"
echo "sal_value = $salutation"
echo "The user's home directory is [$HOME]"
echo "The user's PATH is [$PATH]"
echo "The program [$0] is now running"
echo "The first parameter was [$1]"
echo "The second parameter was [$2]"
echo "The parameter list was $*"

echo "Please enter a new greeting"
read salutation

echo $salutation
echo "The script is now complete"
exit 0
