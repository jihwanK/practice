#!/bin/bash
set -x

file_count=0
dir_count=0
for i in $(ls)  
do
	if [ -f $i  ]; 
	then
		let ++file_count
	fi
	if [ -d $i  ]; 
	then
		let ++dir_count
	fi
done

echo -n "파일수 : "$file_count
echo " 디렉토리수 : "$dir_count
