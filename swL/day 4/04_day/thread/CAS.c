#include <stdio.h>
int __bionic_cmpxchg(int old_value, int new_value, volatile int* ptr)
{
	int prev, status;
	do {
		__asm__ __volatile__ (
				"ldrex %0, [%3]\n"
				"mov %1, #0\n"
				"teq %0, %4\n"
				"strexeq %1, %5, [%3]"
				: "=&r" (prev), "=&r" (status), "+m"(*ptr)
				: "r" (ptr), "Ir" (old_value), "r" (new_value)
				: "cc");
	} while (__builtin_expect(status != 0, 0));
	return prev != old_value;
}

int flag=0;

void spin_lock( int *flag )
{
	while( __bionic_cmpxchg(0, 1, flag) );
}

int main()
{
	int ret;
	//ret = __bionic_cmpxchg(0, 1, &flag);
	//printf("flag=%d, ret=%d\n", flag, ret );
	spin_lock( &flag );
	printf("임계영역 진입\n");
	spin_lock( &flag );
	printf("임계영역 진입\n");
	return 0;
}
