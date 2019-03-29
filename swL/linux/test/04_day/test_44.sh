#!/bin/bash
display() {
# $0: 스크립트의 이름이 저장됩니다.
	echo $0

# 함수 사용 시, 전달된 값이 순서대로 저장됩니다.
	echo $1 $2 $3

# 값이 저장된 매개 변수의 개수를 #변수에 저장됩니다.
# (0번 매개변수는 제외)
	echo $#
}

#       $1      $2       $3
display "apple" "orange" "banana"

