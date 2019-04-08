#if 1
#include <stdio.h>
#include <string.h>
int main()
{
	char buf[10];	
	fgets(buf, sizeof(buf)-1, stdin);
	buf[strlen(buf)-1] = 0;
	printf("[%s]\n", buf );
	return 0;
}
#endif

#if 0
#include <stdio.h>
int main()
{
	char buf[10];	
	gets(&buf);
	printf("[%s]\n", buf );
	return 0;
}
#endif
