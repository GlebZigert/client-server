all: clean client server

client:
	gcc -g -o client client.c
	

server:
	gcc -g -o server server.c

clean:
	-rm client server