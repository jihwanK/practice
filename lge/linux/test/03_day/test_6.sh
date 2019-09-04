#!/bin/bash

declare -i x

x=2#1111    # 2진수
echo $x     # 15

x=8#17      # 8진수
echo $x     # 15

x=16#f      # 16진수, 소문자 f대신 대문자 F 사용 가능하다.
echo $x     # 15

