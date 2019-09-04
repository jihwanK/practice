#!/bin/bash

result=$(expr 2 + 2) # 수식 결과를 변수에 할당하려면 명령 치환($())을 사용해야 >한다.
echo $result

var1=2
var2=2
result=$(expr $var1 \* $var2) # *를 와일드카드가 아닌 단순 문자로 처리될 수 있도록
                              # 백슬래시나 따옴표를 사용한다.
echo $result






