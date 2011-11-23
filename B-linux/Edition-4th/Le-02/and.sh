#!/bin/sh

touch file_one
rm -rf file_two

if [ -f file_one ] && echo "hello" && [ -f file_two ] && echo " there"
then
  echo "in if"
else
  echo "in else"
fi

exit 0
