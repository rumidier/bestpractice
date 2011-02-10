#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int i;
  char str[30] = "Orange Media";
  char *ptr = str;

  i = 0;

  printf ("str:\n");
  while (str[i] != '\0')
    {
      printf ("%c", str[i]);
      i++;
    }
  printf ("\n");

  printf ("ptr:\n");
  while (*ptr != '\0')
    {
      printf ("%c", *ptr);
      ptr++;
    }
  printf ("\n");

  return 0;
}
