//Reciever.h
//g++ Reciever.cpp ../Models/ExecuterUnit.pb.cc -lzmq -lprotobuf -o Reciever

#include "iostream"
#include <zmq.hpp>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fstream>
#include <thread>
#include <queue>
#include "Reciever.h"
#include "../Models/ExecuterUnit.pb.h"
#include "../Models/ExecuterUnit.h"
#include "../Client/Client.h"
#include <google/protobuf/text_format.h>
#include <msgpack.hpp>

using namespace std;



void Reciever::RecieveObject(std::string ip, std::string port)
{
	zmq::context_t context (1);
	zmq::socket_t socket(context, ZMQ_PAIR);
	std::string url = "tcp://" + ip + ":" + port;
	socket.bind(url.c_str());

	zmq::message_t request;
	//  Wait for next request from client
	socket.recv (&request);
	msgpack::sbuffer sbuf;
	sbuf.write(static_cast<const char *>(request.data()), request.size());

	std::vector<std::string> vec;

	msgpack::unpacked msg;
	msgpack::unpack(&msg, sbuf.data(), sbuf.size());
	msgpack::object obj = msg.get();

std::cout << obj << std::endl;

	obj.convert(&vec);


	std::cout << "Recieved Object" << std::endl;

}


void Reciever::RecieveExecutable(std::string ip, std::string port, std::string path)
{	
	zmq::context_t context (1);
	zmq::socket_t socket(context, ZMQ_PAIR);
	std::string url = "tcp://" + ip + ":" + port;
	socket.bind(url.c_str());

	zmq::message_t request;
	socket.recv (&request);		//  Wait for next request from client

	std::string msg(static_cast<char*>(request.data()), request.size());

	FILE *f;
	f = fopen (path.c_str(), "wb");
	if (f==NULL) {fputs ("File error",stderr); exit (1);}
	
	fwrite (msg.c_str() , sizeof(char), request.size(), f);
	fclose (f);
}


std::string Reciever::RecieveCommand(std::string ip, std::string port)
{
	zmq::context_t context (1);
	zmq::socket_t socket(context, ZMQ_PAIR);
	std::string url = "tcp://" + ip + ":" + port;
	socket.bind(url.c_str());

	zmq::message_t request;
	socket.recv (&request);
	std::string msg(static_cast<char*>(request.data()), request.size());
	return msg;
}