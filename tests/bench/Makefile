CC=g++
CFLAGS=-std=c++11 -g
TARGET := client server

all: $(TARGET)

client: client.o
	$(CC) $(CFLAGS) -o $@ $^

server: server.o
	$(CC) $(CFLAGS) -o $@ $^

client.o: client_bench.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

server.o: server_bench.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f client.o server.o client server
