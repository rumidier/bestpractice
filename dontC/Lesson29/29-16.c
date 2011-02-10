#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int num1 = 24;
  float num2 = 7.15f;
  char str[] = "Hi!";

  char strbuf[50];

  printf ("%d %s %g \n", num1, str, num2);
  sprintf (strbuf, "%d %s %g \n", num1, str, num2);

  puts (strbuf);

  return 0;
}
