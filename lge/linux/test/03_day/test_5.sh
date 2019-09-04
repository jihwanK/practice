#!/bin/bash
declare -i age=0
echo $age

age=10         # 대입도 가능하다.
echo $age      # 10

#age="daniel"   # unbound variable 오류로 스크립트가 종료된다.
#echo $age

age=3.14       # syntax error: invalid arithmetic operator (error token is ".14")
echo $age      # 빈 문자열이 출력된다.

declare -i result=0
result=5+5     # 표현식에 공백을 사용할 수 없다. 5 + 5는 오류
echo $result   # 10

result="5 + 5" # 큰 따옴표를 사용하면 공백은 분리자로 사용되지 않으므로 사용 가>능하다.
echo $result   # 10

declare -i n1=1
declare -i n2=1
result=$n1+$n2 # 변수를 사용하여 연산을 할 수 있다.
echo $result   # 2

