#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int mat_a[2][2] = {{2, 2},{2, 2}};
  int mat_b[2][2] = {{1,0},{0,1}};

  printf ("%1d %1d\n", ((mat_a[0][0] * mat_b[0][0])
                        + (mat_a[0][1] * mat_b[1][0]))
                     ,((mat_a[0][0] * mat_b[0][1])
                       + (mat_a[0][1] * mat_b[1][1])));

  printf ("%1d %1d\n", ((mat_a[1][0] * mat_b[0][0])
                        + (mat_a[1][1] * mat_b[1][0]))
                     ,((mat_a[1][0] * mat_b[0][1])
                       + (mat_a[1][1] * mat_b[1][1])));

  return 0;
}
