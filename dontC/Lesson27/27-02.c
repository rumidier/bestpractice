#include <stdio.h>

int
simpleaddone (int num)
{
  return num + 1;
}

int
addtwonumber (int n1,
              int n2)
{
  return n1 + n2;
}

int
main (int   argc,
      char *argv[])
{
  int (*fctptrone) (int);
  int (*fctptrtwo) (int, int);

  fctptrone = simpleaddone;
  fctptrtwo = addtwonumber;

  printf ("10 + 1 = %d \n", fctptrone (10));
  printf ("10 + 20 = %d \n\n", fctptrtwo (10, 20));

  printf ("10 + 1 = %d \n", (*fctptrone) (10));
  printf ("10 + 20 = %d \n\n", (*fctptrtwo) (10, 20));

  return 0;
}
