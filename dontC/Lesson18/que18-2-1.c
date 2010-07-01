#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  char str[100];
  int len = 0;

  printf ("문자열 입력 : ");
  scanf ("%s", str);

  while (str[len] != '\0')
    len++;

  printf ("문자열의 길이는 %d \n", len);

  return 0;
}
