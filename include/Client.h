#include <iostream>
#include <queue>
#include <unistd.h>
#include <thread>
#include <queue>
#include <functional>
#include "ExecuterUnit.h"
#include "Reciever.h"
#include "Sender.h"
#include "Message.h"

using namespace std;


#ifndef CLIENT_H
#define CLIENT_H

class Client
{
	private:
		string ip;
		queue<std::thread*> t;

		Sender sender;
		Command command;
		Command newCommand;
		ExecuterUnit executerUnit;

	public:
		Client(vector<function<void()>> q1, vector<function<void()>> q2);
		void Start();
};

#endif
