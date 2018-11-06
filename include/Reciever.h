//Reciever.h

#include <unistd.h>
#include <iostream>
#include <sstream>
#include <string>
#include <zmq.hpp>
#include <msgpack.hpp>

#ifndef RECIEVER_H
#define RECIEVER_H


class Reciever
{
	public:
		zmq::context_t context = zmq::context_t(1);
		zmq::socket_t socket = zmq::socket_t(context, ZMQ_PAIR);

		Reciever(const std::string ip);

		template <typename T>
		void Recieve(T& data)
		{
			zmq::message_t body_msg;
			socket.recv(&body_msg);

			msgpack::unpacked unpacked_body;
			msgpack::unpack(&unpacked_body, static_cast<const char*>(body_msg.data()), body_msg.size());
			unpacked_body.get().convert(&data);
		}
};

#endif
