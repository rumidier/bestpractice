#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int term;

  term = 3 * 5;

  printf ("Twice %d is %d\n", term, 2 * term);
  printf ("Three times %d is %d\n", term, 3 * term);

  return 0;
}
