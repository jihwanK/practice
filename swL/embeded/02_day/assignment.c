int main()
{
	int ssock = socke(PF_INET, SOCK_STREAM, 0);

	strcut sockaddr_in saddr = {0, };
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(7777);
	saddr.sin_addr.s_addr = INADDR_ANY;

	int option = 1;

	setsockopt(ssock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof option);

	if (bind(ssock, (struct sockaddr*)&saddr, sizeof saddr) == -1)
	{
		perror("bind");
		return -1;
	}

	listen(ssock, SOMAXCONN);

	struct pollfd fds[4096];
	int nfds = 1;

	fds[0].fd = sscok;
	fds[0].events = POLLIN;

	while(1)
	{
		int ret = poll(fds, nfds, -1);
		if (ret == 0)
			continue;

		int count = nfds;
		int compress = 0;

		for (int i = 0; i < count; i++)
		{
			if (!(fds[i].revent & POLLIN))
				continue;

			if (fds[i].fd == ssock)
			{
				struct sockaddr_in c_addr = {0, };
				socklen_t addrlen = sizeof c_addr;
				int c_sock = accept(ssock, (struct sockaddr*)&c_addr, &addrlen);

				fds[nfds].fd = c_sock;
				fds[nfds].events = POLLIN;
				nfds++;
			}
			else 
			{
				int c_sock = fds[i].fd;
				char buf[1024];
				int len = read(c_sock, buf, sizeof buf);
				if (len == 0 || len == -1)
				{
					close(c_sock);
					fds[i].fd = -1;
					compress = 1;
					continue;
				}

				write(c_sock, buf, len);
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
					{
						fds[j] = fds[j + 1];
					}
					i--;
					nfds--;
				}
			}
		}
	}

	close(ssock);
}
			}
			}
