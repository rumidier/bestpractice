#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int data1;
  char data2;
  double data3;

  int *ptr1 = &data1;
  char *ptr2 = &data2;
  double *ptr3 = &data3;

  *ptr1 = 100;
  *ptr2 = 100;
  *ptr3 = 100;

  printf ("data1 : %d \n", *ptr1);
  printf ("data2 : %c \n", *ptr2);
  printf ("data3 : %f \n", *ptr3);

  return 0;
}
