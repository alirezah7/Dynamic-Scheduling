//Sender.h

#include <zmq.hpp>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "../Models/ExecuterUnit.h"
#include <msgpack.hpp>

#ifndef SENDER_H
#define SENDER_H

class Sender
{

	public:
		template<class MSG>
		static void SendObject(std::string ip, std::string port, MSG msg)
		{
			zmq::context_t context(1);
			zmq::socket_t sock(context, ZMQ_PAIR);
			GOOGLE_PROTOBUF_VERIFY_VERSION;
			std::string url = "tcp://" + ip + ":" + port;
			sock.connect(url.c_str());

			msgpack::sbuffer sbuf;
			msgpack::pack(sbuf, msg);
			// create a zmq message from the serialized string
			zmq::message_t request (sbuf.size());
			memcpy(request.data(), sbuf.data(), sbuf.size());

			sock.send (request);

		}
		
		static void SendExecutable(std::string ip, std::string port, std::string path);
		static void SendCommand(std::string ip, std::string port, std::string cmd);
};

#endif