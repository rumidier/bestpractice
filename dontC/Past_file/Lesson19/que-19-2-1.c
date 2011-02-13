#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  char str1[30];
  char str2[30];
  char str3[30];
  char str4[30];

  scanf ("%s", str1);
  scanf ("%s", str2);
  scanf ("%s", str3);
  scanf ("%s", str4);

  printf ("\n");

  printf ("%s\n", str4);
  printf ("%s\n", str3);
  printf ("%s\n", str2);
  printf ("%s\n", str1);

  return 0;
}
