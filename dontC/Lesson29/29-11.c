#include <stdio.h>
#include <string.h>

int
main (int   argc,
      char *argv[])
{
  char str[] = ("it is possible to master C in a month or two");
  char *chptr;

  chptr = strchar (str, 'i');
  printf ("첫 번째 i 이후 문자열 : %s \n", chptr);

  chptr = strrchar (str, 'i');
  printf ("마지막 i 이후 문자열 : %s \n", chptr);

  return 0;
}
