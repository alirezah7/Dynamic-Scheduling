//Client.h
#include "../Models/ExecuterUnit.h"
#include <stdlib.h>
#include <functional>
#include <queue>

#ifndef CLIENT_H
#define CLIENT_H

class Client
{
	public:
		//static void ExecuteCode(ExecuterUnit clientInfo);
		void Start(std::queue<std::function<void()>> );
};

#endif
