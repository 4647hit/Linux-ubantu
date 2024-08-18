.PHONY:All
All: Piped_server Piped_client

Piped_server: Piped_server.cc
	g++ -o $@ $^ -std=c++11 
Piped_client: Piped_client.cc
	g++ -o $@ $^ -std=c++11
.PHONY:clean
clean:
	rm -f Piped_client Piped_server