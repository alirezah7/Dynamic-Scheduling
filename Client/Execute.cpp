#include <iostream>
#include <queue>
#include <unistd.h>
#include <thread>
#include <sys/types.h>
#include "Execute.h"
using namespace std;


bool MigrationFlag = false;


void Execute::Run(queue<function<void()>> q)
{
	while(!q.empty())
	{

		if(MigrationFlag == true) 
		{
			/*migrate(q);*/ 
			break;
		}

		else
		{
			q.front()();
			q.pop();
		}

		this_thread::yield();


	}
}

void Execute:: EnableMigration()
{
	MigrationFlag = true;
	cout << "Migrate CMD" << endl;
}