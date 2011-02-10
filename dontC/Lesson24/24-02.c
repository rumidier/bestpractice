#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int arr[] = {1, 2, 3, 4, 5};
  int *p = &arr[2];
  printf ("Now position : %d \n\n", *p);

  printf ("One position front : %d \n", *(p + 1));
  printf ("Two position front : %d \n\n", *(p + 2));

  printf ("One position back : %d \n", *(p - 1));
  printf ("Two position back : %d \n\n", *(p - 2));

  return 0;
}
