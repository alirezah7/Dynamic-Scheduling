//http://www.cplusplus.com/forum/unices/14125/
#include <iostream>
#include <queue>
#include <unistd.h>
#include <thread>
#include <sys/types.h>

using namespace std;

#ifndef EXECUTE_H
#define EXECUTE_H

class Execute
{

	public:
		void Run(queue<function<void()>> q);
		void EnableMigration();
};

#endif