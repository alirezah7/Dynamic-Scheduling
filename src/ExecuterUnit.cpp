#include <iostream>
#include <queue>
#include <unistd.h>
#include <functional>
#include "../include/ExecuterUnit.h"

using namespace std;


vector<function<void()>> ExecuterUnit::get(int Index)
{
	return Processes[Index];
}

void ExecuterUnit::set(int Index, vector<function<void()>> q)
{
	Processes[Index] = q;
}

void ExecuterUnit::Execute(int PId, int StartIndex, int EndIndex)
{
	vector<function<void()>> CurrentProcess = get(PId);

	int i;
	for(i = StartIndex; i < EndIndex; i++)
	{
		CurrentProcess[i]();
	}
}
