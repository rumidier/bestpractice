#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int num1;
  int num2;

  nu1 = 3;
  num2 = 30;

  int *ptr = &num1;
  int **dptr = &ptr;

  printf ("ptr point num : %d \n", num1);
  printf ("ptr point num : %d \n", *ptr);
  printf ("ptr point num : %d \n\n",  **dptr);

  *dptr = &num2;
  printf ("ptr point num : %d \n", num2);
  printf ("ptr point num : %d \n", *ptr);
  printf ("ptr point num : %d \n\n",  **dptr);


  **dptr += 3000;
  printf ("ptr point num : %d \n", num2);
  printf ("ptr point num : %d \n", *ptr);
  printf ("ptr point num : %d \n\n",  **dptr);

  return 0;
}
