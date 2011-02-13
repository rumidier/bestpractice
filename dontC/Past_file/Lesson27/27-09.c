#include <stdio.h>
#include <stdlib.h>

int acdsort (const void *, const void *);

int
main (int   argc,
      char *argv[])
{
  int arr[5] = {3, 1, 2, 4, 5};
  int i;

  qsort ((void *)arr, sizeof (arr)/ sizeof (int), sizeof (int), acdsort);

  for (i = 0; i < 5; i++)
    printf ("%4d", arr[i]);

  printf ("\n");

  return 0;
}

int acdsort (const void * p1, const void * p2)
{
  int n1 = *((int *)p1);
  int n2 = *((int *)p2);
  int ret;

  if (n1 > n2)
    ret = 1;
  else if (n1 < n2)
    ret = -1;
  else
    ret = 0;

  return ret;
}
