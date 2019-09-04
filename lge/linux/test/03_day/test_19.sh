#!/bin/bash
# 문자열 길이 계산: expr length 문자열
expr length "hello"

# 발견된 특정 문자의 위치 계산
# expr index 문자열 특정문자들

# 색인의 값은 1부터 시작합니다.
# 만약 일치하는 문자가 없으면 0을 반환합니다.
#           12345
expr index "hello" "oe"
expr index "hello" "xyz"

# 부분 문자열 추출 연산
# expr substr 문자열 시작위치 길이

# 문자열에서 시작 위치는 1입니다.
#    1
str="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
echo $(expr substr $str 2 4)


