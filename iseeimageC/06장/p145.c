#include <stdio.h>

int
main (int argc, char *argv[])
{
  char s[30];
  fgets (s, 29, stdin);
  fputs (s, stdout);
  fputs ("error!\n", stdout);

  return 0;
}
