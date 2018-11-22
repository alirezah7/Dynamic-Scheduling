#include <iostream>
#include <queue>
#include <unistd.h>
#include <functional>
#include "../include/ExecuterUnit.h"
#include "../include/Message.h"
#include <mutex>

using namespace std;

std::mutex m;
int i[10] = {0};
int j[10] = {0};
int curr[10] = {0};
bool flag[10] = {false};


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
	i[PId] = StartIndex;
	j[PId] = EndIndex;

	while(i[PId] <= j[PId])
	{
		curr[PId] = i[PId];
		++i[PId];

		auto CurrentFunction = CurrentProcess[curr[PId]];
		CurrentFunction();

		if(flag[PId]) break;
	}
	flag[PId] = false;
}

void ExecuterUnit::MigrateProcess(int PId, string ip)
	{

		flag[PId] = true;

		Command newCommand;
		newCommand.Type = "run";
		newCommand.PID = PId;
		newCommand.DestIP = ip;
		newCommand.StartIndex = i[PId];
		newCommand.EndIndex = j[PId];
	
		i[PId] = 0;
		j[PId] = 0;
		curr[PId] = 0;

		sender.Send(newCommand.DestIP, newCommand);
	}
