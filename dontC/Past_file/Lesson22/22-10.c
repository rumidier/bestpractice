#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  char *str1 = "Computer Systems";
  char *str2 = "Operating Systems";
  char *fmtstr = "%s\n%s\n";

  printf ("%s\n", str1);
  printf ("%s\n", str2);
  printf (fmtstr, str1, str2);

  return 0;
}
