
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>

#include <wiringPi.h>
#include <wiringSerial.h>

int fd;

int main (void)
{
 
  wiringPiSetup();
  fd = serialOpen("/dev/ttyAMA0", 115200);
  if (fd  < 0)
  {
    fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno)) ;
    return 1 ;
  }


  unsigned char pewpew[] = {0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x20,0xdf};
  int c,e;
  c = 0;
  while (c<1){
	  e = write(fd, pewpew, sizeof(pewpew));
	  if (e<0){
		  printf("%s","There was a problem with the write.\n");
	  }
	  sleep(1);
	  c++;
  }
  return 0 ;
}
