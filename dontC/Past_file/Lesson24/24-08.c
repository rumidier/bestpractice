#include <stdio.h>

int *
invarr (int *ar, int len)
{
  int i;
  for (i = 0; i < len; i++)
    ar[i] = -ar[i];

  return ar;
}

int
main (int   argc,
      char *argv[])
{
  int arr[3] = {1, 2, 3};
  int *parr;
  int i;

  parr = invarr (arr, sizeof (arr) / sizeof (int));

  for (i = 0; i < 3; i++)
    printf ("%d \n", *(parr + i));

  return 0;
}
