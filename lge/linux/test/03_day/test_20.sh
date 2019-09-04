#!/bin/bash

# 문자열 길이 계산
# ${#변수}

#    12345
str="hello"
echo ${#str}

# 부분 문자열 추출
# ${변수:시작위치:길이}

# 문자열의 시작은 0입니다.
#    0123456789...
str="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
echo ${str:0:4}

# 길이를 명시하지 않으면 문자열 끝까지 추출합니다.
echo ${str:23}


