#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int num1, num2, num3;
  num1 = 10;
  num2 = 20;
  num3 = 30;

  int *arr[3] = {&num1, &num2, &num3};

  int **dptr = &arr[0];
  printf ("%d %d %d \n", **dptr, **(dptr + 1), **(dptr + 2));

  return 0;
}
