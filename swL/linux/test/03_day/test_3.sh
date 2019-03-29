#!/bin/bash
name="daniel"   # 대입 연산자의 앞과 뒤에 공백이 없어야 한다.
echo name       # name, 변수명을 그냥 사용하면 문자열로 인식한다.
echo $name      # daniel
echo ${name}    # daniel, 중괄호를 사용할 수도 있다.
echo "$name"    # daniel
echo '$name'    # $name
echo "'$name'"  # 'daniel'
echo \$name     # $name 


# 명령어의 결과를 변수에 저장할 수 있다.
str=`date`
echo $str

str=$(pwd)
echo $str

