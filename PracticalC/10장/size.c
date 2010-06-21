#include <stdio.h>

#define SIZE 10
#define FUDGE SIZE -2

int
main (int argc, char *argv[])
{
  int size;

  size = FUDGE;
  printf ("Size is %d\n", size);

  return 0;
}
