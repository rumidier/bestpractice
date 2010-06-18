#include <stdio.h>

void
swapbyval (int, int);
void
swapbyref (int *, int *);

int
main (int argc, char *argv[])
{
  int a = 2, b = 7;

  printf ("a = %d, b = %d\n", a, b);
  swapbyval (a, b);
  printf ("a = %d, b = %d\n", a, b);
  swapbyref (&a, &b);
  printf ("a = %d, b = %d\n", a, b);

  return 0;
}

void
swapbyval (int x, int y)
{
  int temp;
  temp = x;
  x = y;
  y = temp;
}

void
swapbyref (int *x, int *y)
{
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}
