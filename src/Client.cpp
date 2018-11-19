#include <iostream>
#include <queue>
#include <unistd.h>
#include <thread>
#include <queue>
#include <functional>
#include "../include/Client.h"

using namespace std;


Client::Client(vector<function<void()>> q1, vector<function<void()>> q2)
{
	executerUnit.set(0, q1);
	executerUnit.set(1, q2);
}


void Client::Start()
{
	cout << "enter ip address of this node(its for test) : ";
	cin >> ip;
	Reciever reciever(ip);

	int i = 0;
	std::thread* run[10];
	std::thread* migrate[10];

	while(true)
	{
		reciever.Recieve(command);
		if(command.Type == "run")
		{	
			run[i] = new std::thread(&ExecuterUnit::Execute, executerUnit, command.PID, command.StartIndex, command.EndIndex);
			t.push(run[i]);
		}

		else if(command.Type == "migrate")
		{
			migrate[i] = new std::thread(&ExecuterUnit::MigrateProcess, executerUnit, command.PID, command.DestIP);
			t.push(migrate[i]);
		}
		i++;
	}
}
