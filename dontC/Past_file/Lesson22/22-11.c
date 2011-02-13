#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  char vstr [30] = "String Variable";
  char * cstr = "string constant";

  vstr [0] = 'Q';
  printf ("%s\n", vstr);

  *cstr = 'Q';
  printf ("%s\n", cstr);

  return 0;
}
