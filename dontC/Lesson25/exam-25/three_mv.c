#include <stdio.h>

void three_mv_result (int *num1, int *num2, int *num3);

int
main (int   argc,
      char *argv[])
{
  int n1, n2, n3;

  n1 = 5, n2 = 6, n3 = 7;

  printf ("n1[%d] n2[%d] n3[%d]\n", n1, n2, n3);

  three_mv_result (&n1, &n2, &n3);
  printf ("n1[%d] n2[%d] n3[%d]\n", n1, n2, n3);

  return 0;
}

void
three_mv_result (int *num1,
                 int *num2,
                 int *num3)
{
  int temp;

  temp = *num1;
  *num1 = *num2;
  *num2 = *num3;
  *num3 = temp;
}
