arr=(0 1 2 3 4 5 6 7 8 9)
echo ${arr[*]}

unset arr[5]
echo ${arr[*]}

unset arr
echo ${arr[*]}
