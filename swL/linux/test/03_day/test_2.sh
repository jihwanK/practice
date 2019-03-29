#!/bin/bash
echo "hello, world" # echo 명령은 기본적으로 개행을 한다.
echo -n "hello, world"  # -n 옵션을 사용하면 개행을 하지 않는다.
echo hello, world # 단순 문자열인 경우, 따옴표를 사용하지 않아도 된다.
printf "hello, world\n"  # \n은 개행을 하라는 의미
# USER 변수 출력
echo "USER:" $USER", HOME:" $HOME
printf "USER: $USER, HOME: $HOME\n"
printf "USER: %s, HOME: %s\n" $USER $HOME
# printf 포멧 스트링
printf "age: %d\n" "18" # %d: 10진수로 출력
printf "name: %s\n" "daniel" # %s: 문자열로 출력
printf "name: %s, age: %d\n" "daniel" 19
printf "PI: %f\n" 3.14 # %f: 부동소수점으로 출력

