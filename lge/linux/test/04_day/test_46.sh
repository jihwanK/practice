display1() {
    while [ -n "$1" ]; do
        echo -n "$1 "
        shift
    done
    echo
}

name1="daniel"
name2="susan"
name3="joshep"

# 변수명을 사용하면 단순 문자열로 처리됩니다.
display1 name1 name2 name3          # name1 name2 name3

# 값을 전달하려면 반드시 $연산자를 사용해야 합니다.
display1 $name1 $name2 $name3       # daniel susan joshep

