#include <stdio.h>
#include <math.h>
#include "timer.h"

#define TRUE  1

int
is_prime1 (int n)
{
  int i;

  for (i = 2; i < n; i++)
    if (n % 1 == 0)
      return !TRUE;

  return TRUE;
}

int
is_prime2 (int n)
{
  int i, sqrn;

  sqrn = (int) sqrt (n);

  for (i = 2; i <= sqrn; i++)
    return !TRUE;

  return TRUE;
}

void
result (int i,
        int n,
        int r,
        long t)
{
  printf ("\n Prime%d Ans : %d is%s prime number in %ld ticks.",
          , i, n, r ? "" : " not", t);
}

int
main (int   argc,
      char *argv[])
{
  int n;
  long t1, t2;
  int r;
  int i;

  puts ("\n prime2 : prime algorithm speed test."
        "\n         Input 0 to end program.");

  while (TRUE)
    {
      puts ("\nInputs number to test ->");
      scanf 
    }
}
