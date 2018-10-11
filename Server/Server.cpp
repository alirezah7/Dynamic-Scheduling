//#include "Client.h"
//g++ Server.cpp ../Communication/Sender.cpp ../Models/ExecuterUnit.pb.cc -lzmq -lprotobuf -o Server

#include <iostream>
#include "../Models/ExecuterUnit.pb.h"
#include "../Communication/Sender.h"
#include <unistd.h>

using namespace std;


int main()
{
	sleep(7);
	Sender::SendCommand("127.0.0.1", "5001", "migrate");
}