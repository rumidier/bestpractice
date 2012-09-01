#include <stdio.h>

int
main (int argc, char *argv[])
{
  int a, b = 1;
  for (a = 0; a < 5; a++)
    {
      if (a + b >= 3)
        break;
      printf ("%d + %d = %d\n", a, b, a + b);
    }

  return 0;
}
