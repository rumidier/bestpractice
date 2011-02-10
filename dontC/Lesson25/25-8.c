#include <stdio.h>
#include <stdlib.h>

int
main (int   argc,
      char *argv[])
{
  int *arr;
  int i;

  arr = (int *) malloc (sizeof (int) * 3);
  printf ("arr 참조 주소 : %#x \n", arr);
  for (i = 0; i < 3; i++)
    arr[i] = i;

  arr = (int *) realloc (arr, sizeof (int) * 5);
  printf ("arr 참조 주소 : %#x \n", arr);
  for (i = 0; i < 5; i++)
    arr[i] = i;

  for (i = 0; i < 5; i++)
    printf ("%d ", arr[i]);
  printf ("\n");

  free (arr);
  arr = NULL;

  return 0;
}
