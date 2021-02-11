
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>

#define PORT 7001
#define IP_ADDRESS "127.0.0.1"

int main( void ) {

	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	int sock;
	if( sockfd < 0 )
	  perror("socket");
	
	char buff[1024];


	struct sockaddr_in servAddr, clientAddress;
	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons( PORT );
	servAddr.sin_addr.s_addr = inet_addr( IP_ADDRESS );
	socklen_t clientAddressSize = sizeof(clientAddress);

	if( bind( sockfd, ( struct sockaddr * )&servAddr, sizeof( servAddr ) ) < 0 )
	  perror("bind");

	if( listen( sockfd, 5 ) < 0 )
	  perror("listening");

		if( (sock = accept( sockfd, ( struct sockaddr * )&clientAddress, &clientAddressSize ) ) < 0 )
		perror("accepting");
	while ( 1 ) {
		
		read( sock, buff, strlen(buff));
		write( sock, buff, strlen( buff ) );
		close( sockfd );
	}

	return 0;
}
