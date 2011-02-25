#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int num1 = 24;
  float num2 = 7.15f;
  char str[] = "Hi!";

  char str_buf[50];

  printf ("%d %s %g \n", num1, str, num2);
  sprintf (str_buf, "%d %s %g", num1, str, num2);

  puts (str_buf);

  return 0;
}
