#!/bin/bash

echo $(echo "scale=4; 3.44 / 5" | bc) # 세미콜론을 사용하면 여러 명령을 한 번에 전달
                                      # 가능하다.

var1=100
var2=45
echo $(echo "scale=4; $var1 / $var2" | bc) # 변수를 전달할 수도 있다.

# here document를 사용해도 된다.
bc << EOF
scale=4
3.44 / 5
EOF

# 계산기 내부에서 스크립트 상의 변수를 참조할 경우
# 반드시 달러를 사용해야 한다.
radius=2
echo $(bc << EOF
		scale=5
		3.14 * $radius * $radius
		EOF
	  ) 









