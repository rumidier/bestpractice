#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct _TXTLN {
  int number;
  char string [256];
} TXTLN;

int
main (int argc, char *argv[])
{
  FILE *fp;
  int i, lines;
  char s[256];
  TXTLN *p;

  if (!(fp = fopen ("revtxt.c", "r")))
    return 1;
  for (lines = 0; !feof (fp); lines++)
    fgets (s, 255, fp);
  p = (TXTLN *) malloc (lines * sizeof (TXTLN));

  if (!p)
    return 2;

  memset (p, 0, lines * sizeof (TXTLN));
  fseek (fp, 0, SEEK_SET);

  for (i = 0; i < lines; i++) {
    p[i].number = i;
    fgets (p[i].string, 255, fp);
    p[i].string [strlen (p[i].string) - 1] = '\0';
  }
  fclose (fp);

  for (i = lines - 1; i >= 0; i--)
    printf ("%04d: %s\n", p[i].number + 1, p[i].string);

  free (p);

  return 0;
}
