#include <stdio.h>
#include <string.h>

int
main (int   argc,
      char *argv[])
{
  char name[30];

  strcpy (name, "Sam");

  printf ("The name is %s\n", name);

  return 0;
}
