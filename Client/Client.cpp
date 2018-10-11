//g++ Client.cpp ../Communication/Reciever.cpp ../Models/ExecuterUnit.pb.cc -lzmq -lprotobuf -o Client

#include "iostream"
#include "Client.h"
#include "Execute.h"
#include "../Models/ExecuterUnit.h"
#include "../Communication/Reciever.h"
#include <thread>
#include <queue>
#include <unistd.h>

using namespace std;

Execute E;



void foo(int x, int y, int z)
{
	cout<< "3 arg" <<endl;
	sleep(5);
}

void ExecuteCode(string path)
{	
	string temp = "chmod u+x " + path;
	system(temp.c_str());
	system(path.c_str());
}



void Listen()
{
	string CMD = Reciever::RecieveCommand("127.0.0.1", "5001");

	if(CMD == "migrate")
	{
		E.EnableMigration();
	}	
}


void Client::Start(queue<function<void()>> q)
{	
	thread run(&Execute::Run, E, q);
	thread listen(Listen);

	run.join();
	listen.join();
}

void GetExecutable()
{
	std::string path = "/home/node1/Desktop/myfile";
	Reciever::RecieveExecutable("127.0.0.1", "5002", path);
	ExecuteCode(path);
}



int main()
{	
	queue<function<void()>> q;
	q.push( [&] { foo(1, 2, 3); } );	q.push( [&] { foo(1, 2, 3); } );	q.push( [&] { foo(1, 2, 3); } );	q.push( [&] { foo(1, 2, 3); } );
	
	Client c;
	c.Start(q);
}