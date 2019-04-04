#if 0
#include <stdio.h>

typedef  void FUNC(void);
typedef  FUNC* FUNC_P;
//--------------------------------------------
void aaa(void)
{
	printf("aaa()\n");
}
FUNC_P bbb(FUNC_P p)  
{
	p();
	printf("bbb()\n");
	return aaa;
}
//------------------------------------

int main()
{
	bbb(aaa)();
	return 0;
}
#endif
#if 0
#include <stdio.h>

void aaa(void)
{
	printf("aaa()\n");
}
void (*bbb(void(*p)(void)))(void)  
{
	p();
	printf("bbb()\n");
	return aaa;
}
//------------------------------------

int main()
{
	bbb(aaa)();
	return 0;
}
#endif
#if 0
#include <stdio.h>

void aaa(void)
{
	printf("aaa()\n");
}
void (*bbb(void))(void)  
{
	printf("bbb()\n");
	return aaa;
}
//------------------------------------

int main()
{
	bbb()();
	return 0;
}
#endif
#if 0
#include <stdio.h>

void aaa(void)
{
	printf("aaa()\n");
}
void (*)(void)  bbb(void)
{
	printf("bbb()\n");
	return aaa;
}
//------------------------------------

int main()
{
	bbb()();
	return 0;
}
#endif
#if 0
#include <stdio.h>

void bbb(void (*p)(void))
{
	p();
	printf("bbb()\n");
}
//------------------------------------
void aaa(void)
{
	printf("aaa()\n");
}

int main()
{
	bbb(aaa);
	return 0;
}
#endif
#if 0
#include <stdio.h>

void foo(void)
{
	printf("foo()\n");
}

int main()
{
	void (*p)(void) = foo;
	p();
	// foo();
	return 0;
}
#endif

#if 0
#include <stdio.h>

void foo(void)
{
	printf("foo()\n");
}

int main()
{
	void (*p)(void) = &foo;
	(*p)();
	return 0;
}
#endif
#if 0
#include <stdio.h>

void foo(void)
{
	printf("foo()\n");
}

int main()
{
	void *p(void) = &foo;
	return 0;
}
#endif
#if 0
#include <stdio.h>

void foo(void)
{
	printf("foo()\n");
}

int main()
{
	void (void) *p = &foo;
	return 0;
}
#endif
#if 0
#include <stdio.h>

void foo(void)
{
	printf("foo()\n");
}

int main()
{
	foo;
	return 0;
}
#endif

#if 0
#include <stdio.h>

void foo(void)
{
	printf("foo()\n");
}

int main()
{
	int a[2];
	a[1] = 10;
	*(a+1) = 10;
	foo();  //  0x1043c;
	10;   //  10;
	return 0;
}
#endif
