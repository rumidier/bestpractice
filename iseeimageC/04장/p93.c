#include <stdio.h>

int
main (int argc, char *argv[])
{
  int x, y;
  int a[2][3] = {
      {10, 20, 30},
      {40, 50, 60}
  };

  for (x = 0; x < 2; x++) {
    for (y = 0; y < 3; y++)
      printf ("a[%d][%d] = %d ", x, y, a[x][y]);
    printf ("\n");
  }

  return 0;
}
