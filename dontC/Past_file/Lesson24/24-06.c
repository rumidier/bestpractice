#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int arr[5] = {1, 2, 3, 4, 5};
  int *parr = arr;
  int i;

  for (i = 0; i < 5; i++)
    {
      printf ("%d ", parr[i]);
    }
  printf ("\n");

  for (i = 0; i < 5; i++)
    {
      printf ("%d ", *(parr + i));
    }
  printf ("\n");

  return 0;
}
