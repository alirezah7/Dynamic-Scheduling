#include <msgpack.hpp>

struct Command
{
	std::string Type;

	int PID;

	int StartIndex;
	int EndIndex;

	std::string DestIP;

	MSGPACK_DEFINE(Type, PID, StartIndex, EndIndex, DestIP)
};
