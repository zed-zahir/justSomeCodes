#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

int main( int argc, char **argv ) {

	char buff[ 1024 ];

	int sock = socket(AF_INET, SOCK_STREAM, 0);
	int fsock;

	struct sockaddr_in servAddr;
	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons( atoi(argv[ 2 ]) );
	servAddr.sin_addr.s_addr = atoi( argv[ 1 ] );

	fsock = open( "~/Downloads/download.dat", O_CREAT );

	connect( sock, ( struct sockaddr * )&servAddr, sizeof( servAddr ) );

	recv( sock, buff, strlen( buff ), 0 );

	write( fsock, buff, strlen( buff ) );

	close( sock );
	close( fsock );

	return 0;
}
