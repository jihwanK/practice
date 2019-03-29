# while 조건식
# do
#   명령어
# done
cnt=1
while (( $cnt <= 5 ))
do
	printf "%d: hello, world\n" $cnt
	let ++cnt
done

cnt=1
while (( cnt <= 5 )); do  # 세미콜론을 사용하여 한 줄로 처리할 수 있습니다.
	printf "%d: hello, world\n" $cnt
	let ++cnt
done

# bash에서는 참과 거짓을 표현하기 위해 true와 false를 제공합니다.
#cnt=1
#while true; do
#	printf "%d: hello, world\n" $((cnt++))
#done

