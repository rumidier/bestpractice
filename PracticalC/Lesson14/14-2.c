#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char *argv[])
{
  char line [100];
  int count, total;
  int scan_count;

  fgets (line, sizeof (line), stdin);
  scan_count = sscanf (line, "%d %d", &count, &total);

  switch (scan_count) {
  case EOF:
  case 0:
    printf ("Didn't find any number\n");
    break;
  case 1:
    printf ("Found 'count' (%d), but not 'total' \n", count);
    break;
  case 2:
    printf ("Found both 'count' (%d) and 'total' (%d)\n", count, total);
    break;
  default:
    printf ("This should not be possbile\n");
    break;
  }

  return 0;
}
