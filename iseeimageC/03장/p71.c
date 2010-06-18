#include <stdio.h>

int
main (int argc, char *argv[])
{
  int i, j;

  for (j = 1; j <= 9; j++)
    for (i = 1; i <= 9; i++)
      printf ("%dX%d = %d\n", j, i, j*i);

  return 0;
}
