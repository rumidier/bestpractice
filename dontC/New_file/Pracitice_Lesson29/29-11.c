#include <stdio.h>
#include <string.h>

int
main (int   argc,
      char *argv[])
{
  char str[] = "It is possible to master C in a month or two";
  char *ch_ptr;

  ch_ptr = strchr (str, 'i');
  printf ("첫 번재 i 이후 문자열 : %s \n", ch_ptr);

  ch_ptr = strrchr (str, 'i');
  printf ("마지막 i 이후 문자열 : %s \n", ch_ptr);

  return 0;
}
