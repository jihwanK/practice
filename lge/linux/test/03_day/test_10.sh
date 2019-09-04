#!/bin/bash

# 비교 연산자도 사용 가능하다.
# 동등 비교를 제외한 나머지 연산자에 대해서는 반드시 백슬래시나 따옴표를 사용해>야 한다.
let ret=2\>0
echo $ret

let ret=2"<"0
echo $ret

let ret=2'>='0
echo $ret

# 아니면 전체 식에 대하여 따옴표를 사용해도 된다.
let "ret = 2 <= 0"
echo $ret

let ret=2!=0
echo $ret

let ret=2==0
echo $ret





