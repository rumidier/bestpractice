#include <stdio.h>

int
main (int argc, char *argv[])
{
  int thing_var;
  int *thing_ptr;

  thing_var = 2;
  printf ("Thing %d\n", thing_var);

  thing_ptr = &thing_var;
  *thing_ptr = 3;

  printf ("Thing %d\n", thing_var);

  printf ("Thing %d\n", *thing_ptr);

  return 0;
}
