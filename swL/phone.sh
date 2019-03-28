#!/bin/bash

cnt=0
names=()
phone_numbers=()

function register {
	read -p "이름: " name
	
	if [ -z $name ]; then
		echo "이름을 입력하지 않았습니다. 아무 키나 누르세요..."
		return
	fi
	
	for ((idx=0; idx<cnt; idx++)); do
		if [ $name=${names[$idx]} ]; then
			echo "이미 존재하는 이름입니다. 아무 키나 누르세요..."
			return
		fi
	done
	
	names[$cnt]=$name

	read -p "전화번호: " number
	phone_numbers[$cnt]=$number

	((cnt+=1))

	echo "등록되었습니다. 아무 키나 누르세요..."
}

function search {	
	read -p "이름: " s_name	
		
	if [ -z $s_name ]; then
		echo "이름을 입력하지 않았습니다. 아무 키나 누르세요..."
		return
	fi

	for ((idx=0; idx<cnt; idx++)); do
		if [ $s_name=$names[$idx] ]; then
			echo ${names[$idx]} ${phone_numbers[$idx]}
			echo "아무 키나 누르세요..."
			return
		fi
	done

	echo "그런 이름은 없습니다. 아무 키나 누르세요..."
}

function delete {
	read -p "이름: " d_name
	
	if [ -z $d_name ]; then
		echo "이름을 입력하지 않았습니다. 아무 키나 누르세요..."
		return
	fi

	for ((idx=0; idx<cnt; idx++)); do
		if [ $d_name=${names[$idx]} ]; then
			unset names[$idx]
			unset phone_numbers[$idx]
			((cnt-=1))
			echo "삭제되었습니다. 아무 키나 누르세요..."
			return
		fi
	done

	echo "그런 이름은 없습니다. 아무 키나 누르세요..."
}

while true;
do
	echo "1. 등록"
	echo "i. 검색"
	echo "3. 삭제"
	read -p "입력(0. 종료): "

	case $REPLY in
	1) register
	read
	;;
#exit;;
	2) search
	read
	;;
#exit;;
	3) delete
	read
	;;
#exit;;
	0) exit;;
#exit;;
	esac
done

