read -p "정수 입력: "
i=0
sum=0
while true; do
let ++i
# i가 입력된 값보다 크면 루프를 빠져나갑니다.
if ((i > $REPLY)); then
break
fi

# i를 2로 나눈 나머지가 1인 경우, 홀수이므로
# 다음 명령을 실행하지 않고 다음 단계의 루프를 수행합니다.
if (( (i % 2) == 1 )); then
continue
fi
let sum+=i
done
echo "결과: $sum"

