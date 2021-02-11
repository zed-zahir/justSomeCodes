#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>

int main( int argc, char **argv ) {

	if( argc != 4 ) {
		printf("usage: %s <IP Address> <TCP Port start> <TCP Port end>\n", argv[0]);
		exit(1);
	}
	for( int i = atoi(argv[2]); i <= atoi(argv[3]); i++ ) {
	int sock = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in servAddr;
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons( i );
	servAddr.sin_addr.s_addr = inet_addr( argv[1] );

	if( !connect( sock, ( struct sockaddr * )&servAddr, sizeof(servAddr) ) )
		printf("the port number: %d is open\n", i);
	else
		printf("the port number: %d is closed\n", i);
	close(sock);
	}

	return 0;
}
