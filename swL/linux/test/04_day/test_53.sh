#!/bin/bash
# $ ./test_53.sh -a -b hello -c
while getopts :ab:c opt; do
case $opt in
a) echo "옵션 -a";;
b) echo "옵션 -b $OPTARG";;
c) echo "옵션 -c";;
*) echo "잘못된 옵션";;
esac
done

