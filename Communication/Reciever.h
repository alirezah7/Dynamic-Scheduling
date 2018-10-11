//Reciever.h

#include <zmq.hpp>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "../Models/ExecuterUnit.h"
#include <msgpack.hpp>

#ifndef RECIEVER_H
#define RECIEVER_H


class Reciever
{
	public:
		static void RecieveObject(std::string ip, std::string port);
		static void RecieveExecutable(std::string ip, std::string port, std::string path);
		static std::string RecieveCommand(std::string ip, std::string port);
};

#endif