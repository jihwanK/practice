#if 1
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
int global=10;
int temp;
int main()
{
	int *p = malloc(sizeof(int));
	printf("main=%p\n", main);
	printf("global=%p\n", &global);
	printf("temp=%p\n", &temp);
	printf("p=%p\n", p);
	printf("&p=%p\n", &p);
	free(p);
	return 0;
}
#endif

#if 0
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
int main()
{
	int fd;
	int ret;
	char buff[1024];
	char *p;
	fd = open( "aaa", O_RDWR | O_CREAT | O_TRUNC, 0666);
	ftruncate(fd, 4096);
	p = mmap( 0, 4096, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	printf( "p=%p\n", p );
	strcpy( p, "world" );
	printf("[%s]\n" , p );
	getchar();
	close(fd);
	return 0;
}
#endif

#if 0
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
int main()
{
	int fd;
	int ret;
	char buff[1024];
	fd = open( "aaa", O_RDWR|O_CREAT|O_TRUNC, 0666);
	write( fd, "hello", 5 );
	lseek(fd, 0, SEEK_SET);
	ret = read( fd, buff, sizeof buff );
	buff[ret] = 0;
	printf("[%s]\n", buff );
	close(fd);
	return 0;
}
#endif
