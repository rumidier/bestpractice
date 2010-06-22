#include <stdio.h>

int
main (int argc, char *argv[])
{
  int array [] = {4, 5, 8, 9, 8, 1, 0, 1, 9, 3};
  int *array_ptr;

  array_ptr = array;

  while ((*array_ptr) != 0) {
    ++array_ptr;
  }

  printf ("Number of elements before zero %d\n",
          array_ptr - array);

  return 0;
}
