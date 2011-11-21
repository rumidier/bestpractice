#!/bin/sh

unset foo
echo ${foo:-bar}

foo=fud
echo ${foo:-bar}

foo=/usr/bin/x11/startx
echo ${foo#*/}
echo ${foo##*/}
#왼쪽서 부터 검사 #첫 패턴 ##은 최대한 많이

bar=/usr/local/etc/local/networks
echo ${bar%local*}
echo ${bar%%local*}
#오른쪽서 부터 검사 %첫 패턴 %%은 최대한 많이

exit 0
