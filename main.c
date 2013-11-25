/**************************************************

file: main.c
purpose: simple demo that receives characters from
the serial port and print them on the screen

**************************************************/

#include <stdlib.h>
#include <stdio.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "rs232.h"



int main()
{
  int i, n,
      cport_nr=2,        /* /dev/ttyS0 (COM1 on windows) */
      bdrate=115200;       /* 9600 baud */

  unsigned char buf[4096];


  if(RS232_OpenComport(cport_nr, bdrate))
  {
                                 while(1)
    printf("Can not open comport\n");

    return(0);
  }

  while(1)
  {
    n = RS232_PollComport(cport_nr, buf, 4095);

    if(n > 0)
    {
      buf[n] = 0;   /* always put a "null" at the end of a string! */

      for(i=0; i < n; i++)
      {
        if(buf[i] < 32)  /* replace unreadable control-codes by dots */
        {
          buf[i] = '.';
        }
      }

      printf("received %i bytes: %s\n", n, (char *)buf);
    }
    printf("pusto...\n");
#ifdef _WIN32
    Sleep(100);
#else
    usleep(100000);  /* sleep for 100 milliSeconds */
#endif
  }
  while(1) printf("d");
  return(0);
}
