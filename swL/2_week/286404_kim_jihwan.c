#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char** argv) {
	int fd_r;
	int ret;
	char buff[100];
	
	int i = 1;
	int fd_w[100];

	while(i < argc) {
		fd_w[i] = open(argv[i], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		i++;
	}

	while(ret = read(0, buff, sizeof(buff))) {
		write(1, buff, ret);
		for (int k = 1; k < argc; k++) {
			write(fd_w[k], buff, ret);
		}
	}

	for (int k = 0; k < argc; k++) {
		close(fd_w[k]);
	}

	return 0;
}
