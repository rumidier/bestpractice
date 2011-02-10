#include <stdio.h>
void square_ref (int *num);

int
main (int   argc,
      char *argv[])
{
  int num;

  printf ("숫자 입력 : ");
  scanf ("%d", &num);

  square_ref (&num);
  printf ("num[%d]\n", num);

  return 0;
}

void
square_ref (int *num)
{

  int temp;
  temp = (*num) * (*num);
  *num = temp;

}
