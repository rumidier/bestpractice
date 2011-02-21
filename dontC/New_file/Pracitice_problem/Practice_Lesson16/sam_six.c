#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int i;
  int count;

  count = 0;
  i = 1;

  while (i < 1000)
    {
      if (count == 11)
        {
          count = 0;
          printf ("\n");
        }

      if (!(i % 3))
        printf ("   P");
      else if (!((i % 10) % 3) ||
               (i / 10) == 3 || (i / 100) == 3 || (i / 1000) == 3 ||
               (i / 10) == 6 || (i / 100) == 6 || (i / 1000) == 6 ||
               (i / 10) == 9 || (i / 100) == 9 || (i / 1000) == 9)
        printf ("   P");
      else
        printf ("%4d", i);

      count++;
      i++;
    }

  return 0;
}
