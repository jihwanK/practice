#!/bin/bash

# $ ./test_52.sh -a -bc

while getopts "abc" opt; do
case $opt in
a) echo "옵션 -a";;
b) echo "옵션 -b";;
c) echo "옵션 -c";;
*) echo "잘못된 옵션";;
esac
done

