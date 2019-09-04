#!/bin/bash

# 공백을 사용하려면 큰 또는 작은 따옴표를 사용해야 한다.
let 'ret = 1 + 1'
echo "1 + 1 =" $ret
let "ret = 1 + 1"
echo "1 + 1 =" $ret

# 거듭제곱 연산자: 밑**지수
let ret=2**10   # 2의 10제곱을 의미한다.
echo "2 ** 10 =" $ret

# 복합 대입 연산자
num=0
let num+=2 # 변수에 2를 더한다.
echo $num

let num-=1 # 변수를 1를 뺀다.
echo $num

Num=2
let num*=2 # 변수에 2를 곱한다.
echo $num

let num/=2 # 변수를 2로 나눈다.
echo $num

num=4
let num%=3 # 변수를 3으로 나눈 나머지를 대입한다.
echo $num



