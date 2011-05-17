#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

int total, noew;
char filename[13];

int
main (int   argc,
      char *argv[])
{
  line *t;

  if (argc < 2)
    {
      printf ("\nUsage : TVIEW <filename.ext>");
      exit (EXIT_FAILURE);
    }
  strcpy (filename, argv[1]);
  init_line ();
  load_file ();
  key_proc ();

  printf ("\nProgram ends...");

  return 0;
}
