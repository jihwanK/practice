#!/bin/bash

# $ ./test_51.sh a b c d e f g h i j

count=1
while [ -n "$1" ]; do
  	printf "%d번 위치 매개변수: %s\n" $count $1
   	let ++count
	shift
done
