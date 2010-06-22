#include <stdio.h>

#define RECIPROCAL(number) (1.0 / (number))

int
main (int argc, char *argv[])
{
  float counter;

  for (counter = 1.0; counter < 10.0;
       counter += 1.0) {
    printf ("1/%f = %f\n",
            counter, RECIPROCAL (counter));
  }

  return 0;
}
