#!/bin/bash

trap_msg() {
	  echo " CTRL + C"
}

trap 'trap_msg' SIGINT

for ((i=1; i<=10; ++i)); do
    echo "Loop #$i"
    sleep 1
done
