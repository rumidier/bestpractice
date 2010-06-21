#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int term;
  int term_2;
  int term_3;

  term = 3 * 5;
  term_2 = 2 * term;
  term_3 = 3 * term;

  printf ("term : %d \n", term);
  printf ("term_2 : %d \n", term_2);
  printf ("term_3 : %d \n", term_3);

  return 0;
}

