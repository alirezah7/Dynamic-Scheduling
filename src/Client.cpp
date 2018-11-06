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

	while(true)
	{
		reciever.Recieve(command);
		if(command.Type == "run")
		{	
			std::thread* run = new std::thread(&ExecuterUnit::Execute, executerUnit, command.PID, command.StartIndex, command.EndIndex);
			t.push(run);
		}

		else if(command.Type == "migrate")
		{
			cout << "migrate" << endl;
			newCommand.Type = "run";
			newCommand.PID = 0;
			newCommand.StartIndex = command.StartIndex;
			newCommand.EndIndex = command.EndIndex;
			t.pop();
			newCommand.DestIP = "127.1.1.2";
			sender.Send("127.1.1.2", newCommand);
		}
	}
}
