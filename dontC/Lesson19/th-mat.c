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

  for (i = 0; i < 3; i++)
    {
      printf ("*** arr[%d][x][x] 출력 ** \n", i);

      for (j = 0; j < 4; j++)
        {
          for (k = 0; k < 5; k++)
            {
              printf ("%4d", arr[i][j][k]);
            }
          printf ("\n");
        }
      printf ("\n");
    }

  return 0;
}
