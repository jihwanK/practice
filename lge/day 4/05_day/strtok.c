#include <stdio.h>
#include <string.h>
int main()
{
	char ip[] = "...192.----..168.137.---...100";
	char *p;

	p = strtok(ip, ".-");
	// strpbrk
	// strspn
	while(p)
	{
		printf("[%s]\n", p );
		p = strtok(0, ".-");
	}
	return 0;
}
