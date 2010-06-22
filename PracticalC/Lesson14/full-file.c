#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char *argv[])
{
  char name [100];
  FILE *in_file;

  printf ("Name? ");
  fgets (name, sizeof (name), stdin);

  in_file = fopen (name, "r");

  if (in_file == NULL) {
    fprintf (stderr, "Could not open file\n");
    exit 8;
  }

  printf ("File found\n");
  fclose (in_file);

  return 0;
}
