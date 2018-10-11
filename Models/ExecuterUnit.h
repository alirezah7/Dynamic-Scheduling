//ExecuterUnit.h

#include <iostream>
#include <string.h>

#ifndef EXECUTERUNIT_H
#define EXECUTERUNIT_H


class ExecuterUnit
{
	public:
		int MemoryTotal;
		int MemoryRemained;
		int CpuTotal;
		int CpuRemaind;
		std::string CodePath;
		std::string IpAddress;
		pid_t Pid;


	void print()
	{
		std::cout<< CodePath<< std::endl;
	}
};

#endif
