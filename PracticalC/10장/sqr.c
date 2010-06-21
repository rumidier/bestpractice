#include <stdio.h>

#define SQR(x) (x * x)

int
main (int argc, char *argv[])
{
  int counter;

    for (counter = 0; counter < 5; ++counter) {
      printf ("x %d, x squared %d\n",
              counter + 1, SQR (counter + 1));
    }

  return 0;
}

