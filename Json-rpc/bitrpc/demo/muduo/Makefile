CFLAG= -std=c++11 -I ../../build/release-install-cpp11/include/
LFLAG= -L ../../build/release-install-cpp11/lib/ -lmuduo_net -lmuduo_base -lpthread
all:server client

server:server.cpp
	g++ $(CFLAG) -o $@ $^  $(LFLAG)
client:Client.cpp
	g++ $(CFLAG) -o $@ $^  $(LFLAG)
.PHONY:clean
clean:
	rm -rf server client