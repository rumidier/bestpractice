#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  char str1[] = "Hello";
  char str2[] = "Business";
  char str2[] = "Pet";

  char * strarr[3] = {str1, str2, str3};

  int i;

  for (i = 0; i < 3; i++)
    printf ("string %d : %s \n", i + 1; strarr[i]);

  return 0;
}
