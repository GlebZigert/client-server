#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>/* содержит прототипы функций */
#include <sys/types.h>/* содержит объявления стандартных системных типов данных */
#include <resolv.h>/* содержит объявления дополнительных типов данных */





int main(void) 
{
printf("[Server]\n");

int socket_desc, client_sock, c;
struct sockaddr_in server, client;
//create socket
socket_desc = socket(AF_INET, SOCK_STREAM, 0);
if (socket_desc == -1)
	{
		printf("[Server]Could not create socket\n");
	}
printf("[Server]Socket created\n");

//Prepare the sockaddr_in structure
server.sin_family = AF_INET;
server.sin_addr.s_addr = INADDR_ANY;
server.sin_port = htons( 8888 );

//Bind
if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
	{
		//print the error message
		perror("[Server]bind failed. Error");
		return 1;
	}
printf("[Server]bind done\n");

//Listen
listen(socket_desc , 3);
	
//Accept and incoming connection
printf("[Server]Waiting for incoming connections...\n");
c = sizeof(struct sockaddr_in);
	
//accept connection from an incoming client
client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
if (client_sock < 0)
	{
		perror("[Server]accept failed\n");
		return 1;
	}
printf("[Server]Connection accepted\n");

return 0;
}