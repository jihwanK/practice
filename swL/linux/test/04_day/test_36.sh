# 조건식이 거짓이면 루프를 수행합니다.
# 즉, 조건이 참이 될 때까지 루프를 수행합니다.
i=1
until (( i > 5 )); do
let ++i
echo "hello, world"
done

