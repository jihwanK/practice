#!/bin/bash

result=$[2 * 2]    # 곱셈 연산자에 백슬래시를 사용할 필요가 없다.
echo $result       # 4

result=$[2 ** 10]  # ** 연산자는 거듭제곱 연산자이다.
echo $result       # 1024

result=$[10 / 2]   # 나눗셈의 결과는 항상 자연수이다.
echo $result       # 5

result=$[5 % 3]
echo $result       # 2

var1=2
var2=2
result=$[var1 * var2]  # 변수를 사용할 수도 있다.
echo $result   # 4







