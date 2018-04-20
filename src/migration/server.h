#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#ifndef SERVER_H
#define SERVER_H

class server
{
	public:
		int valread;
		char buffer[1024] = {0};

	private:
		int new_sender;
		int addrlen = sizeof(serv_addr);
		int opt = 1;
		struct sockaddr_in serv_addr;
		int sock;
		char* IP;
		int PORT;

	public:
		server(char* ip, int port);

	private:
		int CreateSocket();
		void ServerBinding();
		void Listen();
		void Ready();
};

#endif