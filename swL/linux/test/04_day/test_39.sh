# 소괄호를 사용하여 배열을 선언     [0]   [1]   [2]    [3]
arr1=(1024  "one" $(pwd) $USER)

# 대괄호를 사용하여 임의의 번호를 할당 가능
arr2=([10]="zero" [0]="one" [33]="two")

# 대괄호를 사용하여 배열을 선언
arr3[0]="zero"
arr3[1]="one"
arr3[2]="two"

for i in 0 1 2; do
	echo ${arr3[$i]}
done
