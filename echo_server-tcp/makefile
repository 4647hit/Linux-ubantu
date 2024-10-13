.PHONY:all
all:server client

server:Server.cc
	g++ -o  $@ $^ -std=c++14 -lpthread
client:Client.cc
	g++ -o  $@ $^ -std=c++14 -lpthread

.PHONY:clean
clean:
	rm -rf client server
