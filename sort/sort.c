#include <stdio.h>
#include <stdlib.h>

int
main (int    argc,
      char **argv)
{
  int i;
  int count;
  int *nums;

  if (argc < 2)
    {
      printf ("Usage: %s <num1> [<num2> <num3> ...]\n", argv[0]);
      exit (EXIT_FAILURE);
    }

  /**
   * Set nums
   */
  count = argc - 1;
  nums = (int *) malloc (count * sizeof (int));
  for (i = 0; i < count; ++i)
    {
      nums[i] = atoi (argv[i + 1]);
    }

  /**
   * Do real sort!!
   */

  return 0;
}
