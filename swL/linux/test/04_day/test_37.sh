# for variable in list; do
#    commands
# done

for i in 1 2 3 4 5 6 7 8 9; do
echo "$i: hello, world"
done

# 리스트에 문자열 집합도 사용 가능
fruits="apple orange banana mango"
for i in $fruits
do
echo $i
done

# 리스트에 명령어 치환도 사용이 가능
for i in $(cat test_36.sh)
do
echo $i
done

