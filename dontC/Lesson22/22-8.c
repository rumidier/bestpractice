#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int *ptr = 0;
  *ptr = 100;
  printf ("%d", *ptr);

  return 0;
}
