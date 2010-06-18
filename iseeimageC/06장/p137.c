#include <stdio.h>

int
main (int argc, char *argv[])
{
  FILE *fp;
  char s[256];
  int i = 1;
  fp = fopen ("abc.txt", "r");

  if (fp == NULL)
    return 1;

  while (1) {
    fgets (s, 255, fp);
    if (feof (fp))
      break;
    printf ("%04d: %s", i, s);
    i++;
  }
  fclose (fp);

  return 0;
}
