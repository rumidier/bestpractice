#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int arr[5] = {1, 2, 3, 4, 5};

  int i;

  for (i = 0; i < 3; i++)
    {
      printf ("%d ", arr[i]);
    }
  printf ("\n");

  for (i = 0; i < 5; i++)
    {
      printf ("%d ", *(arr + i));
    }
  printf ("\n");

  return 0;
}
