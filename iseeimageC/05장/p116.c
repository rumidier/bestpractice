#include <stdio.h>

void
dispnum (int a)
{
  printf ("인수의 값은 %d\n", a);
}

int
main (int argc, char *argv[])
{
  int x = 10;
  dispnum (5);
  dispnum (x);

  return 0;
}
