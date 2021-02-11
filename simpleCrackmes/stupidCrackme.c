#include <stdio.h>

int main( int argc, char **argv ) {

	int c1, c2, c3, c4, c5, c6;

	printf( "enter the password please: " );
	scanf( "%lc%lc%lc%lc%lc%lc", &c1, &c2, &c3, &c4, &c5, &c6 );

	if( c1 == 0x41 && c2 == 0x5A && c3 == 0x4A && c4 == 0x45 && c5 == 0x4A && c6 == 0x41 ) {
		printf( "good, you can make the happy dance now :D\n" );
	}
	else {
		printf( "oh no, try again!\n" );
	}


	return 0;
}
