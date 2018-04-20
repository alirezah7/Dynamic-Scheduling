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

struct NodeInfo;
struct ProcessInfo;


#ifndef GETINFO_H
#define GETINFO_H

class getinfo
{

	public:
		void GetNodeInfo(struct NodeInfo *Node);
		void GetProcessInfo(pid_t pid, struct ProcessInfo * Process);

};

#endif
