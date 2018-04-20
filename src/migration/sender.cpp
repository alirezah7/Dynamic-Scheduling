#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "sender.h"

sender::sender(char* ip, int port)
{
	IP = ip;
	PORT = port;
	sock = CreateSocket();
	ClientConnect();
}

void sender::SendBySocket(char *msg)
{
	send(sock , msg , strlen(msg) , 0 );
	printf("Hello message sent\n");
	valread = read( sock , buffer, 1024);
	printf("%s\n",buffer );
}


int sender::CreateSocket()
{
	memset(&serv_addr, '0', sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	serv_addr.sin_addr.s_addr = inet_addr(IP);

	return socket(AF_INET, SOCK_STREAM, 0);
}

void sender::ClientConnect()
{
	connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
}