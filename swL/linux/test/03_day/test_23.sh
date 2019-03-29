#!/bin/bash
# ${string/#substring/replacement}: $substring이 $string의 맨 앞에서 일치하면 $replacement로 치환함
# ${string/%substring/replacement}: $substring이 $string의 맨 뒤에서 일치하면 $replacement로 치환함

str="abcABC123ABCabc"

echo ${str/#abc/---}          # ---ABC123ABCabc
# 맨 앞에서 일치하는 'abc'를 '---'로 치환합니다.

echo ${str/%abc/---}          # abcABC123ABC---
# 맨 뒤에서 일치하는 'abc'를 '---'로 치환합니다.


