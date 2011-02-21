#include <stdio.h>

static int
power (int a, int x);

int
main (int   argc,
      char *argv[])
{
  int a;
  int x;
  int total;

  total = 0;

  for (a = 1; a <= 9; a++)
    {
      for (x = 0; x <= 9; x++)
        {
          total += power (a, x);
        }
    }

  printf ("총 total 값은 %d \n", total);

  return 0;
}

static int
power (int a, int x)
{
  int return_total;
  int i;

  return_total = 1;

  for (i = 1; i <= x; i++)
    return_total *= a;

  return return_total;

}
