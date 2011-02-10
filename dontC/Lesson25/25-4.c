#include <stdio.h>

typedef int INT;
typedef INT *PINT;

void swapref (PINT p1, PINT p2)
{
  INT tmp = *p1;
  *p1 = *p2;
  *p2 = tmp;
}

int
main (int   argc,
      char *argv[])
{
  INT val1 = 5;
  INT val2 = 7;
  printf ("swap 이전 [val1:%d, val2:%d] \n", val1, val2);

  swapref (&val1, &val2);
  printf ("swap 이후 [val1:%d, val2:%d] \n", val1, val2);

  return 0;
}
