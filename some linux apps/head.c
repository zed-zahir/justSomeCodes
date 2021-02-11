#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main( int argc, char **argv ) {

	char buffer[1024];
	int i = 0;

	int f = open( argv[1], O_RDONLY );

	read( f, buffer, sizeof( buffer ) );

	write( 1, buffer, strlen( buffer ) );

	return 0;
}
