#include <stdio.h>
#include <string.h>

char buf[50];

int
main (int   argc,
      char *argv[])
{
  scanf ("%s", buf);
  printf ("[%s]", buf);
  if (!strcmp (buf, "hint"))
    {
      printf ("야호\n");
    }
  else
    {
      printf ("??\n");
    }

  return 0;
}
