#include <stdio.h>

int
main (int argc, char *argv[])
{
  int array [] = {4, 5, 6, 8, 9, 8, 1, 0, 1, 9, 3};
  int index;

  index = 0;

  while (array [index] != 0) {
    ++index;
  }

  printf ("Number of elements before zero %d\n",
          index);

  return 0;
}
