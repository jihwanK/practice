#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void open_devnull_stdio(void)
{
	int fd;
	static const char *name = "__null__";
	if (mknod(name, S_IFCHR | 0600, (1 << 8) | 3) == 0) {
		fd = open(name, O_RDWR);
		unlink(name);
	}

	dup2(fd, 0);
	dup2(fd, 1);
	dup2(fd, 2);
	if (fd > 2) {
		close(fd);
	}
}

int main()
{
	open_devnull_stdio();
	printf("hello\n");
	return 0;
}
