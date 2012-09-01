#include <stdio.h>

int
main (int argc, char *argv[])
{
  int i = 0;
  char a[] = "NET";
  char b[4];

  while (a[i] != '\0')
    {
      b[i] = a[2 - i];
      i++;
    }

  b[3] = '\0';
  printf ("%s는 거꾸로 읽으면 %s입니다.\n", a, b);

  return 0;
}
