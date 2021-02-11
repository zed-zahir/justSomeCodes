#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char **argv ) {

	char letters[6] = "AHi23";
	char input[6];
	char output[6];

	printf( "enter the passphrase: " );
	scanf( "%s", input );
	if( strlen( input ) != 5 ) {
		printf( "not the right length!!\n" );
		exit(0);
	}

	output[0] = (int)letters[0] ^ 2; 
	output[1] = (int)letters[3] - 10; 
	output[2] = (int)letters[2] + 12; 
	output[3] = (int)letters[2];
	output[4] = (int)letters[1] + 1;

	if( !strcmp( output, input ) )
		printf( "you succeed!!\n" );
	else
		printf( "try again\n" );

	return 0;
}
