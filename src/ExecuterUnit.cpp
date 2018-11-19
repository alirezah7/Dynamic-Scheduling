#include <iostream>
#include <queue>
#include <unistd.h>
#include <functional>
#include "../include/ExecuterUnit.h"
#include "../include/Message.h"
#include <mutex>

using namespace std;

std::mutex m;
int i, j = 0;
bool flag = false;


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
	int curr = 0;
	i = StartIndex;
	j = EndIndex;

	while(i <= j)
	{
		m.lock();
		curr = i;
		++i;
		m.unlock();

		auto CurrentFunction = CurrentProcess[curr];
		CurrentFunction();

		m.lock();
		if(flag) break;
		flag = false;
		m.unlock();
	}

}

void ExecuterUnit::MigrateProcess(int PId, string ip)
	{
		m.lock();
		flag = true;
		m.unlock();

		Command newCommand;
		newCommand.Type = "run";
		newCommand.PID = PId;
		newCommand.DestIP = ip;

		m.lock();
		newCommand.StartIndex = i;
		newCommand.EndIndex = j;
		i = 0;
		j = 0;
		m.unlock();

		sender.Send(newCommand.DestIP, newCommand);
	}
