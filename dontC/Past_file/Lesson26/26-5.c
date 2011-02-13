#include <stdio.h>
#include <string.h>

int
main (int   argc,
      char *argv[])
{
  int i;
  int src1[5] = {1, 2, 3, 4, 5};
  int dest1[5];

  double src2[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
  double dest2[5];

  memmove ((void *) dest1, (void *)src1, sizeof (src1));
  memmove ((void *) dest2, (void *)src2, sizeof (src2));

  for (i = 0; i < 5; i++)
    printf ("%2d %8.2f \n", dest1[i], dest2[i]);

  return 0;
}
