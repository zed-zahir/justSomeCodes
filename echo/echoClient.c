#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>

//#define PORT 7
//#define IP_ADDRESS "127.0.0.1"

int main( int argc, char **argv ) {

	char buff[ 2048 ];
	char message[ 2048 ];

	int sock = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in servAddr;
	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons( atoi(argv[2]) );
	servAddr.sin_addr.s_addr = inet_addr( argv[1] );
	

	while(1) {
	scanf( "%s", message );
	connect( sock, ( struct sockaddr * )&servAddr, sizeof(servAddr) );

	write( sock, message, sizeof( message ) );
	  read( sock, buff, sizeof( buff ) );

 	  printf( "%s\n", buff );
	  close(sock);
	}	
	return 0;
}
