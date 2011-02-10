#include <stdio.h>

int *makeintarray (int len,
                   int init)
{
  int arr[len];

  int i;
  for (i = 0; i < len; i++)
    {
      arr[i] = init;
    }

  return arr;
}

int
main (int   argc,
      char *argv[])
{
  int *arr1 = makeintarray (5, 0);
  int *arr2 = makeintarray (7, 2);

  int i;
  for (i = 0; i < 5; i++)
    printf ("%d ", arr1[i]);

  printf ("\n");
  for (i = 0; i < 7; i++)
    printf ("%d ", arr2[i]);

  return 0;
}
