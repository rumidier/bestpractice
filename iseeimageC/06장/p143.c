#include <stdio.h>

int
main (int argc, char *argv[])
{
  FILE *fp;
  char filename[] = "bintest.dat";
  int buf_w [10], buf_r [10];
  int i;

  for (i = 0; i < 10; i++)
    buf_w [i] = (i + 1) * 10;

  if (!(fp = fopen (filename, "wb")))
    return 1;

  if (fwrite (buf_w, sizeof (int), 10, fp) != 10) {
    fclose (fp);
    return 2;
  }
  fclose (fp);

  if (!(fp = fopen (filename, "rb")))
    return 3;
  if (fread (buf_r, sizeof (int), 10, fp) != 10) {
    fclose (fp);
    return 4;
  }
  fclose (fp);

  for (i = 0; i < 10; i++)
    printf ("%d ", buf_r [i]);
  printf ("\n");

  return 0;
}
