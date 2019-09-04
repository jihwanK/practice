#!/bin/bash
read word1 word2 word3
echo $word1 $word2 $word3

# REPLY라는 내장 변수를 사용할 수 있다.
read
echo $REPLY

# p 옵션을 사용하면 화면 상에 프롬프트를 출력할 수 있다.
read -p "name: "
echo $REPLY

read -p "name: " name
echo $name
