#include <stdio.h>
#include <string.h>

int
main (int   argc,
      char *argv[])
{
  char str[] = "It is possible to master C in a month or two.";
  char *printf_ptr;
  char c = 'i';

  char *fir_c;
  char *last_c;

  fir_c = strchr (str, c);
  last_c = strrchr (str, c);

  printf_ptr = ++fir_c;
  *(last_c) = '\0';
  printf ("%s\n", printf_ptr);

  return 0;
}
