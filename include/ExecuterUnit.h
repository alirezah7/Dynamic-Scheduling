#include <iostream>
#include <queue>
#include <unistd.h>
#include <functional>
#include "Sender.h"


using namespace std;

#ifndef EXECUTERUNIT_H
#define EXECUTERUNIT_H

class ExecuterUnit
{
	private:
		vector<function<void()>> Processes[10];
		Sender sender;

	public:
		void Execute(int PId, int StartIndex, int EndIndex);
		vector<function<void()>> get(int Index);
		void set(int Index, vector<function<void()>> q);
		void MigrateProcess(int PId, std::string ip);
};

#endif
