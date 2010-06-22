#include <stdio.h>
#include <string.h>

int
main (int   argc,
      char *argv[])
{
  char first[100];
  char last[100];
  char full[200];

  printf ("Enter first name: ");
  fgets (first, sizeof (first), stdin);

  printf ("Enter last name: ");
  fgets (last, sizeof (last), stdin);

  strcpy (full, first);
  strcat (full, "");
  strcat (full, last);

  printf ("The name is %s\n", full);

  return 0;
}
