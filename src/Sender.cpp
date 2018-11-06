#include <unistd.h>
#include <iostream>
#include <sstream>
#include <string>
#include <zmq.hpp>
#include <msgpack.hpp>
#include "../include/Sender.h"


/*template <typename T>
void Sender::Send(const std::string ip, const T& data)
{
	std::string address = "tcp://" + ip + ":8000";

	zmq::context_t context(1);
	zmq::socket_t socket(context, ZMQ_PAIR);
	socket.connect(address);

	msgpack::sbuffer packed;
	msgpack::pack(&packed, data);

	zmq::message_t body_msg(packed.size());
	std::memcpy(body_msg.data(), packed.data(), packed.size());

	socket.send(body_msg);
}*/
