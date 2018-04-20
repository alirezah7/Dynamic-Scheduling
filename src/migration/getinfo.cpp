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
};


void getinfo::GetNodeInfo(struct NodeInfo *Node)
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
	for(int j=0; buffer[i] != ' '; i++,j++)
		osname[j] = buffer[i];

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


	for(int j=0; buffer[i] != ' '; i++,j++)
		version[j] = buffer[i];

	string s2(version);
	Node->KernelVersion = s2;
	
	char name[20];
	t = gethostname(name,20);
	cout << "res: " <<  strerror(errno) << endl;

	string s3(name);
	Node->Name = s3;
}

void getinfo::GetProcessInfo(pid_t pid, struct ProcessInfo * Process)
{
//ToDo

}
