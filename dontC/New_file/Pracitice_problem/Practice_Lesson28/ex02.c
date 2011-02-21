#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int arr [] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int *ptr = arr;

  printf ("%d \n", *(ptr + 1)); // 2
  printf ("%d \n", *(ptr + 4) - *ptr); // 4
  printf ("%d \n", *(ptr++)); // 1
  printf ("%d \n", *(++ptr)); // 3

  printf ("%d \n", *(ptr - 2)); // 1
  printf ("%d \n", *(ptr--)); // 3
  printf ("%d \n", *(--ptr)); // 1

  return 0;
}
