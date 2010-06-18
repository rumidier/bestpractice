#include <stdio.h>

int
main (int argc, char *argv[])
{
  int i;
  int a[] = {1, 2, 3, 4};

  for (i = 3; i >= 0; i--)
    printf ("%d ", a[i]);
  printf ("\n");

  return 0;
}
