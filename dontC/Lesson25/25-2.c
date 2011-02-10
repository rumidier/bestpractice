#include <stdio.h>

void swapvalue (int n1,
                int n2)
{
  int tmp = n1;
  n1 = n2;
  n2 = tmp;

  printf ("n1 : %d \n", n1);
  printf ("n2 : %d \n", n2);
}

int
main (int   argc,
      char *argv[])
{
  int val1 = 5;
  int val2 = 7;

  swapvalue (val1, val2);
  printf ("val1 : %d \n", val1);
  printf ("val2 : %d \n", val2);

  return 0;
}
