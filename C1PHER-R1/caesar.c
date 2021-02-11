#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if( argc < 2 || argc > 2 || atoi(argv[1]) < 1 || atoi(argv[1]) > 26 ) {
        printf( "Usage: %s key\n", argv[0] );
        return 1;
    }
    
    int key = atoi(argv[1]);
    char plaintext[32];

    printf( "plaintext: " );
    scanf( "%s", plaintext );
    size_t sizeofPlaintext = strlen( plaintext );

    char ciphertext[sizeofPlaintext];
    
    for( int i = 0; i < sizeofPlaintext; i++ ) {
        if( ((int)plaintext[i] + key) > 122) {
            plaintext[i] = plaintext[i] - 26;
        }
        if( (int)plaintext[i] >= 65 && (int)plaintext[i] <= 90 && (int)plaintext[i] + key > 90 ) {
            plaintext[i] = plaintext[i] - 26;
        }
        ciphertext[i] = (int) plaintext[i] + key;
    }
    printf( "ciphertext: " );
    for( int i = 0; i < sizeofPlaintext; i++ ) {
        printf( "%c", ciphertext[i] );
    }
    
    printf( "\n" );
}

