#include <unistd.h>
#include <iostream>
#include <sstream>
#include <string>
#include <zmq.hpp>
#include <msgpack.hpp>
#include "../include/Reciever.h"

Reciever::Reciever(const std::string ip)
{
	std::string address = "tcp://" + ip + ":8000";
	socket.bind(address.c_str());	
}


/*template <typename T>
void Reciever::Recieve(T& data)
{
	zmq::message_t body_msg;
	socket.recv(&body_msg);

	msgpack::unpacked unpacked_body;
	msgpack::unpack(&unpacked_body, static_cast<const char*>(body_msg.data()), body_msg.size());
	unpacked_body.get().convert(&data);
}*/
