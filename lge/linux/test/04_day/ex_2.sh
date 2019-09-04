#!/bin/bash
set -x

year=`date +%y`
month=`date +%m`
day=`date +%d`

touch  "$1.$year$month$day"
