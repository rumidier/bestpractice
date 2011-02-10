#include <stdio.h>

int main(void)
{
  char *str1 = "abc";
  char* p1=str1;

  p1+= 2;
  *p1 = 'd';
  p1 -= 2;
  puts (p1);
  return 0;
}
