#include <stdio.h>

#include "list.h"

int
main (int   argc,
      char *argv[])
{
  char buf[20] = "chohanyoung";

  list_init (first, NULL);

  list_ins_next (first, elmt_first, buf);
  printf ("first

  return 0;
}
