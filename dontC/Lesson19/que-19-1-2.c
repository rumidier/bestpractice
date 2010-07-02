#include <stdio.h>

int
main (int   argc,
      char *argv[])
{

  int mat[3][9];
  int i, j;

  for (i = 2; i < 5; i++)
    {
      for (j = 1; j <= 9; j ++)
        {
          mat[i - 2][j- 1] = i * j;
        }
    }

  for (i = 0; i < 9; i++)
    {
      printf ("%4d", mat[0][i] + mat[1][i] + mat[2][i]);
    }
  printf ("\n");

  return 0;
}
