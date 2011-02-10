#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  double num1, num2, num3;

  num1 = 12.345;
  num2 = 23.456;
  num3 = 45.678;

  double *arr[3] = {&num1, &num2, &num3};

  double **dptr = &arr[0];
  printf ("%f %f %f \n", **dptr, **(dptr + 1), **(dptr + 2));

  return 0;
}
