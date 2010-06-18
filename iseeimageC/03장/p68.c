#include <stdio.h>

int
main (int argc, char *argv[])
{
  char c = '#';

  printf ("%c은", c);

  if ('0' <= c && c <= '9')
    printf ("숫자입니다.\n");
  else if ('a' <= c && c <= 'z')
    printf ("소문자입니다.\n");
  else if ('A' <= c && c <= 'Z')
    printf ("대문자입니다.\n");
  else
    printf ("기호입니다.\n");

  return 0;
}
