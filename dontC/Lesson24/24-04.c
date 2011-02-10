#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int arr[3] = {100, 200, 300};
  printf ("arr[0] [%d], *arr [%d] \n", arr[0], *arr);

  return 0;
}
