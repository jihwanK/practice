#if 1
#include <stdio.h>
int main()
{
	//int i=0xffffffff;
	int i=0xff;
	printf("%d\n", i );
	return 0;
}
#endif
#if 0
#include <stdio.h>
typedef struct
{
	int b1:1;
} BIT;
int main()
{
	BIT bit;
	bit.b1 = 1;
	// 1
    // 1
	// -1

	printf("%d\n", bit.b1 );
	return 0;
}
#endif
#if 0
#include <stdio.h>
typedef struct
{
	int b1:2;
} BIT;
int main()
{
	BIT bit;
	bit.b1 = 2;
	// 10
	// 10 
	// -2

	if( bit.b1 == 2 )
		printf("%d\n", bit.b1 );
	return 0;
}
#endif

#if 0
#include <stdio.h>
int main()
{
	int i=0xfffffffe; 
	// 1111111111111111111111111111110
	// 0000000000000000000000000000010
	// -2
	printf("%d\n", i );
	return 0;
}
#endif

#if 0
#include <stdio.h>
int main()
{
	short s=0xfffc; // 1111 1111 1111 1100
	                // 0000 0000 0000 0011
	                // 0000 0000 0000 0100
	                // -4
	printf("%d\n", s );
	return 0;
}
#endif

#if 0
#include <stdio.h>
int main()
{
	signed char ch=250;
	printf("%d\n", ch );
	return 0;
}
#endif
