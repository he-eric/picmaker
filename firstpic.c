#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main() {

  char line[256];
  int fd, a, i, j, r, g, b;
  /* open .ppm file and then read in header */
  fd = open( "firstpic.ppm", O_RDWR | O_CREAT, 0644 );
  if ( fd < 0 )
    printf( "[OPEN]Errno[%d] [%s]\n", errno, strerror(errno) );
  a = write( fd, "P3 500 500 256 ", 15 );
  if ( a < 0 )
    printf( "[HEADER]Errno[%d] [%s]\n", errno, strerror(errno) );
  for ( i = 0; i < 500; i++ ) {
    for ( j = 0; j < 500; j++ ) {
      if ( i < 250  && j < 250) {
	r = 0;
	g = 0;
	b = 0;
	a = sprintf( line, "%d %d %d ", r, g ,b );
	if ( a < 0 ) 
	  printf( "[SPRINTF]Errno[%d] [%s]\n", errno, strerror(errno) );
      }
      else if ( i > 250 && j > 250 ) {
	r = 0;
	g = 0;
	b = 0;
	a = sprintf( line, "%d %d %d ", r, g, b );
      }
      else {
	r = 255;
	g = 255;
	b = 0;
	a = sprintf( line, "%d %d %d ", r, g, b );
      }
      a = write( fd, line, strlen(line) );
      if ( a < 0 )
	printf( "[WRITE]Errno[%d] [%s]\n", errno, strerror(errno) );
    }
  }
  a = close( fd );
  if ( a < 0 ) 
    printf( "[CLOSE]Errno[%d] [%s]\n", errno, strerror(errno) );

  return 0;
  
}
