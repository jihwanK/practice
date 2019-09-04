#if 1
#include <stdio.h>
#define BIT_SET( index, x )  (x[index/32] |= 1<<(index%32))
#define BIT_ISSET( index, x) (x[index/32] & ( 1<<(index%32) ) )
#define BIT_CLR(index,x )    (x[index/32] &= ~(1<<(index%32)))
#define BIT_ZERO(x)          do{ int i;                    \
                                 for( i=0; i<32; i++ )     \
							        x[i] = 0; } while(0)
typedef  int bit_set[32];
//-----------------------------------------------------------
int main()
{
	bit_set item;
	int i;
	BIT_ZERO( item );
	BIT_SET( 700, item );
	BIT_SET( 800, item );

	for( i=0; i<1024; i++ )
		if( BIT_ISSET(i,item) )
			printf("%d\n", i );

	printf("----------\n");
	BIT_CLR(800,item);
	for( i=0; i<1024; i++ )
		if( BIT_ISSET(i,item) )
			printf("%d\n", i );
	return 0;
}
#endif

#if 0
#include <stdio.h>
int main()
{
	int item[32] = {0,};
	int i;
	item[700/32] |= 1<<(700%32);
	item[800/32] |= 1<<(800%32);

	for( i=0; i<1024; i++ )
		if( item[i/32] & ( 1<<(i%32) ) )
			printf("%d\n", i );

	printf("----------\n");
	item[800/32] &= ~(1<<(800%32));
	for( i=0; i<1024; i++ )
		if( item[i/32] & ( 1<<(i%32) ) )
			printf("%d\n", i );
	return 0;
}
#endif
#if 0
#include <stdio.h>
int main()
{
	int item = 0;
	int i;
	item |= 1<<0;
	item |= 1<<3;

	for( i=0; i<4; i++ )
		if( item & ( 1<<i ) )
			printf("%d\n", i );

	printf("----------\n");
	item &= ~(1<<3);
	for( i=0; i<4; i++ )
		if( item & ( 1<<i ) )
			printf("%d\n", i );
	return 0;
}
#endif
#if 0
#include <stdio.h>
int main()
{
	int item = 0;
	int i;
	item = item | 1;
	item = item | 8;

	for( i=0; i<4; i++ )
		if( item & ( 1<<i ) )
			printf("%d\n", i );

	printf("----------\n");
	item = item & ~8;
	for( i=0; i<4; i++ )
		if( item & ( 1<<i ) )
			printf("%d\n", i );
	return 0;
}
#endif
#if 0
#include <stdio.h>
int main()
{
	int item[4] = {0,};
	int i;
	item[0] = 1;
	item[3] = 1;

	for( i=0; i<4; i++ )
		if( item[i] )
			printf("%d\n", i );

	printf("----------\n");
	item[3] = 0;
	for( i=0; i<4; i++ )
		if( item[i] )
			printf("%d\n", i );
	return 0;
}
#endif
