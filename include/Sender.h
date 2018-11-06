#include <unistd.h>
#include <iostream>
#include <sstream>
#include <string>
#include <zmq.hpp>
#include <msgpack.hpp>

#ifndef SENDER_H
#define SENDER_H

class Sender
{
	public:
		template <typename T>
		void Send(const std::string ip, const T& data)
		{
		std::string address = "tcp://" + ip + ":8000";

		zmq::context_t context(1);
		zmq::socket_t socket(context, ZMQ_PAIR);
		socket.connect(address.c_str());

		msgpack::sbuffer packed;
		msgpack::pack(&packed, data);

		zmq::message_t body_msg(packed.size());
		std::memcpy(body_msg.data(), packed.data(), packed.size());

		socket.send(body_msg);
		}
};

#endif
