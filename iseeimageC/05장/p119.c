#include <stdio.h>

int y;
int z;

void
myfunc (int a)
{
  int z;
  int x;

  x = a;
  y = a;
  z = a;
}

int
main (int argc, char *argv[])
{
  int x;

  x = 10;
  y = 10;
  z = 10;

  printf ("x, y, z의 값은 %d, %d, %d\n", x, y, z);

  myfunc (5);
  printf ("x, y, z의 값은 %d, %d, %d\n", x, y, z);

  return 0;
}
