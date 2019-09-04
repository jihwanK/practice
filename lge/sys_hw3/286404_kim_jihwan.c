#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

typedef struct info {
	int argc;
	char** argv;
} INFO;

INFO* parse_option(char* command) {
	int i = 0;
	int flag = 0;
	int argc = 1;

	while (command[i] != '\0') {
		if (command[i] == ' ')
			argv++;
	}
}


int main(void) {
	char command[100];
	pid_t pid;

	while(1) {
		printf("[/root] > ");
		scanf("%s", command);
	
		pid = fork();
		if (pid == 0) {
			execlp(command, "", 0);
			exit(0);
		}

		wait(0);
	}
	return 0;
}
