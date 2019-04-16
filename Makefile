all: target 

target:
	gcc -g -o client client.c
	


clean:
	-rm client