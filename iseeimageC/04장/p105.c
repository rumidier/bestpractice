#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>

int
main (int argc, char *argv[])
{
  char *buf;
  char a[4] = {20, 40, 30, 10};
  buf = (char *) malloc (200 * sizeof (char));

  if (!buf)
    return 1;
  memcpy (buf, a, sizeof (char) * 4);
  printf ("%d %d %d %d\n", buf [0], buf [1], buf [2], buf [3]);

  free (buf);

  return 0;
}
