#include <stdio.h>

typedef int IARR3 [3];
typedef int I2ARR4 [][4];

void incre2arr (I2ARR4 arr, int height);
void print2arr (I2ARR4 arr, int height);

int
main (int   argc,
      char *argv[])
{
  IARR3 arr1 = {1, 2, 3};
  I2ARR4 arr2 = {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12}
  };

  int i;
  for (i = 0; i < 3; i++)
    {
      printf ("%4d", arr1[i]);
    }
  printf ("\n\n");

  print2arr (arr2, 3);
  printf ("\n");

  incre2arr (arr2, 3);
  print2arr (arr2, 3);

  return 0;
}

void incre2arr (I2ARR4 arr, int height)
{
  int i, j;

  for (i = 0; i < height; i++)
    {
      for (j = 0; j < 4; j++)
        arr[i][j]++;
    }
}

void print2arr (I2ARR4 arr, int height)
{
  int i, j;

  for (i = 0; i < height; i++)
    {
      for (j = 0; j < 4; j++)
        {
          printf ("%4d", arr[i][j]);
        }
      printf ("\n");
    }
}
