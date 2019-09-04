#include <sys/types.h>       
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h> 
#include <signal.h> 
#include <sys/wait.h> 
#include <pthread.h> 
#include <poll.h>

int cli_count = 0;

int main()
{
	int s_sock = socket(PF_INET, SOCK_STREAM, 0);
	int option = 1;
	struct pollfd fds[4096];
	int nfds = 1;

	struct sockaddr_in saddr = {0, };
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(7777);
	//saddr.sin_addr.s_addr = INADDR_ANY;
	saddr.sin_addr.s_addr   = inet_addr("192.168.137.100");

	setsockopt(s_sock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof option);

	if (bind(s_sock, (struct sockaddr*)&saddr, sizeof saddr) == -1)
	{
		perror("bind");
		return -1;
	}

	listen(s_sock, SOMAXCONN);

	fds[0].fd = s_sock;
	fds[0].events = POLLIN;

	while(1)
	{
		int ret = poll(fds, nfds, -1);
		int count = nfds;
		int compress = 0;

		if (ret == 0)
			continue;

		for (int i = 0; i < count; i++)
		{
			if (!(fds[i].revents & POLLIN))
				continue;

			if (fds[i].fd == s_sock)
			{
				struct sockaddr_in c_addr = {0, };
				socklen_t addrlen = sizeof c_addr;
				int c_sock = accept(s_sock, (struct sockaddr*)&c_addr, &addrlen);

				if (c_sock < 0)
					perror("accept");

				fds[nfds].fd = c_sock;
				fds[nfds].events = POLLIN;
				nfds++;
				cli_count++;

				printf("client ip=%s port=%d the number of current clients=%d \n", inet_ntoa(c_addr.sin_addr), ntohs(c_addr.sin_port), cli_count);
			}
			else 
			{
				int c_sock = fds[i].fd;
				char buf[1024];
				int len = read(c_sock, buf, sizeof buf);

				if (strcmp(buf, "quit") == 0 || len == 0 || len == -1)
				{
					close(c_sock);
					fds[i].fd = -1;
					nfds--;
					cli_count--;
					compress = 1;
					printf("the connection terminates successfully, the number of current clients=%d\n", cli_count);

					for (int j = 1; j < cli_count; j++)
						write(fds[j].fd, "the connection terminates successfully, the number of current clients=%d\n", cli_count);
					
					continue;
				}
				else
				{
					write(1, buf, len);
					for (int j = 1; j < cli_count; j++)
						write(fds[j].fd, buf, len);
				}
			}
		}

		if (compress)
		{
			compress = 0;
			for(int i = 0; i < nfds; i++)
			{
				if (fds[i].fd == -1)
				{
					for(int j = i; j < nfds; j++)
						fds[j] = fds[j + 1];
					i--;
					nfds--;
				}
			}
		}
	}

	close(s_sock);
}
