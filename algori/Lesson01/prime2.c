/***********
 *  prime1.c : prime test program 1
 *
 *             programmed by chohanyoung
 */

#include <stdio.h>
#include <math.h>

#define TRUE    1

int is_prime (int n)
{
  int i, sqrn;

  sqrn = (int) sqrt (n);

  for (i = 2; i <= sqrn; i++)
    {
      if (n % i == 0)
        return !TRUE;
    }

  return TRUE;
}

int
main (int   argc,
      char *argv[])
{
  int n;

  puts ("\nprime1 : Test that input is prime or noe." \
        "\n          Input 0 to end program.");

  while (TRUE)
    {
      puts ("\nInput number to test ->");
      scanf ("%d", &n);

      if (n < 0)
        continue;
      if (n == 0)
        break;

      printf ("\nAns : %d is %s prime number" \
              , n, is_prime (n) ? "" : "not");
    }

  return 0;
}
