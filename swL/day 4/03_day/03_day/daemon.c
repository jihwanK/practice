#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

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
static int klog_fd = -1;
void klog_init(void) {
	if (klog_fd >= 0) return; /* Already initialized */

	static const char* name = "__kmsg__";
	if (mknod(name, S_IFCHR | 0600, (1 << 8) | 11) == 0) {
		klog_fd = open(name, O_WRONLY | O_CLOEXEC);
		unlink(name);
	}
}

int daemon_init(void){
	pid_t   pid;
	int i;
	if(fork() > 0)
		exit(0); 
	setsid();               /* become session leader */
	chdir("/");             /* change working directory */
	umask(0);               /* clear our file mode creation mask */

	for(i=0;i<64;i++)
		close(i);
	signal(SIGCLD,SIG_IGN);
	return(0);
}

int main()
{
	daemon_init();
	open_devnull_stdio();
	klog_init();
	write( klog_fd, "hello world\n", 12 );
	while(1)
	{
		;
	}
	return 0;
}
