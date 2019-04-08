#if 1
#include <stdio.h>
#define  htons(x) (((x>>8)&0xff) | ((x<<8)&0xff00))
int main()
{
	short port = 0x1234;
	char *p = (char*)&port;
	printf("%x%x\n", p[0], p[1]);
	port = htons(port);
	printf("%x%x\n", p[0], p[1]);
	return 0;
}
#endif
#if 0
#include <stdio.h>
int main()
{
	short port = 0x1234;
	char *p = (char*)&port;
	printf("%x%x\n", p[0], p[1]);
	port = ((port>>8)&0xff) | ((port<<8)&0xff00);
	printf("%x%x\n", p[0], p[1]);
	return 0;
}
#endif

#if 0
#include <stdio.h>
int main()
{
	int ip = 0x12345678;
	char *p = (char*)&ip;
	printf("%x%x%x%x\n", p[0], p[1], p[2], p[3]);
	return 0;
}
#endif
