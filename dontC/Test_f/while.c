#include <stdio.h>

int main(void)
{
  int num=0;
  int i=0;

  printf("배수의 갯수: ");
  scanf("%d", &num);

  printf ("%d\n", i);
  while(i++ < num)
    {
      printf ("[%d]\n", i);
      printf("%d \n", 3*i);

    }
  return 0;
}
