.PHONY:all
all:client server
 
client: client.cc
	g++ -o $@ $^ -std=c++14 -lpthread
server: Main.cc
	g++ -o $@ $^ -std=c++14 -lpthread
.PHONY:clean
clean:
	rm -rf client server