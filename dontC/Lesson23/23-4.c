#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int n1, n2, n3;
  int *arrptr[3] = {&n1, &n2, &n3};

  int i;
  for (i = 0; i < 3; i++)
    {
      printf ("숫자 입력 : ");
      scanf ("%d", arrptr[i]);
    }

  printf ("입력된 숫자의 총 합은 %d 입니다 \n",
          *arrptr[0] + *arrptr[1] + *arrptr[2]);

  return 0;
}
