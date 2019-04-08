#if 1
#include <stdio.h>

#define my_ffz(x)  my_ffs(~(x))

int my_ffs(int word)
{
	int num = 0;
	// O(logN)
	if ((word & 0xffff) == 0) {
		num += 16;
		word >>= 16;
	}
	if ((word & 0xff) == 0) {
		num += 8;
		word >>= 8;
	}
	if ((word & 0xf) == 0) {
		num += 4;
		word >>= 4;
	}
	if ((word & 0x3) == 0) {
		num += 2;
		word >>= 2;
	}
	if ((word & 0x1) == 0)
		num += 1;
	return num;
}

int main()
{
	int bitmap=0;  
	//int bitmap=0x80000000;  
	int index;
	if( bitmap )
	{
		index = my_ffs(bitmap);
		printf("index=%d\n", index );
	}
	else
		printf("세팅된 비트가 없습니다.\n");
	return 0;
}
#endif

#if 0
#include <stdio.h>

#define my_ffz(x)  my_ffs(~(x))

int my_ffs(int word)
{
	int num = 0;
	// O(logN)
	if ((word & 0xffff) == 0) {
		num += 16;
		word >>= 16;
	}
	if ((word & 0xff) == 0) {
		num += 8;
		word >>= 8;
	}
	if ((word & 0xf) == 0) {
		num += 4;
		word >>= 4;
	}
	if ((word & 0x3) == 0) {
		num += 2;
		word >>= 2;
	}
	if ((word & 0x1) == 0)
		num += 1;
	return num;
}

int main()
{
	int bitmap=0xf;  // 000000000000001111
	int index;
	index = my_ffz(bitmap);
	printf("index=%d\n", index );
	return 0;
}
#endif
