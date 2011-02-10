#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int num1 = 10;
  double num2 = 7.12345;

  int *ptr1 = &num1;
  double *ptr2 = &num2;

  printf ("ptr1 : %d \n", ptr1);
  printf ("ptr2 : %d \n\n", ptr2);

  ptr1++, ptr2++;
  printf ("ptr1 : %d \n", ptr1);
  printf ("ptr2 : %d \n\n", ptr2);

  printf ("ptr1 : %d \n", ptr1 + 3);
  printf ("ptr2 : %d \n\n", ptr2 + 3);
  
  ptr1--, ptr2--;
  printf ("ptr1 : %d \n", ptr1);
  printf ("ptr2 : %d \n\n", ptr2);

  printf ("ptr1 : %d \n", ptr1 - 3);
  printf ("ptr2 : %d \n\n", ptr2 - 3);

  return 0;
}
