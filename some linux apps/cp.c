#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main( int argc, char **argv ) {

	char buffer[1024];

	int fileSource = open( argv[1], 0, O_RDONLY );
	int fileDestination = open( argv[2], 0, O_APPEND );

	read( fileSource, buffer, strlen( buffer ) );
	write( fileDestination, buffer, strlen( buffer ) );

	return 0;
}
