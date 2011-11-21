#!/bin/sh

sample text="global variable"

foo() {
	local sample text="local variable"
	echo "Function foo is executing"
	echo $sample text
}

echo "script staring"
echo $sample text

foo
echo "script ended"
echo $sample text

exit 0
