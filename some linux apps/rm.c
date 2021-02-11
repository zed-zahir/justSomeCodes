#include <unistd.h>
#include <stdio.h>

int main( int argc, char **argv ) {

	int unlinkReturn = 0;

	if( argc != 2 ) {
		printf( "you need to specify the path and the file to remove\n" );
		unlinkReturn = 1;
	} else {
		removeFile( argv[1] );
		unlinkReturn = 0;
	}

	return unlinkReturn;
}

int removeFile( char *pathname ) {

       int unlinkResponse = unlink(pathname);
       
       return unlinkResponse;
}
