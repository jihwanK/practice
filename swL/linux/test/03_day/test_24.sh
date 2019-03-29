#!/bin/bash

read -p "input number: "

if test $REPLY -eq 0    # REPLY == 0
then
    echo "number is zero"
fi # 인터프리터이므로 if의 끝을 알려주어야 하며 fi라는 키워드를 사용합니다.

if test $REPLY -ne 0    # REPLY != 0
then
    echo "number is not zero"
fi
