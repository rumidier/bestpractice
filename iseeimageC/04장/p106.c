#include <stdio.h>

int
main (int argc, char *argv[])
{
  char s[] = "I love cat and dog.";
  char c = 'a';
  char *p = s;
  int n = 0;

  printf ("\"%s\" 안에서  \'%c\'를 찾습니다.\n", s, c);
  while (*p != '\0') {
    if (*p == c) {
      printf ("%d번째에서 발견되었습니다.\n", p - s + 1);
      n++;
    }
    p++;
  }

  if (n == 0)
    printf ("한 개도 발견되지 않았습니다.\n");
  else
    printf ("모두 %d개 발견되었습니다.\n", n);

  return 0;
}
