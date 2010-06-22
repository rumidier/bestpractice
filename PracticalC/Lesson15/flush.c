#include <stdio.h>

int
main (int argc, char *argv[])
{
  int i, j;

  i = 1;
  j = 0;
  printf ("Starting\n");
  printf ("Before divide...");

  i = i / j;
  printf ("After\n");

  return 0;
}
