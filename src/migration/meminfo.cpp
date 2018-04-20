#include <sys/uio.h>
#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sstream>
#include <string>
#include <stdlib.h>
#include "meminfo.h"

using namespace std;


void meminfo::FindMemoryAddress(pid_t pid)
{

	char command[50];
	sprintf(command, "/proc/%d/maps", pid);

	int fd;
	fd = open(command,0);
	cout << "res: " <<  strerror(errno) << endl;

	char buf3[3000];
	ssize_t t;
	t = read(fd, buf3, 3000);
	cout << "res: " <<  strerror(errno) << endl;

	int flag=0;
	int i = 0;
	while(flag != 3)
	{
		if(buf3[i] == '\n')
		{
			flag += 1;
		}
		i++;
	}

	char address[8];
	for(int j=0; j<8; i++,j++)
		address[j] = buf3[i];
	sscanf(address,"%lx",(long unsigned *)&heap_start_address);

	i++;

	for(int j=0; j<8; i++,j++)
		address[j] = buf3[i];
	sscanf(address,"%lx",(long unsigned *)&heap_end_address);

	//heap_length = heap_end_address - heap_start_address;
}

void meminfo::ReadFromProcessMemory(pid_t pid, void* address)
{
	//int address = FindMemoryAddress(pid);
	struct iovec result[1];
	struct iovec process[1];
	char buffer[20000];
	ssize_t nread;

	result[0].iov_base = buffer;
	result[0].iov_len = 20000;

	process[0].iov_base = address;
	process[0].iov_len = 20000;

	nread = process_vm_readv(pid, result, 1, process, 1, 0);
	cout << "res: " <<  strerror(errno) << endl;
	cout << "output: \n" << buffer << endl;
}

void meminfo::writeInProcessMemory(pid_t pid, void* address, char* buffer)
{
	//int address = FindMemoryAddress(pid);
	struct iovec result[1];
	struct iovec process[1];
	ssize_t nread;

	result[0].iov_base = buffer;
	result[0].iov_len = 20000;

	process[0].iov_base = address;
	process[0].iov_len = 20000;

	nread = process_vm_writev(pid, result, 1, process, 1, 0);
	cout << "res: " <<  strerror(errno) << endl;
}
