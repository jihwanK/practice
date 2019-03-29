function print_hello {
    echo "hello"
    return
}

print_world() {
    echo "world"
}

# 함수를 호출하는 방법은 함수명을 그냥 적으면 됩니다. 
print_hello
print_world
