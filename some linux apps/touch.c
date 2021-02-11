#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main( int argc, char **argv ) {

	if( creat( argv[1], O_CREAT ) != -1 ) {
		return 0;
	}
	else {
		printf( "can't creat the file\n" );
		return 1;
	}
}
