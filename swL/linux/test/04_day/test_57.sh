#!/bin/bash

trap "echo ' CTRL+C'" SIGINT

for ((i=1; i<=5; ++i)); do
	echo "$i 초"
	sleep 1
done

# 트랩 제거 방법: trap -- 시그널

trap -- SIGINT

for ((; i<=10; ++i)); do
	echo "$i 초"
	sleep 1
done

