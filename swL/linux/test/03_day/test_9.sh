#!/bin/bash

# 단항 연산자도 제공한다.
# 변수를 증가시킨 다음 사용한다.
num=0
let ret=++num
printf "num = %d, ret = %d\n" $num $ret

# 변수를 사용한 다음 증가시킨다.
num=0
let ret=num++
printf "num = %d, ret = %d\n" $num $ret

# 변수를 감소시킨 다음 사용한다.
num=1
let ret=--num
printf "num = %d, ret = %d\n" $num $ret

# 변수를 사용한 다음 감소시킨다.
num=1
let ret=num--
printf "num = %d, ret = %d\n" $num $ret




