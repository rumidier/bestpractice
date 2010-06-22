#include <stdio.h>

#define BIG_NUMBER 10 ** 10

int
main (int argc, char *argv[])
{
  int index;

  index = 0;

  while (index < BIG_NUMBER) {
    index = index * 8;
  }

  return 0;
}
