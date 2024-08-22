.PHONY:All
All: server client

server: Server.cc
	g++ -o $@ $^ -std=c++11 
client: Client.cc
	g++ -o $@ $^ -std=c++11
.PHONY:clean
clean:
	rm -f client server