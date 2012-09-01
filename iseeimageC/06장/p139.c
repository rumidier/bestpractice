#include <stdio.h>

int
main (int argc, char *argv[])
{
  FILE *fp;
  int a = 100, b = 5, c = 40;
  int x = 1, y = 10, z = 100;
  char delm[] = "----====----\n";

  fp = fopen ("mat.txt", "w");

  if (fp == NULL)
    return 1;
  fputs (delm, fp);
  fprintf (fp, "%4d%4d%4d\n%4d%4d%4d\n", a, b, c, x, y, z);
  fputs (delm, fp);
  fclose (fp);

  return 0;
}
