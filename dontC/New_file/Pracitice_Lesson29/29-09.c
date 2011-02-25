#include <stdio.h>
#include <string.h>

int
main (int   argc,
      char *argv[])
{
  char str1[20] = "Your name is ";
  char str2[20];

  printf ("이름을 입력하세요 : ");
  gets (str2);
  strcat (str1, str2);

  puts (str1);

  return 0;
}
