#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>/* содержит прототипы функций */
#include <sys/types.h>/* содержит объявления стандартных системных типов данных */
#include <resolv.h>/* содержит объявления дополнительных типов данных */





int main(void) 
{
printf("[Client]\n");
int sock;
struct sockaddr_in server;
char message[1000] , server_reply[2000];
//Create socket
sock = socket(AF_INET , SOCK_STREAM , 0);
	if (sock == -1)
	{
		printf("[Client] Could not create socket\n");
	}
	printf("[Client] Socket created\n");

server.sin_addr.s_addr = inet_addr("127.0.0.1");
server.sin_family = AF_INET;
server.sin_port = htons( 8888 );

//Connect to remote server
	if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
	{
		perror("[Client] connect failed. Error\n");
		return 1;
	}
	
	printf("[Client] Connected\n");

while(1)
	{
		printf("[Client]Enter message : ");
		scanf("%s" , message);
		
		//Send some data
		if( send(sock , message , strlen(message) , 0) < 0)
		{
			puts("[Client]Send failed");
			return 1;
		}
		
		//Receive a reply from the server
		if( recv(sock , server_reply , 2000 , 0) < 0)
		{
			puts("[Client]recv failed");
			break;
		}
		
		puts("[Client]Server reply :");
		puts(server_reply);
	}
	
	close(sock);

return 0;
}