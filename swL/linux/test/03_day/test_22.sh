#!/bin/bash

# 3. 뒤에서부터 가장 짧게 일치하는 부분 문자열을 삭제
# ${변수%부분문자열}

# 4. 뒤에서부터 가장 길게 일치하는 부분 문자열을 삭제
# ${변수%%부분문자열}

str="123ABCEFABCDEF"
#            |----|
#       |---------|

echo ${str%A*F}
echo ${str%%A*F}

# 처음 일치하는 부분문자열을 치환문자열로 치환함
# ${문자열/부분문자열/치환문자열}

# 일치하는 모든 부분문자열을 치환문자열로 치환함
# ${문자열//부분문자열/치환문자열}

str="xyzABC123ABCxyz"

echo ${str/ABC/***}
echo ${str//ABC/***}



