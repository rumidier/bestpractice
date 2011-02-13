#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  char name[20];
  printf ("이름 : ");
  gets (name);

  printf ("%s \n", name);
  puts (name);

  return 0;
}
