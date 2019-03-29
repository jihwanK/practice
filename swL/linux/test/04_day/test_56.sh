#!/bin/bash

trap "echo 스크립트가 종료되었습니다." EXIT

for ((i=1; i<=5; ++i)); do
    echo "Loop #$i"
    sleep 1
done
