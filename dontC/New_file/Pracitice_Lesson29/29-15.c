#include <stdio.h>
#include <stdlib.h>

int
main (int   argc,
      char *argv[])
{
  int num1;
  double num2;
  long num3;

  num1 = atoi ("123");
  num2 = atof ("-1.234");
  num3 = atol ("1234123");

  printf ("%d, %g, %ld \n", num1, num2, num3);

  return 0;
}
