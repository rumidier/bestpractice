#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int *ptr = arr;

  printf ("%d \n", *(ptr + 1));
  printf ("%d \n", *(ptr + 4) - *ptr);
  printf ("%d \n", *(ptr++));
  printf ("%d \n", *(++ptr));

  printf ("%d \n", *(ptr - 2));
  printf ("%d \n", *(ptr--));
  printf ("%d \n", *(ptr--));

  return 0;
}
