#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int arr[3][4][5];
  int i, j, k;
  int num = 1;

  for (i = 0; i < 3; i++)
    {
      for (j = 0; j < 4; j++)
        {
          for (k = 0; k < 5; k++)
            {
              arr[i][j][k] = num;
              num++;
            }
        }
    }

  for (i = 0; i < 4; i++)
    {
      for (j = 0; j < 5; j++)
        {
          printf ("%4d", arr[0][i][j] + arr[1][i][j] + arr[2][i][j]);
        }

      printf ("\n");
    }

  return 0;
}
