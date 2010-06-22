#include <stdio.h>
#define SIZE 20

int
main (int argc, char *argv[])
{
  int data [SIZE];
  int twice [SIZE];

  int index;

  for (index = 0; index < SIZE; ++index) {
    data [index] = index;
    twice [index] = index * 2;
  }

  return 0;
}
