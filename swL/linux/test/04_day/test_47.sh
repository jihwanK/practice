print_param() {
	echo \$*: $*
	echo \$@: $@
	echo
	echo '"$*" >'
	for arg in "$*"; do
		echo "$arg"
	done
	echo
	echo '"$@" >'
	for arg in "$@"; do
		echo "$arg"
	done
}
print_param "hi~" "hello, world" "bye" 

