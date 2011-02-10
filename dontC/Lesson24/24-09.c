#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int arr1[3][2];
  int arr2[3][3];
  int arr3[3][4];

  printf ("%p %p \n", arr1, arr1 + 1);
  printf ("%p %p \n", arr2, arr2 + 1);
  printf ("%p %p \n", arr3, arr3 + 1);

  return 0;
}
