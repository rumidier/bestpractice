#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int mat[3][4][5];
  int i, j, k;
  int num = 1;

  for (i = 0; i < 3; i++)
    {
      for (j = 0; j < 4; j++)
        {
          for (k = 0; k < 5; k++)
            {
              mat[i][j][k] = num;
              num++;
            }
        }
    }

  for (i = 0; i < 3; i++)
    {
      for (j = 0; j < 4; j++)
        {
          for (k = 0; k < 5; k++)
            {
              if (!(mat[i][j][k] % 2) && !(mat[i][j][k] % 3))
                  printf ("%4d", mat[i][j][k]);
            }
          printf ("\n");
        }
    }

  return 0;
}
