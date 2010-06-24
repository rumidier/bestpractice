#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  char line[100];
  int value;

  printf ("Enter a value: ");

  fgets (line, sizeof (line), stdin);
  sscanf (line, "%d", &value);

  printf ("Twice %d is %d\n", value, value * 2);

  return 0;
}
