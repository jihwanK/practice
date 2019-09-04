read -p "양수 입력: "
if (($REPLY <= 0)); then
exit 1
fi

total=0
for ((i=1; i<$REPLY; ++i)); do
	((total+=i))
done

echo "총합: $total"
