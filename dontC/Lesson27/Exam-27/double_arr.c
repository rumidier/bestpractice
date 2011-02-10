#include <stdio.h>
#include <stdlib.h>

int dsdsort (const void *, const void *);

int
main (int   argc,
      char *argv[])
{
  double arr[] = {2.5, 5.12, 4.12, 0.016, 9.14};
  int i;

  qsort ((void *) arr, sizeof (arr) / sizeof (double), sizeof (double), dsdsort);

  for (i = 0; i < 5; i++)
    printf ("%7g ", arr[i]);

  printf ("\n");

  return 0;
}

int dsdsort (const void *p1, const void *p2)
{
  double n1 = *((double *)p1);
  double n2 = *((double *)p2);
  int ret;

  if (n1 > n2)
    ret = 1;
  else if (n1 < n2)
    ret = -1;
  else
    ret = 0;

  return ret;
}
