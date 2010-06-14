#include <stdio.h>

int
main (int    argc,
      char **argv)
{
  if (argc < 2)
    {
      printf ("Usage: %s <num1> [<num2> <num3> ...]\n", argv[0]);
    }

  return 0;
}
