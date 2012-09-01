#include <stdio.h>

int
addnum (int a, int b)
{
  int x;

  x = a + b;

  return x;
}

int
maini (int argc, char *argv[])
{
  int n;

  n = addnum (2, 3);
  printf ("변환된 값은 %d\n", n);

  return 0;
}
