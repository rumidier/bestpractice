#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  char line[100];
  int height;
  int width;
  int area;

  printf  ("Enter width height? ");

  fgets (line, sizeof (line), stdin);
  sscanf (line, "%d %d", &width, &height);

  area = (width * height) / 2;
  printf ("The area is %d\n", area);

  return 0;
}
