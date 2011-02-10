#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  char starr[3][9] = {"Hello", "Business", "Per"};
    int i;

    for (i = 0; i < 3; i++)
      printf ("string %d : %s \n", i + 1, strarr[i]);

    return 0;
}
