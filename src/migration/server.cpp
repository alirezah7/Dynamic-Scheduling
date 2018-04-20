#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "server.h"


server::server(char* ip, int port)
{
	IP = ip;
	PORT = port;
	sock = CreateSocket();
	ServerBinding();
	Listen();
	Ready();
}


int server::CreateSocket()
{
	memset(&serv_addr, '0', sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	serv_addr.sin_addr.s_addr = inet_addr(IP);

	int server_fd = socket(AF_INET, SOCK_STREAM, 0);
	setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

	return server_fd;
}

void server::ServerBinding()
{
	bind(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
}

void server::Listen()
{
	listen(sock, 3);
}

void server::Ready()
{
	char *hello = "msg recieved";
	while(1)
	{
		new_sender = accept(sock, (struct sockaddr *)&serv_addr, (socklen_t*)&addrlen);
		valread = read(new_sender , buffer, 2500);
		printf("%s\n",buffer);

		send(new_sender , hello , strlen(hello) , 0 );
		close(new_sender);
	}
}
