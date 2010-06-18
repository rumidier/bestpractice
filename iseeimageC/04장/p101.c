#include <stdio.h>

int
main (int argc, char *argv[])
{
  int a[4] = {10, 20, 30, 40};

  printf ("배열 a[3]의 값은 %d\n", *(a + 3));
  printf ("배열 a[0]의 값에 3을 더하면 %d\n", *a + 3);

  return 0;
}
