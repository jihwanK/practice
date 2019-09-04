#include <time.h>
#include <stdio.h>
int main()
{
	time_t now;
	struct tm *tmp;
	char *str;
	now = time(0);
	printf("now=%lu\n", now );
	str = ctime( &now );
	printf("%s\n", str );
	tmp = localtime(&now);
	printf("%d %d %d %02d:%02d:%02d\n", 
			tmp->tm_year+1900, tmp->tm_mon+1, tmp->tm_mday,
			tmp->tm_hour, tmp->tm_min, tmp->tm_sec );
	return 0;
}
