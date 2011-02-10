#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int i, k;

  for (i = 2; i < 9;)
    {
      for (k = 1; k <= i; k++)
        {
          printf ("%d X %d = %d\n", i, k, k * i);
        }
      printf ("--------------\n");
      i += 2;
    }

  return 0;
}
