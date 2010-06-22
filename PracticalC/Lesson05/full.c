#include <stdio.h>
#include <string.h>

int
main (int   argc,
      char *argv[])
{
  char first[100];
  char last[100];
  char full_name[200];

  strcpy (first, "Steve");
  strcpy (last, "Oualline");

  strcpy (full_name, first);

  strcat (full_name, "");
  strcat (full_name, last);

  printf ("The full name is %s\n", full_name);

  return 0;
}
