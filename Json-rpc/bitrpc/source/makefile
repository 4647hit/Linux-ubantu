CFLAG= -std=c++11 -I ../build/release-install-cpp11/include/
LFLAG= -L ../build/release-install-cpp11/lib/ -lmuduo_net -lmuduo_base -lpthread -ljsoncpp
all:server client

server:test_server.cpp
	g++ $(CFLAG) -o $@ $^  $(LFLAG)
client:test_client.cpp
	g++ $(CFLAG) -o $@ $^  $(LFLAG)
.PHONY:clean
clean:
	rm -rf server client
	