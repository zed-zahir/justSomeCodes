#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void encrypt( char*, int );
void decrypt( char*, int );

int main( void ) {

  char alice[64];
  int key;

  printf("enter the plain text: ");
  scanf("%s", alice);
  printf("enter the key as an integer: ");
  scanf("%d", &key);

  printf("plain text %s\n", alice);
  encrypt(alice, key);
  printf("encrypted text %s\n", alice);
  decrypt(alice, key);
  printf("decrypted text %s\n", alice);

  return 0;
}

void encrypt( char *dat, int key ) {
  char tmp;
  for( int i = 0; i <= strlen(dat); i += 2) {
    if((strlen(dat) % 2 == 1) && i == strlen(dat) - 1)
      continue;
    tmp = dat[i] ^ key;
    dat[i] = dat[i + 1] ^ (key + 1);
    dat[i + 1] = tmp;
  }
}

void decrypt( char *dat, int key ) {
  char tmp;
  for( int i = 0; i <= strlen(dat); i += 2 ) {
    if( ( strlen(dat) % 2 == 1 ) && i == strlen(dat) -1 )
      continue;
    tmp = dat[i + 1] ^ key;
    dat[i + 1] = dat[i] ^ (key + 1);
    dat[i] = tmp;
  }
}
