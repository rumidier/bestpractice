#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int num1;
  doule num2;

  num1 = 3;
  num2 = 3.15;

  int *ptr1 = &num1;
  double *ptr2 = &num2;

  int **dptr1 = &ptr1;
  double **dptr2 = &ptr2;

  printf ("ptr1 save num : %#x \n", ptr1);
  printf ("ptr1 save point num : %#x \n", dptr1);

  printf ("ptr2 save num : %#x \n", ptr2);
  printf ("ptr2 save point num : %#x \n", ptr2);

  return 0;
}
