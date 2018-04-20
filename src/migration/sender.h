#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#ifndef SENDER_H
#define SENDER_H

class sender
{
	public:
		int valread;
		char buffer[1024] = {0};

	private:
		struct sockaddr_in serv_addr;
		int sock;
		char* IP;
		int PORT;

	public:
		sender(char* ip, int port);
		void SendBySocket(char *msg);

	private:
		int CreateSocket();
		void ClientConnect();

};

#endif
