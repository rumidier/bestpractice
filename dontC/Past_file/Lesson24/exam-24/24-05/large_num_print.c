#include <stdio.h>


int large_num_plus_arry (int arr[][3]);
int *large_num_cmparrsum (int ar1[][3],
                          int ar2[][3]);

int *
large_num_cmparrsum (int ar1[][3], int ar2[][3])
{
  if (large_num_plus_arry (ar1) > large_num_plus_arry (ar2))
    return (int *)ar1;
  else
    return (int *)ar2;
}

int
large_num_plus_arry (int arr[][3])
{
  int add_result;
  int i, j;

  add_result = 0;

  for (i = 0; i < 3; i++)
    for (j = 0; j < 3; j++)
      {
        add_result += arr[i][j];
      }

  return add_result;
}

int
main (int   argc,
      char *argv[])
{
  int arr1[3][3] = {{3, 2, 1}, {6, 7, 2}, {5, 1, 9}};
  int arr2[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  int (*aptr)[3] = large_num_cmparrsum (arr1, arr2);

  int i, j;

  for (i = 0; i < 3; i++)
    {
      for (j = 0; j < 3; j++)
        {
          printf ("%4d", aptr[i][j]);
        }
      printf ("\n");
    }

  return 0;
}
