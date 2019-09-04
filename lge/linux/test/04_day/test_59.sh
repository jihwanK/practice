#!/bin/bash

read -p "양수 입력: "

if (($REPLY <= 0)); then
  exit 1
fi

#export PS4='+(${BASH_SOURCE[0]}:${LINENO}): ${FUNCNAME[0]:+${FUNCNAME[0]}(): }'
set -x # 디버깅 설정
#-----------------------------
  total=0
  for ((i=1; i<$REPLY; ++i)); do
    ((total+=i))
  done
#-----------------------------
set +x # 디버깅 해제
echo "총합: $total"
