#if 1
#include <stdio.h>
#include <setjmp.h>

jmp_buf env;
void foo()
{
	int flag = -1;
	printf("foo()\n");
	if( flag < 0 )
		longjmp( env, 1 );  // throw 1;
	printf("after\n");
}

int main()
{
	int ret;
	ret = setjmp(env);
	if( 0==ret )        // try
	{
		while(1)
			while(1)
				foo();
	}
	else if( ret == 1 )  // catch(1)
	{
		printf("catch 1 error\n");
	}
	return 0;
}
#endif

#if 0
#include <stdio.h>

void foo()
{
	int flag = -1;
	if( flag < 0 )
	   goto err;
}

int main()
{

	while(1)
	{
		while(1)
		{
			foo();
		}
	}
	return 0;
err:
	printf("error\n");
	return -1;
}
#endif

#if 0
#include <stdio.h>
int main()
{
	int flag = -1;

	while(1)
	{
		while(1)
		{
			if( flag < 0 )
				break;
		}
		if( flag < 0 )
			break;
	}
	if( flag < 0 )
		printf("error\n");
	return 0;
}
#endif
