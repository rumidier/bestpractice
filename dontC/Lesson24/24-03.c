#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int arr[] = {1, 2, 3, 4, 5};
  int *ptr = arr;

  printf ("first element : %d \n", *(ptr++));
  printf ("second element : %d \n", *(ptr++));
  printf ("third element : %d \n", *(ptr++));
  printf ("fourth element : %d \n", *(ptr++));
  printf ("fifth element : %d \n", *(ptr++));

  return 0;
}
