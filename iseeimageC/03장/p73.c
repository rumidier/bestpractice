#include <stdio.h>

int
main (int argc, char *argv[])
{
  char a;

  do {
    a = getchar ();
    printf ("%c", a);
  } while (a != 'e');

  return 0;
}
