#include <stdio.h>

void showstring (char *argv[], int strnum);

int
main (int   argc,
      char *argv[])
{
  char *strptrary[3] = {
    "AAA",
    "BBB",
    "CCC"
  };

  char **strptr = strptrary;
  showstring (strptr, 3);

  return 0;
}

void
showstring (char **argv,
            int   strnum)
{
  int i;

  for (i = 0; i < strnum; i++)
    printf ("%s \n", argv[i]);
}
