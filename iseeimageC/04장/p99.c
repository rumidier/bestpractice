#include <stdio.h>
#include <string.h>

int
main (int argc, char *argv[])
{
  char s[] = "I love cat.";
  char c = 'd';
  char *p = NULL;

  printf ("문자열 %s안에 문자 %c", s, c);

  p = strchr (s, c);

  if (!p)
    printf ("는 없습니다.\n");
  else
    printf ("를 찾았습니다.\n");

  return 0;
}
