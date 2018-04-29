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
#include "getinfo.h"

using namespace std;

struct NodeInfo
{
	string Name;
	string KernelVersion;
	string OSName;

	string cpuMHz;
	string cpuCache;

	string memTotal;
	string memFree;
	string memAvailable;
	string memBuffers;
	string memCached;
};


void getinfo::GetOsInfo(struct NodeInfo *Node)
{
	int fd;
	fd = open("/proc/version",0);
	cout << "res: " <<  strerror(errno) << endl;

	char buffer[170];
	char osname[15];
	char version[20];

	ssize_t t;
	t = read(fd, buffer, 170);
	cout << "res: " <<  strerror(errno) << endl;

	int i = 0;
	int j = 0;
	for(j=0; buffer[i] != ' '; i++,j++)
		osname[j] = buffer[i];

	osname[j] = '\0';
	string s1(osname);
	Node->OSName = s1;

	int flag=0;
	while(flag != 2)
	{
		if(buffer[i] == ' ')
		{
			flag += 1;
		}
		i++;
	}


	for(j=0; buffer[i] != ' '; i++,j++)
		version[j] = buffer[i];

	version[j] = '\0';
	string s2(version);
	Node->KernelVersion = s2;
	
	char name[20];
	t = gethostname(name,20);
	cout << "res: " <<  strerror(errno) << endl;

	string s3(name);
	Node->Name = s3;

	close(fd);
}

void getinfo::GetCpuInfo(struct NodeInfo *Node)
{
	int fd;
	fd = open("/proc/cpuinfo",0);
	cout << "res: " <<  strerror(errno) << endl;

	char buffer[200];
	char cpuCache[10];
	char cpuMHz[10];

	ssize_t t;
	t = read(fd, buffer, 200);
	cout << "res: " <<  strerror(errno) << endl;

	int i = 0;
	int flag=0;
	int j = 0;
	while(flag != 6)
	{
		if(buffer[i] == '\n')
		{
			flag += 1;
		}
		i++;
	}

	flag = 0;
	for(; flag != 2; i++)
	{
		if(buffer[i] == ' ')
			flag++;
	}

	for(j=0; buffer[i] != '\n'; i++,j++)
		cpuMHz[j] = buffer[i];

	cpuMHz[j] = '\0';
	string s1(cpuMHz);
	Node->cpuMHz = s1;


	flag = 0;
	i++;
	for(; flag != 2; i++)
	{
		if(buffer[i] == ' ')
			flag++;
	}

	for(int j=0; buffer[i] != ' '; i++,j++)
		cpuCache[j] = buffer[i];

	cpuCache[j] = '\0';
	string s2(cpuCache);
	Node->cpuCache = s2;

	close(fd);		
}

void getinfo::GetMemoryInfo(struct NodeInfo *Node)
{
	int fd;
	fd = open("/proc/meminfo",0);
	cout << "res: " <<  strerror(errno) << endl;

	char buffer[150];
	char memTotal[10];
	char memFree[10];
	char memAvailable[10];
	char memBuffers[10];
	char memCached[10];

	ssize_t t;
	t = read(fd, buffer, 150);
	cout << "res: " <<  strerror(errno) << endl;

	int i = 0;
	int flag=0;
	int j = 0;

	for(; flag != 1; i++)
	{
		if(buffer[i] == ' ')
			flag++;
	}

	while(buffer[i] == ' ') i++;

	for(j=0; buffer[i] != ' '; i++,j++)
		memTotal[j] = buffer[i];

	memTotal[j]='\0';

	string s1(memTotal);
	Node->memTotal = s1;


	i++;
	flag = 0;
	
	for(; flag != 1; i++)
	{
		if(buffer[i] == ' ')
			flag++;
	}
	while(buffer[i] == ' ') i++;

	for(j=0; buffer[i] != ' '; i++,j++)
		memFree[j] = buffer[i];

	memFree[j]='\0';

	string s2(memFree);
	Node->memFree = s2;


	i++;
	flag = 0;

	for(; flag != 1; i++)
	{
		if(buffer[i] == ' ')
			flag++;
	}
	while(buffer[i] == ' ') i++;

	for(int j=0; buffer[i] != ' '; i++,j++)
		memAvailable[j] = buffer[i];

	memAvailable[j]='\0';

	string s3(memAvailable);
	Node->memAvailable = s3;

	close(fd);	
}

void getinfo::GetProcessInfo(pid_t pid, struct ProcessInfo * Process)
{
//ToDo

}
