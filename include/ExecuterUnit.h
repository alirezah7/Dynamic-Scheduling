#include <iostream>
#include <queue>
#include <unistd.h>
#include <functional>

using namespace std;

#ifndef EXECUTERUNIT_H
#define EXECUTERUNIT_H

class ExecuterUnit
{
	private:
		vector<function<void()>> Processes[10];

	public:
		void Execute(int PId, int StartIndex, int EndIndex);
		vector<function<void()>> get(int Index);
		void set(int Index, vector<function<void()>> q);
};

#endif
