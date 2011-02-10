#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int i, j;

  int a = 1, b = 2, c = 3;
  int *ptrarr[3] = {&a, &b, &c};

  int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
  //int arr[2][3] = {1, 2, 3, 4, 5, 6};
  //warining : missing braces around initializer
  //warining : (near initialization for 'arr[0] ')
  int (*arrptr)[3] = arr;

  for (i = 0; i < 3; i++)
    {
      printf ("%d ", *(ptrarr[i]));
    }
  printf ("\n\n");

  for (i = 0; i < 2; i++)
    {
      for (j = 0; j < 3; j++)
        {
          printf ("%d ", arrptr[i][j]);
        }
      printf ("\n");
    }

  return 0;
}
