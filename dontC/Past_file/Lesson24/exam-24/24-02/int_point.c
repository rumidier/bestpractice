#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int a, b, c;
  int *iptrarr[3] = {&a, &b, &c};
  int **int_ptr;

  int_ptr = &iptrarr[0];

  a = 10;
  b = 20;
  c = 30;


  int  i = 0;
  while (i < 3)
    {
      printf ("%d \n", **(int_ptr + i));
      i++;
    }

  return 0;
}
