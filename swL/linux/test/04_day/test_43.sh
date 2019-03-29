str="global"

func() {
	local str="local"   # str은 지역 변수입니다.
	echo $str           # local
	return
}

func
echo $str   # global

