# 사용방법: trap 명령어 시그널
# 명령어는 큰 따옴표나 작은 따옴표를 사용해야 합니다.
# 시그널은 1개 이상 사용이 가능합니다.

trap "echo ' CTRL + C'" SIGKILL

for ((i=1; i<=100; ++i)); do
  echo "Loop #$i"
  sleep 1
done
