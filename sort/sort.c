#include <stdio.h>
#include <stdlib.h>

int
main (int    argc,
      char **argv)
{
  int i;

  if (argc < 2)
    {
      printf ("Usage: %s <num1> [<num2> <num3> ...]\n", argv[0]);
      exit (EXIT_FAILURE);
    }

  for (i = 1; i < argc; ++i)
    {
      printf ("%s ", argv[i]);
    }
  printf ("\n");

  return 0;
}
