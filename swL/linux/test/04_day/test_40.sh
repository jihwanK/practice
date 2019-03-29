animals=("dog" "cat" "fish")

# 윈소의 참조 방법: ${배열명[번호]}
echo ${animals[0]}
echo ${animals[1]}
echo ${animals[2]}

# 배열의 이름을 첫 번째 원소로 해석됨
echo $animals

# 별표를 사용하면 배열의 모든 원소를 하나의 문자열로 처리합니다.
echo ${animals[*]} 

# 초기화가 안된 원소는 빈 값으로 출력됩니다.
echo ${animals[100]} #

# 배열 원소의 개수를 출력하려면 @와 #을 조합해서 사용하면 됩니다.
echo ${#animals[@]}

