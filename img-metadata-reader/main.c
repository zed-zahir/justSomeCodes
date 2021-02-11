#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv) {

  unsigned char buff[999];

  int f = open( argv[1], O_RDONLY );
  read( f, buff, sizeof(buff) );

  if( buff[0] == 0x42 && buff[1] == 0x4D) {
    printf( "the file format is BMP\n" );
  } else {
    printf( "the file format is not BMP\n" );
    exit(1);
  }
  
  unsigned int size = buff[2] + buff[3] + buff[4] + buff[5];
  unsigned int unusedA = buff[6] + buff[7];
  unsigned int unusedB = buff[8] + buff[9];
  unsigned int pixelArray = buff[0xA] + buff[0xB] + buff[0xC] + buff[0xD];
  
  printf("the size of the bmp file is: %d\n", size); 
}
