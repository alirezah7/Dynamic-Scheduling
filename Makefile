all:
	g++ -std=c++11 src/Test.cpp src/Client.cpp src/Reciever.cpp src/Sender.cpp src/ExecuterUnit.cpp -lzmq -lmsgpack -lpthread -o build/Client

clean:
	rm -rf build/Client