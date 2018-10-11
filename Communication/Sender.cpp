//Reciever.h
//https://gist.github.com/samklr/0b8a0620f82005e7f556
//http://biicode-docs.readthedocs.io/c++/examples/zmq_protobuf.html
//https://tuananh.org/2015/06/16/how-to-install-zeromq-on-ubuntu/
//g++ Sender.cpp ../Models/ExecuterUnit.pb.cc -lzmq -lprotobuf -o Sender

#include "iostream"
#include <zmq.hpp>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "../Models/ExecuterUnit.pb.h"
#include "../Models/ExecuterUnit.h"
#include "Sender.h"


using namespace std;


zmq::context_t context(1);
zmq::socket_t sock(context, ZMQ_PAIR);



void Sender::SendExecutable(std::string ip, std::string port, std::string path)
{
	std::string url = "tcp://" + ip + ":" + port;
	sock.connect(url.c_str());

	char * buffer;
	long lSize;
	size_t result;

	FILE *f = fopen(path.c_str(), "rb");
	if (f==NULL) {fputs ("File error",stderr); exit (1);}

	fseek (f , 0 , SEEK_END);
	lSize = ftell (f);
	rewind (f);

	buffer = (char*) malloc (sizeof(char)*lSize);
	if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}

	result = fread (buffer,1,lSize,f);
	if (result != lSize) {fputs ("Reading error",stderr); exit (3);}

	zmq::message_t request (lSize);
	memcpy ((void *) request.data (), buffer, lSize);
	sock.send (request);
}


void Sender::SendCommand(std::string ip, std::string port, std::string cmd)
{
	std::string url = "tcp://" + ip + ":" + port;
	sock.connect(url.c_str());

	zmq::message_t request (cmd.size());
	memcpy ((void *) request.data (), cmd.c_str(), cmd.size());
			
	sock.send (request);
}