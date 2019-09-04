#if 1
#include <stdio.h>
#include <unistd.h>
int main()
{
	char *argv[] = { "newpgm", "parm1", "param2", "param3", (char *)0};
	char *envp[] = { "name=kji", "addr=seoul", (char *)0};
	printf("this is the original program\n");
	execve("./newpgm", argv,  envp);
	printf("This line should never get printed\n");
}
#endif
#if 0
#include <stdio.h>
#include <unistd.h>
int main()
{
	printf("this is the original program\n");
	execl("ls", "ls", "-l", "-a", "-i", (char *) 0 );
	printf("This line should never get printed\n");
}
#endif
#if 0
#include <stdio.h>
#include <unistd.h>
int main()
{
	printf("this is the original program\n");
	execl("./newpgm", "newpgm", "parm1", "parm2", "parm3", (char *) 0 );
	printf("This line should never get printed\n");
}
#endif
