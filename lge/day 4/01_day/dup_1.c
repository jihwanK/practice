#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
// # ls > xxx
// ./a.out xxx
int main(int argc, char **argv)
{
	int fd;
	fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0666);

	close(1);  // 표준 출력을 닫는다.
	dup(fd);   // 파일 디스크립터를 표준 출력에 복제 한다.

	printf("hello\n"); // 출력이 파일로 나간다.
	close(fd);

	return 0;
}

