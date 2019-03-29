display() {
	local count=$1
	if (( count == 0 )); then
		return 0
	fi
	echo $2
	count=$(( count - 1 ))
	display $count "$2"
}
display 3 hello

