#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#ifndef MEMINFO_H
#define MEMINFO_H

class meminfo
{
	public:
		void FindMemoryAddress(pid_t pid);
		void ReadFromProcessMemory(pid_t pid, void* address);
		void writeInProcessMemory(pid_t pid, void* address, char* buffer);

		void* heap_start_address;
		void* heap_end_address;
		void* heap_length;

		void* stack_start_address;
		void* stack_end_address;
		void* stack_length;
};

#endif