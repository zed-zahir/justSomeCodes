#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main( int argc, char **argv ) {
	
	char buffer[ 1024 ];
	char bufferr[ 1024 ];

	int fd = open( argv[ 1 ], O_RDONLY );
	read( fd, buffer, 1024 );
	int fdd = open( argv[ 2 ], O_RDONLY );
	read( fdd, bufferr, 1024 );
	strcat( buffer, bufferr );
	write( 1, buffer, strlen( buffer ) );

	return 0;
}
