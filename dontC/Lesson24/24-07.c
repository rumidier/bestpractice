#include <stdio.h>

void intarrprintf (int *arr, int len)
{
  int i;
  for (i = 0; i < len; i++)
    printf ("%9d ", arr[i]);

  printf ("\n");
}

void dblarrprintf (double *arr, int len)
{
  int i;
  for (i = 0; i < len; i++)
    printf ("%9.4f ", arr[i]);

  printf ("\n");
}

int
main (int   argc,
      char *argv[])
{
  int arr1[3] = {1, 2, 3};
  double arr2[3] = {1.1, 2.2, 3.3};

  intarrprintf (arr1, sizeof (arr1) / sizeof (int));
  dblarrprintf (arr2, sizeof (arr2) / sizeof (double));

  return 0;
}
